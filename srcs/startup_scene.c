/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 10:00:58 by hbally            #+#    #+#             */
/*   Updated: 2018/12/09 22:21:48 by hbally           ###   ########.fr       */
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
	camera->t.translate_x = -(((float)map->width / 2) * map->t.scale_x);
	camera->t.translate_y = (float)map->width / 4;
	camera->t.translate_z = (float)map->height + ((float)map->height / 2) * map->t.scale_z;
}

void			startup_map(t_map *map,
							float delta_elevation, float delta_scale)
{
	matrix_inv(map->t.matrix);
	transform_apply(&(map->t), map->points, map->width, map->height);
	map->t.scale_x += delta_scale;
	map->t.scale_y += delta_elevation;
	map->t.scale_z += delta_scale;
	transform_build(&(map->t));
	transform_apply(&(map->t), map->points, map->width, map->height);
}

void			startup_scene(t_hub *hub)
{
	ft_bzero(&(hub->camera), sizeof(t_camera));
//	map_assign_altitude(hub->map, 5);
	hub->img.background_color = DARK_GRAY;
	hub->img.map_color = LIGHT_BLUE;
	startup_map(hub->map, 0.5, 1);
	startup_camera(&(hub->camera), hub->map);
}
