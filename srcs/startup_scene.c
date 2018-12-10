/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 10:00:58 by hbally            #+#    #+#             */
/*   Updated: 2018/12/10 18:46:21 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "matrix.h"
#include "colors.h"

void			startup_camera(t_camera *camera, t_map *map)
{
	ft_bzero(&(camera->t), sizeof(t_transform));
	camera->t.rotate_x = -M_PI / 3;
	camera->t.rotate_y = -atan((double)map->width / (double)map->height);
	camera->t.translate_x = -(float)map->width;
	camera->t.translate_y = (float)map->width;
	camera->t.translate_z = (float)map->height;
}

void			startup_map(t_map *map,
							float delta_elevation, float delta_scale)
{
	matrix_inv(map->t.matrix);
	transform_apply(&(map->t), map->points, map->width, map->height);
	map->t.scale_x += delta_scale;
	map->t.scale_y += delta_elevation;
	map->t.scale_z += delta_scale;
	if (map->t.scale_x < 0.1)
		map->t.scale_x = 0.1;
	if (map->t.scale_y == 0)
		map->t.scale_y += delta_elevation;
	if (map->t.scale_z < 0.1)
		map->t.scale_z = 0.1;
	transform_build(&(map->t));
	transform_apply(&(map->t), map->points, map->width, map->height);
}

void			startup_scene(t_hub *hub)
{
	ft_bzero(&(hub->camera), sizeof(t_camera));
	hub->camera.fullrender = 1;
	hub->camera.start_speed = 4 * hub->map->width;
	hub->camera.speed = hub->camera.start_speed;
	hub->camera.canvas_w = 2;
	hub->camera.canvas_h = 2;
	map_assign_altitude(hub->map, 400);
	hub->img.background_color = PASTEL_WHITE;
	hub->img.night_mode = 0;
	hub->img.show_ui = 0;
	startup_map(hub->map, 0.5, 1);
	startup_camera(&(hub->camera), hub->map);
}
