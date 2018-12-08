/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:52:46 by hbally            #+#    #+#             */
/*   Updated: 2018/12/08 09:46:06 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"
#include "matrix.h"

static void		free_row(void *row, size_t row_size)
{
	ft_memdel(&row);
	row_size = 0;
}

static void		fill_map(t_map *map, t_list *map_raw)
{
	int			x;
	int			y;
	int			z;

	x = 0;
	y = 0;
	z = map->height - 1;
	while (map_raw)
	{
		map->points[z] = (t_vector*)malloc(sizeof(t_vector) * map->width);
		if (!(map->points[z]))
			exit(1);
		x = 0;
		while (x < map->width)
		{
			y = *(int*)(map_raw->content + x * sizeof(int));
			map->points[z][x].x = (float)x;
			map->points[z][x].y = (float)y;
			map->points[z][x].z = (float)z;
			map->points[z][x].w = 1;
			x++;
		}
		map_raw = map_raw->next;
		z--;
	}
}

t_map			*build_map(int fd)
{
	t_map		*map;
	t_list		*map_raw;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	if (map && (map_raw = get_input(fd, map)))
	{
		if (map->height)
		{
			map->points = (t_vector**)malloc(sizeof(t_vector*) * map->height);
			if (map->points)
			{
				fill_map(map, map_raw);
				matrix_init(map->transform.matrix, 1);
				ft_lstdel(&map_raw, &free_row);
				return (map);
			}
			ft_lstdel(&map_raw, &free_row);
		}
		free(map);
	}
	return (NULL);
}
