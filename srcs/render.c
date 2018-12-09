/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:44:16 by hbally            #+#    #+#             */
/*   Updated: 2018/12/09 22:29:48 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "matrix.h"
#include "mlx.h"

void				pt_to_screen(t_vector *point, t_camera *cam, t_img *img)
{
	vect_mat_mul(point, cam->t.matrix);
	point->x /= -point->z;
	point->y /= -point->z;
	point->x = (point->x + cam->canvas_w / 2) / cam->canvas_w;
	point->y = (point->y + cam->canvas_h / 2) / cam->canvas_h;
	point->x = floor((double)(point->x * img->win_width));
	point->y = floor((double)((1 - point->y) * img->win_height));
}

void				pt_draw(t_vector point, t_hub *hub, int z, int x)
{
	t_vector		connect;

	if (x < hub->map->width - 1)
	{
		connect = hub->map->points[z][x + 1];
		pt_to_screen(&connect, &(hub->camera), &(hub->img));
		draw_line(&(hub->img), point, connect);
	}
	if (z > 0)
	{
		connect = hub->map->points[z - 1][x];
		pt_to_screen(&connect, &(hub->camera), &(hub->img));
		draw_line(&(hub->img), point, connect);
	}
}

void				parse_points(t_hub *hub)
{
	int 			x;
	int				z;
	t_vector		point;

	z = 0;
	x = 0;
	while (z < hub->map->height)
	{
		x = 0;
		while (x < hub->map->width)
		{
			point = hub->map->points[z][x];
//			if (!((double)fabs(point.x) > hub->camera.canvas_w / 2 ||
//				(double)fabs(point.y) > hub->camera.canvas_h / 2))
//			{
				pt_to_screen(&point, &(hub->camera), &(hub->img));
				pt_draw(point, hub, z, x);
//			}
			x++;
		}
		z++;
	}
}

void				render(t_hub *hub)
{
	ft_bzero(hub->img.data, hub->img.line_size * hub->img.win_height);
	img_set_background(&(hub->img), hub->img.background_color);
	hub->camera.canvas_w = 2;
	hub->camera.canvas_h = 2;
	transform_build(&(hub->camera.t));
	matrix_inv(hub->camera.t.matrix);
	parse_points(hub);
	mlx_put_image_to_window(hub->win.mlx_id, hub->win.self_id,
							hub->img.self_id, 0, 0);
}
