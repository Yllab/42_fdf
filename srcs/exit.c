/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:30:50 by hbally            #+#    #+#             */
/*   Updated: 2018/12/15 21:36:09 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

void			fdf_close(char *msg)
{
	if (msg)
	{
		ft_putstr("Error : ");
		ft_putendl(msg);
		exit(EXIT_FAILURE);
	}
	while(1){}
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
	if (hub->win.mlx_id)
		free(hub->win.mlx_id);
	if (hub->win.self_id)
		free(hub->win.self_id);
	if (hub->img.self_id)
		free(hub->img.self_id);
	if (hub->img.data)
		free(hub->img.data);
	fdf_close(msg);
}
