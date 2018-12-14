/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:32:47 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 17:12:43 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "keys.h"
#include "colors.h"

static void		hook_1(int keycode, t_camera *camera, int scale)
{
	if (keycode == LSFT_KEY || keycode == RSFT_KEY)
		camera->autorotate = camera->autorotate ? 0 : 1;
	if (keycode == LEFT_KEY)
		camera->t.rotate_y += M_PI / 50;
	if (keycode == RIGHT_KEY)
		camera->t.rotate_y -= M_PI / 50;
	if (keycode == UP_KEY)
		camera->t.rotate_x -= M_PI / 50;
	if (keycode == DOWN_KEY)
		camera->t.rotate_x += M_PI / 50;
	if (keycode == I_KEY && camera->canvas > 0.1 &&
			(camera->proj || ((!camera->proj && (camera->canvas - 0.05 * scale > 0.1)))))
		camera->canvas -= 0.05 * (!camera->proj ? scale : 1);
	if (keycode == K_KEY && camera->canvas < 1000)
		camera->canvas += 0.05 * (!camera->proj ? scale : 1);
	if (keycode == ESC_KEY)
		exit(0);
}

static void		hook_2(int keycode, t_hub *hub)
{
	if (keycode == N_KEY)
		hub->img.night_mode = hub->img.night_mode == 1 ? 0 : 1;
	if (keycode == PL_KEY)
		hub->camera.speed += (hub->map->width + hub->map->height) / 2;
	if (keycode == MN_KEY)
	{
		hub->camera.speed -= hub->map->width;
		if (hub->camera.speed <= 0.001)
			hub->camera.speed = 1;
	}
	if (keycode == W_KEY)
		hub->camera.t.translate_y += 0.01 * hub->camera.speed;
	if (keycode == S_KEY)
		hub->camera.t.translate_y -= 0.01 * hub->camera.speed;
	if (keycode == E_KEY)
		hub->camera.t.translate_z -= 0.01 * hub->camera.speed;
	if (keycode == A_KEY)
		hub->camera.t.translate_x -= 0.01 * hub->camera.speed;
	if (keycode == Q_KEY)
		hub->camera.t.translate_z += 0.01 * hub->camera.speed;
	if (keycode == D_KEY)
		hub->camera.t.translate_x += 0.01 * hub->camera.speed;
	if (keycode == F_KEY)
		hub->camera.fullrender = hub->camera.fullrender == 0 ? 1 : 0;
}

static void		hook_3(int keycode, t_hub *hub)
{
	if (keycode == P_KEY)
	{
		hub->camera.proj = hub->camera.proj ? 0 : 1;
		startup_camera(&(hub->camera), hub->map);
		reset_canvas(&hub->camera, hub->map);
	}
	if (keycode == PUP_KEY)
		transform_map(hub->map, 0.06, 0);
	if (keycode == PDOWN_KEY)
		transform_map(hub->map, -0.06, 0);
	if (keycode == HOME_KEY)
		transform_map(hub->map, 0, 0.03);
	if (keycode == END_KEY)
		transform_map(hub->map, 0, -0.03);
	if (keycode == K1_KEY)
		theme_red(&(hub->theme));
	if (keycode == K2_KEY)
		theme_pink(&(hub->theme));
	if (keycode == K3_KEY)
		theme_catalog(&(hub->theme));
	if (keycode == K4_KEY)
		theme_purple(&(hub->theme));
	if (keycode == K5_KEY)
		theme_cafe(&(hub->theme));
}

static void		hook_4(int keycode, t_hub *hub)
{
	if (keycode == Z_KEY || keycode == X_KEY || keycode == C_KEY ||
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
	if (keycode == H_KEY)
		hub->img.show_ui = hub->img.show_ui == 1 ? 0 : 1;
	if (keycode == W_KEY && hub->camera.proj == 0)
		hub->camera.t.translate_y += 0.01 * hub->camera.speed;
	if (keycode == S_KEY && hub->camera.proj == 0)
		hub->camera.t.translate_y -= 0.01 * hub->camera.speed;
	if (keycode == R_KEY)
	{
		startup_map(hub->map);
		startup_camera(&(hub->camera), hub->map);
	}
}

int				keyboard_hooks(int keycode, void *param)
{
	t_hub	*hub;

	hub = (t_hub*)param;
	hook_1(keycode, &(hub->camera), hub->map->scale);
	hook_2(keycode, hub);
	hook_3(keycode, hub);
	hook_4(keycode, hub);
	if (hub->camera.autorotate)
		hub->camera.t.rotate_y += M_PI / 300;
	if (hub->camera.t.translate_x > 1000 ||
			hub->camera.t.translate_y > 1000 ||
			hub->camera.t.translate_z > 1000)
		startup_camera(&(hub->camera), hub->map);
	render(hub);
	return (0);
}
