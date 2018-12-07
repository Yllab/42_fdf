/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:17:23 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 19:03:49 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

/*
** DEBUG
*/

#include "libft.h"
/*
** TODO
*/

static void		find_window_size(t_hub *hub)
{
	hub->win.w = 1500;
	hub->win.h = 1000;
}

/*
** _________________________________________
*/

static void		create_window(t_hub *hub)
{
	hub->win.mlx_id = mlx_init();
	if (hub->win.mlx_id)
	{
		find_window_size(hub);
		hub->win.self_id = mlx_new_window(hub->win.mlx_id,
											hub->win.w, hub->win.h, "fdf");
		if (hub->win.self_id)
		{
			hub->img.self_id = mlx_new_image(hub->win.mlx_id, 
												hub->win.w, hub->win.h);
			hub->img.data = mlx_get_data_addr(hub->img.self_id, &(hub->img.bpp),
									&(hub->img.line_size), &(hub->img.endian));
			hub->img.color = 0xFFFFFF;
		}
	}
	else
		exit(1);
}

int				key_hook(int keycode, void *param);

void			start_window(t_hub *hub)
{
	create_window(hub);
	if (hub->win.mlx_id && hub->win.self_id)
	{
		//mlx_key_hook(hub->win.self_id, &key_hook, hub);
		mlx_loop(hub->win.mlx_id);
	}
}
