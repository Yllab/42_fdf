/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:36:31 by hbally            #+#    #+#             */
/*   Updated: 2018/12/09 14:32:43 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "fdf.h"
#include <stdlib.h>
#include <math.h>

int					map_find_range(t_map *map)
{
	int				z;
	int				x;

	z = 0;
	x = 0;
	map->min_y = 0;
	map->max_y = 0;
	while (z < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->points[z][x].y > map->max_y)
				map->max_y = map->points[z][x].y;
			else if (map->points[z][x].y < map->min_y)
				map->min_y = map->points[z][x].y;
			x++;
		}
		z++;
	}
	return (map->max_y - map->min_y);
}

int					map_find_point_level(t_map *map, int level_size, int y)
{
	int				i;

	i = 1;
	while (map->min_y + i * level_size < y)
		i++;
}

void				map_find_altitude(t_map *map, int granularity)
{
	int				z;
	int				x;
	int				range;
	int				level_size;

	range = map_find_range(map);
	level_size = (int)ceil((double)range / (double)granularity);

	z = 0;
	x = 0;
	while (z < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[z][x].color = map->points[z][x].y
			x++;
		}
		z++;
	}
}
