/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:32:47 by hbally            #+#    #+#             */
/*   Updated: 2018/12/13 19:57:11 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "keys.h"
#include "colors.h"

static void		hook_camera_2(int keycode, t_hub *hub)
{
	if (keycode == Q_KEY)
		hub->camera.t.rotate_y += M_PI / 50;
	if (keycode == E_KEY)
		hub->camera.t.rotate_y -= M_PI / 50;
	if (keycode == T_KEY)
		hub->camera.t.rotate_x -= M_PI / 50;
	if (keycode == G_KEY)
		hub->camera.t.rotate_x += M_PI / 50;
	if (keycode == K_KEY && hub->camera.canvas_h < 100)
	{
		hub->camera.canvas_h += 0.05;
		hub->camera.canvas_w += 0.05;
	}
	if (keycode == I_KEY && hub->camera.canvas_h > 0.1)
	{
		hub->camera.canvas_h -= 0.05;
		hub->camera.canvas_w -= 0.05;
	}
	if (keycode == L_KEY && hub->camera.canvas_h > 0.1)
		hub->camera.canvas_w += 0.05;
	if (keycode == J_KEY && hub->camera.canvas_h < 100)
		hub->camera.canvas_w -= 0.05;
	if (keycode == P_KEY)
	{
		hub->camera.projection++;
		if (hub->camera.projection > 1)
			hub->camera.projection = 0;
		reset_canvas(&hub->camera, hub->map);
	}
}

static void		hook_camera_1(int keycode, t_hub *hub)
{
	if (keycode == PL_KEY)
		hub->camera.speed += hub->map->width;
	if (keycode == MN_KEY)
	{
		hub->camera.speed -= hub->map->width;
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
	if (keycode == R_KEY)
		startup_camera(&(hub->camera), hub->map);
	if (keycode == F_KEY)
		hub->camera.fullrender = hub->camera.fullrender == 0 ? 1 : 0;
}

static void		hook_map(int keycode, t_hub *hub)
{
	if (keycode == PUP_KEY)
		transform_map(hub->map, 0.01, 0);
	if (keycode == PDOWN_KEY)
		transform_map(hub->map, -0.01, 0);
	if (keycode == HOME_KEY)
		transform_map(hub->map, 0, 0.01);
	if (keycode == END_KEY)
		transform_map(hub->map, 0, -0.01);
	if (keycode == K1_KEY)
		hub->map->gradient = 1;
	if (keycode == K2_KEY)
		hub->map->gradient = 2;
	if (keycode == K3_KEY)
		hub->map->gradient = 3;
	if (keycode == K4_KEY)
		hub->map->gradient = 4;
	if (keycode == K5_KEY)
		hub->map->gradient = 5;
}

static void		hook_ui(int keycode, t_hub *hub)
{
	if (keycode == Z_KEY ||
			keycode == X_KEY ||
			keycode == C_KEY ||
			keycode == V_KEY)
	{
		if (keycode == Z_KEY)
			hub->img.background_color = PASTEL_YELLOW;
		if (keycode == X_KEY)
			hub->img.background_color = PASTEL_PINK;
		if (keycode == C_KEY)
			hub->img.background_color = PASTEL_AZURE;
		if (keycode == V_KEY)
			hub->img.background_color = PASTEL_WHITE;
		hub->img.night_mode = 0;
	}
	if (keycode == N_KEY)
		hub->img.night_mode = hub->img.night_mode == 1 ? 0 : 1;
	if (keycode == H_KEY)
		hub->img.show_ui = hub->img.show_ui == 1 ? 0 : 1;
	if (keycode == ESC_KEY)
		exit(0);
}

int				keyboard_hooks(int keycode, void *param)
{
	t_hub	*hub;

	hub = (t_hub*)param;
	hook_camera_1(keycode, hub);
	hook_camera_2(keycode, hub);
	hook_map(keycode, hub);
	hook_ui(keycode, hub);
	render(hub);
	return (1);
}
