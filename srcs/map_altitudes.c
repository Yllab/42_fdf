/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_altitudes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:38:10 by hbally            #+#    #+#             */
/*   Updated: 2018/12/10 16:50:48 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static int			map_find_range(t_map *map)
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

void				map_assign_altitude(t_map *map, int granularity)
{
	int				z;
	int				x;
	int				range;
	int				level;
	int				level_size;

	range = map_find_range(map);
	if (granularity <= 0)
		level_size = 1;
	else
		level_size = (int)ceil((double)range / (double)granularity);
	if (level_size < 1)
		level_size = 1;
	z = 0;
	x = 0;
	while (z < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			level = 1;
			while ((map->min_y + level * level_size) < map->points[z][x].y)
				level++;
			map->points[z][x].level = level;
			map->points[z][x].altitude = map->points[z][x].y;
			x++;
		}
		z++;
	}
}
