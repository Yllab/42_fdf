/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/03 15:28:22 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"
#include "mlx.h"

//DEBUG

#include <stdio.h>
#include <stdlib.h>

void	debug_print_points(t_map *map)
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

int			key_hook(int keycode, void *param)
{
	t_vector	p1;
	t_vector	p2;

	if (keycode == 125)
	{
		p1.x = arc4random_uniform(1500);
		p1.y = arc4random_uniform(1000);
		p2.x = arc4random_uniform(1500);
		p2.y = arc4random_uniform(1000);
		draw_line_pilot(p1, p2, ((t_hub*)param)->img);
		mlx_put_image_to_window(((t_hub*)param)->win->mlx_id,
								((t_hub*)param)->win->self_id,
								((t_hub*)param)->img->self_id, 0, 0);
	}
	return (0);
}

void		create_window(t_win *win, t_img *img)
{
	win->mlx_id = mlx_init();
	if (win->mlx_id)
	{
		win->w = 1500;
		win->h = 1000;
		win->self_id = mlx_new_window(win->mlx_id, win->w, win->h, "fdf");
		if (win->self_id)
		{
			img->self_id = mlx_new_image(win->mlx_id, win->w, win->h);
			img->data = mlx_get_data_addr(img->self_id,
						&(img->bpp), &(img->line_size), &(img->endian));
		}
	}
}

//-------------------------------------

int			main(int argc, char **argv)
{
	int			fd;
	t_hub		hub;
	t_win		win;
	t_img		img;
	t_map		*map;

	if (argc != 2)
		return (0);	

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	
	map = build_map(fd);
	if (!map)
		return (0);		

	hub.win = &win;
	hub.img = &img;
	hub.map = map;
	
	create_window(&win, &img);
	if (win.self_id)
	{
	//debug
	mlx_key_hook(win.self_id, &key_hook, &hub);
//	mlx_new_image (mlx_id, win->width, win->height);

	mlx_loop(win.mlx_id);	
	}
}
