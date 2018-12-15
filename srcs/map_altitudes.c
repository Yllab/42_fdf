/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_altitudes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 22:32:22 by hbally            #+#    #+#             */
/*   Updated: 2018/12/15 22:32:23 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void			map_find_range(t_map *map)
{
	int				z;
	int				x;

	z = 0;
	x = 0;
	map->min_y = 0.0;
	map->max_y = 0.0;
	while (z < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((double)map->points[z][x].y > map->max_y)
				map->max_y = (double)map->points[z][x].y;
			else if ((double)map->points[z][x].y < map->min_y)
				map->min_y = (double)map->points[z][x].y;
			x++;
		}
		z++;
	}
}

void				map_assign_alti(t_map *map)
{
	int				z;
	int				x;

	z = 0;
	x = 0;
	map_find_range(map);
	while (z < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[z][x].alti = (double)map->points[z][x].y;
			x++;
		}
		z++;
	}
}
