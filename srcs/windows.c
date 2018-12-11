/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:17:23 by hbally            #+#    #+#             */
/*   Updated: 2018/12/11 20:35:48 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "keys.h"

static void		find_window_size(t_hub *hub)
{
	hub->img.win_width = 1920;
	hub->img.win_height = 1080;
}

static void		create_window(t_hub *hub,
		t_win *win,
		t_img *img)
{
	win->mlx_id = mlx_init();
	if (win->mlx_id)
	{
		find_window_size(hub);
		win->self_id = mlx_new_window(win->mlx_id,
				img->win_width,
				img->win_height,
				"fdf");
		if (win->self_id)
		{
			img->self_id = mlx_new_image(win->mlx_id,
					img->win_width,
					img->win_height);
			if (img->self_id)
			{
				img->data = mlx_get_data_addr(img->self_id,
						&(img->bpp),
						&(img->line_size),
						&(img->endian));
				if (!img->data)
					exit(1);
			}
			else
				exit(1);
		}
		else
			exit(1);
	}
	else
		exit(1);
}

void			start_window(t_hub *hub)
{
	create_window(hub, &(hub->win), &(hub->img));
	if (hub->win.mlx_id && hub->win.self_id)
	{
		ft_putstr("//startup_scene\n");
		startup_scene(hub);
		ft_putstr("//render\n");
		render(hub);
		ft_putstr("//hook\n");
		mlx_hook(hub->win.self_id,
				KEYPRESS,
				KEYPRESSMASK,
				&keyboard_hooks,
				hub);
		ft_putstr("//loop\n");
		mlx_loop(hub->win.mlx_id);
	}
}
