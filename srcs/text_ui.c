
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:12:41 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 13:44:07 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "colors.h"
#include "mlx.h"

static void			draw_ui_3(t_win *win, t_ui *ui)
{
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "P         - Projection");
	ui->line += ui->line_increment;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "+ / -     - Speed");
	ui->line += ui->line_increment;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "I / K     - Zoom");
	ui->line += ui->line_increment;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "Shift     - AutoRotate");
	ui->line += ui->line_increment;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "Arrows    - Rotation");
	ui->line += ui->line_increment;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "WASDQE    - Move");
	ui->line += ui->line_increment;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "CAMERA");
}

static void			draw_ui_2(t_win *win, t_ui *ui)
{
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "1 2 3 4 5 - Gradient");
	ui->line += ui->line_increment;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "Z X C V   - Background");
	ui->line += ui->line_increment;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "COLORS");
	ui->line += ui->line_increment * 2;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "Home|End  - Size");
	ui->line += ui->line_increment;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "PgUp|Dwn  - Altitude");
	ui->line += ui->line_increment;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "MAP SCALING");
	ui->line += ui->line_increment * 2;
	mlx_string_put(win->mlx_id, win->self_id, ui->a_x, ui->a_y + ui->line,
			ui->color, "R         - Reset");
	ui->line += ui->line_increment;
	draw_ui_3(win, ui);
}

void				draw_ui(t_img *img, t_win *win)
{
	t_ui			ui;

	ui.a_x = img->win_width - 230;
	ui.a_y = img->win_height - 30;
	ui.line = 0;
	ui.line_increment = -20;
	ui.color = img->night_mode ? LIGHT_GRAY : MEDIUM_GRAY;
	if (img->show_ui)
	{
		mlx_string_put(win->mlx_id, win->self_id, ui.a_x, ui.a_y + ui.line,
				ui.color, "F         - Fast Mode");
		ui.line += ui.line_increment;
		mlx_string_put(win->mlx_id, win->self_id, ui.a_x, ui.a_y + ui.line,
				ui.color, "RENDER");
		ui.line += ui.line_increment * 2;
		mlx_string_put(win->mlx_id, win->self_id, ui.a_x, ui.a_y + ui.line,
				ui.color, "N         - Dark OnOff");
		ui.line += ui.line_increment;
		draw_ui_2(win, &ui);
	}
	else
		mlx_string_put(win->mlx_id, win->self_id, ui.a_x, ui.a_y + ui.line,
				ui.color, "H - Show/Hide Controls");
}
