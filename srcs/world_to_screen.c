/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_to_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:03:37 by hbally            #+#    #+#             */
/*   Updated: 2018/12/11 19:56:25 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void			pt_to_canvas(t_vector *point, t_camera *cam)
{
	ft_putstr("pt to canvas\n");
	vect_mat_mul(point, cam->t.matrix);
	if (point->z <= -0.1)
	{
		point->z = 1;
		if (cam->projection == 1)
		{
			point->x /= -point->z;
			point->y /= -point->z;
		}
	}
	else
		point->z = 0;
	ft_putstr("exit pt to canvas\n");
}

static void			pt_to_screen(t_vector *point, t_camera *cam, t_img *img)
{
	ft_putstr("pt to screen\n");
	point->x = (point->x + cam->canvas_w / 2) / cam->canvas_w;
	point->y = (point->y + cam->canvas_h / 2) / cam->canvas_h;
	point->x = floor((double)(point->x * img->win_width));
	point->y = floor((double)((1 - point->y) * img->win_height));
}

static void			pt_draw(t_vector *point, t_hub *hub, int z, int x)
{
	t_vector		connected_point;

	ft_putstr("pt draw\n");
	if (x < hub->map->width - 1)
	{
		connected_point = hub->map->points[z][x + 1];
		pt_to_canvas(&connected_point, &(hub->camera));
			ft_putstr("pika4\n");
		if ((point->z && connected_point.z))
		{
			pt_to_screen(&connected_point, &(hub->camera), &(hub->img));
			draw_line(hub, *point, connected_point);
		}
	}
	if (z > 0)
	{
		connected_point = hub->map->points[z][x + 1];
		connected_point = hub->map->points[z - 1][x];
		pt_to_canvas(&connected_point, &(hub->camera));
			ft_putstr("pika5\n");
		if ((point->z && connected_point.z))
		{
			ft_putstr("pika6\n");
			pt_to_screen(&connected_point, &(hub->camera), &(hub->img));
			ft_putstr("pika7\n");
			draw_line(hub, *point, connected_point);
		}
	}
}

void				world_to_screen(t_hub *hub)
{
	int 			x;
	int				z;
	t_vector		point;

	ft_putstr("world to screen\n");
	z = 0;
	x = 0;
	while (z < hub->map->height)
	{
		x = 0;
		while (x < hub->map->width)
		{
			point = hub->map->points[z][x];
			pt_to_canvas(&point, &(hub->camera));
			ft_putstr("pika1\n");
			if (hub->camera.fullrender ||
					!((double)fabs(point.x) > hub->camera.canvas_w / 2 ||
						(double)fabs(point.y) > hub->camera.canvas_h / 2))
			{
			ft_putstr("pika2\n");
				pt_to_screen(&point, &(hub->camera), &(hub->img));
			ft_putstr("pika3\n");
				pt_draw(&point, hub, z, x);
			}
			x++;
		}
		z++;
	}
}
