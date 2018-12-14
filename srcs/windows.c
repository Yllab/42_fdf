/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:17:23 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 20:03:36 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "keys.h"

static void		create_img(t_win *win, t_img *img)
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

static void		find_window_size(t_hub *hub)
{
	hub->img.win_width = 2560;
	hub->img.win_height = 1400;
}

static void		create_window(t_hub *hub)
{
	hub->win.mlx_id = mlx_init();
	if (hub->win.mlx_id)
	{
		find_window_size(hub);
		hub->win.self_id = mlx_new_window(hub->win.mlx_id,
											hub->img.win_width,
											hub->img.win_height,
											"fdf");
		if (hub->win.self_id)
			create_img(&(hub->win), &(hub->img));
		else
			exit(1);
	}
	else
		exit(1);
}

void			start_window(t_hub *hub)
{
	create_window(hub);
	if (hub->win.mlx_id && hub->win.self_id)
	{
		startup_scene(hub);
		render(hub);
		mlx_hook(hub->win.self_id,
					KEYPRESS,
					KEYPRESSMASK,
					&keyboard_hooks,
					hub);
		mlx_loop_hook (hub->win.mlx_id, &loop_hook, hub);
		mlx_loop(hub->win.mlx_id);
		exit (1);
	}
}
