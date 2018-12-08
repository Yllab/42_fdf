/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 10:00:58 by hbally            #+#    #+#             */
/*   Updated: 2018/12/08 11:22:08 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "matrix.h"
#include <math.h>

void			startup_camera(t_camera *camera, t_map *map)
{
	ft_bzero(camera, sizeof(t_camera));
	camera->t.translate_z = map->height;
	camera->t.rotate_y = -atan((double)map->width / (double)map->height);
	camera->t.rotate_x = -(M_PI / 3);
	camera->t.translate_x = -((map->width / 2) * map->t.scale_x);
	camera->t.translate_z = (map->height / 2) * map->t.scale_z;
	transform_build(&(camera->t));
}

void			map_transform(t_map *map,
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
	map_transform(hub->map, 0, 0);
	startup_camera(&(hub->camera), hub->map);
}
