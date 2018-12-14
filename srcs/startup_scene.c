/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 10:00:58 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 18:16:19 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "matrix.h"
#include "colors.h"

void			reset_canvas(t_camera *camera, t_map *map)
{
	if (camera->proj == 1)
		camera->canvas = 2;
	else
		camera->canvas = map->scale;
}

void			transform_map(t_map *map,
								float delta_elevation,
								float delta_scale)
{
	matrix_inv(map->t.matrix);
	transform_apply(&(map->t), map->points, map->width, map->height);
	map->t.scale_x += delta_scale;
	map->t.scale_z += delta_scale;
	map->t.scale_y += delta_elevation;
	if (map->t.scale_x < 0.1)
	{
		map->t.scale_x = 0.1;
		map->t.scale_z = 0.1;
	}
	if (map->t.scale_x > 10)
	{
		map->t.scale_x = 10;
		map->t.scale_z = 10;
	}
	if (map->t.scale_y == 0)
		map->t.scale_y += delta_elevation;
	if (map->t.scale_y < -10 || map->t.scale_y > 10)
		map->t.scale_y = 1;
	transform_build(&(map->t));
	transform_apply(&(map->t), map->points, map->width, map->height);
}

void			startup_camera(t_camera *camera, t_map *map)
{
	ft_bzero(&(camera->t), sizeof(t_transform));
	reset_canvas(camera, map);
	camera->speed = map->width + map->height;
	camera->t.translate_z = (float)map->height * 2;
	camera->t.translate_y = ((double)map->height / 2) / tan(M_PI_4);
	camera->t.rotate_x = -M_PI_4;
}

void			startup_map(t_map *map)
{
	map->t.scale_x = 0;
	map->t.scale_z = 0;
	map->t.scale_y = 0;
	transform_map(map, 1, 1);
}

void			startup_scene(t_hub *hub)
{
	ft_bzero(&(hub->camera), sizeof(t_camera));
	hub->camera.proj = 1;
	hub->camera.fullrender = 1;
	hub->camera.autorotate = 1;
	theme_cafe(&(hub->theme));
	hub->img.background_color = PASTEL_WHITE;
	hub->img.night_mode = 1;
	hub->img.show_ui = 0;
	map_assign_alti(hub->map);
	hub->map->scale = hub->map->width + hub->map->height;
	hub->map->t.translate_x = (float)(-hub->map->width / 2);
	hub->map->t.translate_z = (float)(-hub->map->height / 2);
	startup_map(hub->map);
	startup_camera(&(hub->camera), hub->map);
}
