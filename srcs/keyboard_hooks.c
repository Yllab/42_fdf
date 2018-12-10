/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:39:50 by hbally            #+#    #+#             */
/*   Updated: 2018/12/10 14:14:32 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"
#include "colors.h"
#include <math.h>

void		hook_camera(int keycode, t_hub *hub)
{
	if (keycode == PL_KEY)
		hub->camera.speed += 10;
	if (keycode == MN_KEY)
	{
		hub->camera.speed -= 10;
		if (hub->camera.speed <= 0)
			hub->camera.speed = 1;
	}
	if (keycode == UP_KEY)
		hub->camera.t.translate_y += 0.01 * hub->camera.speed;
	if (keycode == DOWN_KEY)
		hub->camera.t.translate_y -= 0.01 * hub->camera.speed;
	if (keycode == W_KEY)
		hub->camera.t.translate_z -= 0.01 * hub->camera.speed;
	if (keycode == A_KEY)
		hub->camera.t.translate_x -= 0.01 * hub->camera.speed;
	if (keycode == S_KEY)
		hub->camera.t.translate_z += 0.01 * hub->camera.speed;
	if (keycode == D_KEY)
		hub->camera.t.translate_x += 0.01 * hub->camera.speed;
	if (keycode == Q_KEY)
		hub->camera.t.rotate_y += M_PI / 150;
	if (keycode == E_KEY)
		hub->camera.t.rotate_y -= M_PI / 150;
	if (keycode == T_KEY)
		hub->camera.t.rotate_x -= M_PI / 150;
	if (keycode == G_KEY)
		hub->camera.t.rotate_x += M_PI / 150;
	if (keycode == R_KEY)
		startup_camera(&(hub->camera), hub->map);
	if (keycode == PUP_KEY)
		startup_map(hub->map, 0.01, 0);
	if (keycode == PDOWN_KEY)
		startup_map(hub->map, -0.01, 0);
	if (keycode == HOME_KEY)
		startup_map(hub->map, 0, 0.01);
	if (keycode == END_KEY)
		startup_map(hub->map, 0, -0.01);
	if (keycode == I_KEY)
		hub->camera.canvas_h += 0.1;
	if (keycode == K_KEY)
		hub->camera.canvas_h -= 0.1;
	if (keycode == J_KEY)
		hub->camera.canvas_w -= 0.1;
	if (keycode == L_KEY)
		hub->camera.canvas_w += 0.1;
}

void		hook_color(int keycode, t_hub *hub)
{
	if (keycode == B_KEY)
	{
		if (hub->img.background_color == DARK_GRAY)
		{
			hub->img.background_color = LIGHT_BLUE;
			if (hub->img.map_color == LIGHT_BLUE)
				hub->img.map_color = DARK_GRAY;
		}
		else
		{
			hub->img.background_color = DARK_GRAY;
			if (hub->img.map_color == DARK_GRAY)
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
