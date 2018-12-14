/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 10:00:58 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 12:08:21 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "matrix.h"
#include "colors.h"

void			reset_canvas(t_camera *camera, t_map *map)
{
	if (camera->projection == 1)
	{
		camera->canvas_w = 2;
		camera->canvas_h = 2;
	}
	else
	{
		camera->canvas_w = 1000;
		camera->canvas_h = 1000;
	}
	map = NULL;
}

void			startup_camera(t_camera *camera, t_map *map)
{
	ft_bzero(&(camera->t), sizeof(t_transform));
	reset_canvas(camera, map);
	if (camera->projection == 1)
		camera->speed = 2 * map->width;
	else
		camera->speed = 8 * map->width;
	camera->t.translate_z = (float)map->height + (float)(map->height / 2);
	camera->t.translate_y = (double)map->height / tan(M_PI_4);
	camera->t.rotate_x = -M_PI_4;
}

void			transform_map(t_map *map,
								float delta_elevation,
								float delta_scale)
{

	printf("TRANSFORM MAP\n");
	matrix_inv(map->t.matrix);
	transform_apply(&(map->t), map->points, map->width, map->height);
	map->t.scale_x += delta_scale;
	map->t.scale_y += delta_elevation;
	map->t.scale_z += delta_scale;
	if (map->t.scale_x < 0.1)
		map->t.scale_x = 0.1;
	if (map->t.scale_z < 0.1)
		map->t.scale_z = 0.1;
	if (map->t.scale_y == 0)
		map->t.scale_y += delta_elevation;


	//debug
//	matrix_print(map->t.matrix);
	printf("ROTATE VALUES %f %f\n", map->t.scale_x, map->t.scale_z);
//
//
	transform_build(&(map->t));
	transform_apply(&(map->t), map->points, map->width, map->height);
	printf("END TRANSFORM MAP\n");
}

void			startup_map(t_map *map)
{
	map->t.translate_x = (float)(-map->width / 2);
	map->t.translate_z = (float)(-map->height / 2);
	transform_map(map, 1, 1);
}

void			startup_scene(t_hub *hub)
{
	ft_bzero(&(hub->camera), sizeof(t_camera));

	hub->camera.projection = 1;
	hub->camera.fullrender = 1;
	hub->camera.autorotate = 1;
	map_assign_alti(hub->map, 1);

	hub->img.background_color = PASTEL_WHITE;
	hub->img.night_mode = 1;
	hub->img.show_ui = 0;

	startup_map(hub->map);
	startup_camera(&(hub->camera), hub->map);
}
