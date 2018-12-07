/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 19:45:00 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "matrix.h"

void					transform_map(t_map *map,
										float delta_height, float delta_scale)
{
	//transform.matrix needs to be set to identity at the start
	matrix_inv(map->transform.matrix);
	transform_apply(&(map->transform), map->points, map->width, map->height);
	map->transform.translate_y += delta_height;
	map->transform.scale_x += delta_scale;
	map->transform.scale_y += delta_scale;
	transform_build(&(map->transform));
	transform_apply(&(map->transform), map->points, map->width, map->height);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_hub		hub;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			hub.map = build_map(fd);
			//DEBUG
			//END DEBUG
			if (hub.map)
				start_window(&hub);
		}
	}
	return (0);
}
