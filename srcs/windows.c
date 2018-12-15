/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:23:05 by hbally            #+#    #+#             */
/*   Updated: 2018/12/15 23:08:55 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "keys.h"

static void		get_window_size(t_hub *hub)
{
	hub->img.win_width = WIN_WIDTH;
	hub->img.win_height = WIN_HEIGHT;
}

static void		create_img(t_hub *hub, t_win *win, t_img *img)
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
			fdf_exit(hub, "Could not allocate image data.");
	}
	else
		fdf_exit(hub, "Could not allocate image.");
}

static void		create_window(t_hub *hub)
{
	hub->win.mlx_id = mlx_init();
	if (hub->win.mlx_id)
	{
		get_window_size(hub);
		hub->win.self_id = mlx_new_window(hub->win.mlx_id,
											hub->img.win_width,
											hub->img.win_height,
											"fdf");
		if (hub->win.self_id)
			create_img(hub, &(hub->win), &(hub->img));
		else
			fdf_exit(hub, "Could not allocate window.");
	}
	else
		fdf_exit(hub, "Could not allocate MLX.");
}

void			start_window(t_hub *hub)
{
	create_window(hub);
	startup_scene(hub);
	render(hub);
	mlx_hook(hub->win.self_id, KEYPRESS, KEYPRESSMASK, &keyboard_hooks, hub);
	mlx_loop_hook(hub->win.mlx_id, &loop_hook, hub);
	mlx_loop(hub->win.mlx_id);
	fdf_exit(hub, "Fatal error with MLX loop.");
}
