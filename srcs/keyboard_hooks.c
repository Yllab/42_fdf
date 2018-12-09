/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:39:50 by hbally            #+#    #+#             */
/*   Updated: 2018/12/09 22:23:58 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"
#include "colors.h"
#include <math.h>

void		hook_camera(int keycode, t_hub *hub)
{
	if (keycode == UP_KEY)
		hub->camera.t.translate_y += 0.5;
	if (keycode == DOWN_KEY)
		hub->camera.t.translate_y -= 0.5;
	if (keycode == W_KEY)
		hub->camera.t.translate_z -= 0.5;
	if (keycode == A_KEY)
		hub->camera.t.translate_x -= 0.5;
	if (keycode == S_KEY)
		hub->camera.t.translate_z += 0.5;
	if (keycode == D_KEY)
		hub->camera.t.translate_x += 0.5;
	if (keycode == Q_KEY)
		hub->camera.t.rotate_y += M_PI / 48;
	if (keycode == E_KEY)
		hub->camera.t.rotate_y -= M_PI / 48;
	if (keycode == R_KEY)
		startup_camera(&(hub->camera), hub->map);
}

void		hook_color(int keycode, t_hub *hub)
{
	if (keycode == B_KEY)
	{
		if (hub->img.background_color == DARK_GRAY)
		{
			hub->img.background_color = LIGHT_BLUE;
			hub->img.map_color = DARK_GRAY;
		}
		else
		{
			hub->img.background_color = DARK_GRAY;
			hub->img.map_color = LIGHT_BLUE;
		}
	}
}

int			keyboard_hooks(int keycode, void *param)
{
	t_hub	*hub;

	hub = (t_hub*)param;
	hook_camera(keycode, hub);
	hook_color(keycode, hub);
	render(hub);
	return (1);
}
