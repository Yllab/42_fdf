/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:44:16 by hbally            #+#    #+#             */
/*   Updated: 2018/12/13 16:23:49 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"
#include "mlx.h"

void				render(t_hub *hub)
{
	ft_bzero(hub->img.data, hub->img.line_size * hub->img.win_height);
	img_set_background(&(hub->img));
	ft_putstr("////////IN////////\n");
	transform_build(&(hub->camera.t));
	matrix_inv(hub->camera.t.matrix);
	world_to_screen(hub);
	ft_putstr("////////OUT////////\n");
	mlx_put_image_to_window(hub->win.mlx_id, hub->win.self_id,
							hub->img.self_id, 0, 0);
	draw_ui(&(hub->img), &(hub->win));
}
