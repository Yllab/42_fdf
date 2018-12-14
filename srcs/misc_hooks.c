/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:15:37 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 11:34:01 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "types.h"
#include "fdf.h"

int		loop_hook(void *param)
{
	t_hub	*hub;

	hub = (t_hub*)param;
	if (hub->camera.autorotate)
	{
		hub->camera.t.rotate_y += M_PI / 300;
		render(hub);
	}
	return (0);
}
