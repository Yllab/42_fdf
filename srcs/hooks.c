/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:39:50 by hbally            #+#    #+#             */
/*   Updated: 2018/12/08 19:28:12 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int			key_hook(int keycode, void *param)
{
	if (keycode == 126)
		((t_hub*)param)->camera.t.translate_y += 10;
	if (keycode == 125)
		((t_hub*)param)->camera.t.translate_y -= 10;
	if (keycode == 12)
		((t_hub*)param)->camera.t.rotate_y += M_PI / 6;
	if (keycode == 13)
		((t_hub*)param)->camera.t.translate_z -= 10;
	if (keycode == 14)
		((t_hub*)param)->camera.t.rotate_y -= M_PI / 6;
	if (keycode == 0)
		((t_hub*)param)->camera.t.translate_x -= 10;
	if (keycode == 1)
		((t_hub*)param)->camera.t.translate_z += 10;
	if (keycode == 2)
		((t_hub*)param)->camera.t.translate_x += 10;
	render((t_hub*)param);
	return (1);
}
