/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/03 17:15:10 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"
#include "mlx.h"

//DEBUG

#include <stdio.h>
#include <stdlib.h>

void	debug_translate_point(t_vector *point, int x, int y)
{
	point->x += x;
	point->y += y;
}

void	debug_scale_point(t_vector *point)
{
	point->x *= 10;
	point->y *= 10;
}

void	debug_print_points(t_hub *hub)
{
	t_map *map;
	t_img *img;

	map = hub->map;
	img = hub->img;

	int x = 0;
	int z = 0;	
	while (z < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			debug_scale_point(&(map->points[z][x]));
			debug_translate_point(&(map->points[z][x]),
									hub->win->w / 2,
									hub->win->h / 2);			
			printf("x = %d, y = %d\n", map->points[z][x].x, map->points[z][x].y);
			x++;
		}
		z++;
	}

	x = 0;
	z = 0;	
	while (z < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (z == 1)
				img->color = 0xFFAAFF;
			if (z != 0)
				draw_line(img, map->points[z][x], map->points[z - 1][x]);
			if (z != map->height - 1)
				draw_line(img, map->points[z][x], map->points[z + 1][x]);
			if (x != 0)
				draw_line(img, map->points[z][x], map->points[z][x - 1]);
			if (x != map->width - 1)
				draw_line(img, map->points[z][x], map->points[z][x + 1]);
			mlx_put_image_to_window(hub->win->mlx_id,
									hub->win->self_id,
									img->self_id, 0, 0);
			x++;
		}
		z++;
	}
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
//			img->color = arc4random_uniform(0xFF * 0xFF * 0xFF);
			img->color = 0xFFFFFF;
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
//	mlx_key_hook(win.self_id, &key_hook, &hub);
//	mlx_new_image (mlx_id, win->width, win->height);

	debug_print_points(&hub);
	mlx_loop(win.mlx_id);	
	}
}
