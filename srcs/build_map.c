/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:43:40 by hbally            #+#    #+#             */
/*   Updated: 2018/12/15 20:53:01 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include "libft.h"
#include "matrix.h"

static void		tabfree(char **tab, int i)
{
	while (i--)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}

static void		fill_row(t_map *map, t_hub *hub, char *line, int z)
{
	int			i;
	char		**split;

	map->points[z] = (t_vector*)ft_memalloc(sizeof(t_vector) * map->width);
	split = ft_strsplit(line, ' ');
	if (!map->points[z] || !split)
		fdf_exit(hub, "Allocation failure.");
	i = 0;
	while (split[i])
	{
		map->points[z][i].x = (float)i;
		map->points[z][i].y = (float)ft_atoi(split[i]);
		map->points[z][i].z = (float)z;
		map->points[z][i].w = 1;
		i++;
	}
	tabfree(split, i - 1);
	if (i != map->width)
		fdf_exit(hub, "Map is not a rectangle.");
}

static void		get_input(int fd, t_map *map, t_hub *hub)
{
	int			i;
	char		*line;

	map->points = (t_vector**)ft_memalloc(sizeof(t_vector*) * map->height);
	if (!map->points)
		fdf_exit(hub, "Allocation failure.");
	i = 0;
	while (i < map->height)
	{
		if (get_next_line(fd, &line) < 0)
			fdf_exit(hub, "Read error / Invalid Map.");
		fill_row(map, hub, line, i);
		ft_strdel(&line);
		i++;
	}
}

static void		get_map_size(int fd, t_map *map, t_hub *hub)
{
	int			i;
	int			ret;
	char		*line;
	char		**get_map_width;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!map->width)
		{
			if (!(get_map_width = ft_strsplit(line, ' ')) || !(*get_map_width))
				fdf_exit(hub, "Read error / Invalid Map.");
			i = 0;
			while (get_map_width[i++])
				map->width++;
			tabfree(get_map_width, i--);
		}
		map->height++;
		ft_strdel(&line);
	}
	if (ret < 0 || !map->height || (map->width == 1 && map->height == 1))
		fdf_exit(hub, "Read error / Invalid Map.");
}

void			build_map(int fd1, char *filename, t_hub *hub)
{
	int			fd2;

	hub->map = (t_map*)ft_memalloc(sizeof(t_map));
	if (!hub->map)
		fdf_exit(hub, "Allocation failure.");
	get_map_size(fd1, hub->map, hub);
	if ((fd2 = open(filename, O_RDONLY)) == -1)
		fdf_exit(hub, "Read error / Invalid Map.");
	get_input(fd2, hub->map, hub);
	matrix_init(hub->map->t.matrix);
}
