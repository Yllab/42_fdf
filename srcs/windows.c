/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:17:23 by hbally            #+#    #+#             */
/*   Updated: 2018/12/09 22:25:40 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "keys.h"
/*
** DEBUG
*/

#include "libft.h"
/*
** TODO
*/

static void		find_window_size(t_hub *hub)
{
	hub->img.win_width = 1500;
	hub->img.win_height = 1000;
}

/*
** _________________________________________
*/

static void		create_window(t_hub *hub,
								t_win *win, t_img *img)
{
	win->mlx_id = mlx_init();
	if (win->mlx_id)
	{
		find_window_size(hub);
		win->self_id = mlx_new_window(win->mlx_id,
										img->win_width, img->win_height, "fdf");
		if (win->self_id)
		{
			img->self_id = mlx_new_image(win->mlx_id, 
										img->win_width, img->win_height);
			img->data = mlx_get_data_addr(img->self_id, &(img->bpp),
											&(img->line_size), &(img->endian));
		}
	}
	else
		exit(1);
}

void			start_window(t_hub *hub)
{
	create_window(hub, &(hub->win), &(hub->img));
	if (hub->win.mlx_id && hub->win.self_id)
	{
		startup_scene(hub);
		render(hub);
		mlx_hook(hub->win.self_id, KEYPRESS, KEYPRESSMASK, &keyboard_hooks, hub);
		mlx_loop(hub->win.mlx_id);
	}
}
