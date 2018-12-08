/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:17:23 by hbally            #+#    #+#             */
/*   Updated: 2018/12/08 16:11:52 by hbally           ###   ########.fr       */
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
	hub->camera.win_w = 1000;
	hub->camera.win_h = 1000;
}

/*
** _________________________________________
*/

static void		create_window(t_hub *hub,
								t_win *win, t_img *img, t_camera *cam)
{
	win->mlx_id = mlx_init();
	if (win->mlx_id)
	{
		find_window_size(hub);
		win->self_id = mlx_new_window(win->mlx_id, cam->win_w, cam->win_h,
																		"fdf");
		if (win->self_id)
		{
			img->self_id = mlx_new_image(win->mlx_id, cam->win_w, cam->win_h);
			img->data = mlx_get_data_addr(img->self_id, &(img->bpp),
											&(img->line_size), &(img->endian));
			img->color = 0xFFFFFF;
		}
	}
	else
		exit(1);
}

void			start_window(t_hub *hub)
{
	ft_bzero(&(hub->camera), sizeof(t_camera));
	create_window(hub, &(hub->win), &(hub->img), &(hub->camera));
	if (hub->win.mlx_id && hub->win.self_id)
	{
		mlx_key_hook(hub->win.self_id, &key_hook, hub);
		startup_scene(hub);
		render(hub);
		mlx_loop(hub->win.mlx_id);
	}
}
