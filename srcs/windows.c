/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:17:23 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 13:38:52 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

/*
** DEBUG
*/

#include "libft.h"
/*
** TODO
*/

static void		find_window_size(t_hub *hub)
{
	hub->win->w = 1500;
	hub->win->h = 1000;
}

/*
** _________________________________________
*/

static void		create_window(t_hub *hub)
{
	t_win 		win;
	t_img		img;

	hub->win = &win;
	hub->img = &img;
	win.mlx_id = mlx_init();
	if (win.mlx_id)
	{
		find_window_size(hub);
		win.self_id = mlx_new_window(win.mlx_id, win.w, win.h, "fdf");
		if (win.self_id)
		{
			img.self_id = mlx_new_image(win.mlx_id, win.w, win.h);
			img.data = mlx_get_data_addr(img.self_id,
						&(img.bpp), &(img.line_size), &(img.endian));
			img.color = 0xFFFFFF;
		}
	}
}

int				key_hook(int keycode, void *param);

void			start_window(t_hub *hub)
{
	create_window(hub);
	if (hub->win->mlx_id && hub->win->self_id)
	{
		mlx_key_hook(hub->win->self_id, &key_hook, hub);
		mlx_loop(hub->win->mlx_id);
	}
}
