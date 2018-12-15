/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:30:50 by hbally            #+#    #+#             */
/*   Updated: 2018/12/15 23:31:47 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"
#include "mlx.h"

void			fdf_close(char *msg)
{
	if (msg)
	{
		ft_putstr("Error : ");
		ft_putendl(msg);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void			free_points(t_vector **points, t_map *map)
{
	int			i;

	i = 0;
	while (i < map->height)
	{
		if (points[i])
		{
			free(points[i]);
			points[i] = NULL;
		}
		i++;
	}
	free(points);
	points = NULL;
}

void			fdf_exit(t_hub *hub, char *msg)
{
	if (hub->map)
	{
		if (hub->map->points)
			free_points(hub->map->points, hub->map);
		free(hub->map);
	}
	mlx_destroy_image(hub->win.mlx_id, hub->img.self_id);
	fdf_close(msg);
}
