/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:12:41 by hbally            #+#    #+#             */
/*   Updated: 2018/12/10 18:14:03 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "colors.h"
#include "mlx.h"

void				draw_ui(t_img *img, t_win *win)
{
	int color;
	int anchor_x;
	int anchor_y;
	int line;
	int line_increment;

	anchor_x = img->win_width - 200;
	anchor_y = img->win_height - 30;
	line = 0;
	line_increment = -20;
	color = img->night_mode ? LIGHT_GRAY : MEDIUM_GRAY;
	if (img->show_ui)
	{
		mlx_string_put(win->mlx_id, win->self_id, anchor_x, anchor_y + line, 
			color, "F1 > F12 --");
		line += line_increment;
		mlx_string_put(win->mlx_id, win->self_id, anchor_x, anchor_y + line, 
			color, "N        -- Night");
		line += line_increment;
		mlx_string_put(win->mlx_id, win->self_id, anchor_x, anchor_y + line, 
			color, "R        -- Reset");
		line += line_increment;
		mlx_string_put(win->mlx_id, win->self_id, anchor_x, anchor_y + line, 
			color, "Q / E    -- Yaw");
		line += line_increment;
		mlx_string_put(win->mlx_id, win->self_id, anchor_x, anchor_y + line, 
			color, "G / T    -- Pitch");
		line += line_increment;
		mlx_string_put(win->mlx_id, win->self_id, anchor_x, anchor_y + line, 
			color, "+ / -    -- Speed");
		line += line_increment;
		mlx_string_put(win->mlx_id, win->self_id, anchor_x, anchor_y + line, 
			color, "Arrows   -- Up/Down");
		line += line_increment;
		mlx_string_put(win->mlx_id, win->self_id, anchor_x, anchor_y + line, 
			color, "WASD     -- Move");
		line += line_increment;
		mlx_string_put(win->mlx_id, win->self_id, anchor_x, anchor_y + line, 
			color, "CAMERA");
	}
	else
		mlx_string_put(win->mlx_id, win->self_id, anchor_x - 30, anchor_y + line, 
			color, "H - Show/Hide Controls");
}
