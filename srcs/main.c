/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/11/30 19:36:30 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"
#include "mlx.h"

//DEBUG

#include <stdio.h>

void	debug_print_points(t_map map)
{
	int x = 0;
	int z = 0;	
	while (z < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			printf("x = %f ", map->points[z][x].x);
			printf("y = %f ", map->points[z][x].y);
			printf("z = %f ", map->points[z][x].z);
			printf("\n");
			x++;
		}
		z++;
	}
}

//-------------------------------------

int			main(int argc, char **argv)
{
	int		fd;
	void	*mlx_id;
	void	*win_id;
	t_map	*map;

//	START	
	if (argc != 2)
		return (0);	

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	
	mlx_id = mlx_init();
	if (!mlx_id)
		return (0);

//	DRAW WINDOW
	
	win_id = mlx_new_window(mlx_id, 800, 600, "fdf");
	if (!win_id)
		return (0);
	mlx_loop(mlx_id);

//	INPUT
	map = build_map(fd);
	if (!map)
		return (0);		

	return (0);
}
