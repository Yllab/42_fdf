/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:10:50 by hbally            #+#    #+#             */
/*   Updated: 2018/12/03 18:52:42 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void		draw_vertex(t_img *img, t_map *map, int z, int x)
{
	if (z != 0)
		draw_line(img, map->points[z][x], map->points[z - 1][x]);
	if (z != map->height - 1)
		draw_line(img, map->points[z][x], map->points[z + 1][x]);
	if (x != 0)
		draw_line(img, map->points[z][x], map->points[z][x - 1]);
	if (x != map->width - 1)
		draw_line(img, map->points[z][x], map->points[z][x + 1]);
}	

void			render(t_hub *hub)
{
	int 		x;
	int 		z;

	x = 0;
	z = 0;	
	while (z < hub->map->height)
	{
		x = 0;
		while (x < hub->map->width)
		{
			draw_vertex(hub->img, hub->map, z, x);
			mlx_put_image_to_window(hub->win->mlx_id,
									hub->win->self_id,
									hub->img->self_id, 0, 0);
			x++;
		}
		z++;
	}
}
