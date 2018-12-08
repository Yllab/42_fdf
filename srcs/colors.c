/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:36:31 by hbally            #+#    #+#             */
/*   Updated: 2018/12/08 21:27:08 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "fdf.h"
#include <stdlib.h>

void				find_range(t_map *map, int *lowest, int *highest, int *average)
{
	static int		values[1000];
	int				i;
	int				j;
	int				size;

	i = 0;
	j = 0;
	*highest = 0;
	*lowest = 0xFFFFFFFF;
	size = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->points[i][j].y > *highest)
				*highest = map->points[i][j].y;
			if (map->points[i][j].y < *lowest)
				*lowest = map->points[i][j].y;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			values[map->points[i][j].y] += 1;
			size++;
			j++;
		}
		i++;
	}
	average = 0;
	i = 0;
	while (i < size)
	{
		if 
	}

}

void				color_points(t_map *map)
{
	int				i;
	int				j;
	int				highest;
	int				lowest;
	int				average;
	int				gray;

	i = 0;
	j = 0;
	find_range(map, &lowest, &highest, &average);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			gray = ((map->points[i][j].y - lowest) * 255 / (highest - lowest));
			if (map->points[i][j].y == lowest)
				map->points[i][j].color = 0x141414;
			map->points[i][j].color = gray | (gray << 8) | (gray << 16);
			j++;
		}
		i++;
	}
}
