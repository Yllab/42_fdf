/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:34:49 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 19:39:34 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "colors.h"

static void		img_update(t_hub *hub, t_line *line, int x, int y)
{
	int			color;

	if (x < hub->img.win_width &&
		y < hub->img.win_height &&
		x > 0 && y > 0)
	{
		color = pixel_color(hub, line, x);
		ft_memmove(&(hub->img.data[(y * hub->img.line_size) + (x * 4)]),
						&color, sizeof(int));
	}
}

static void		draw_line_low(t_hub *hub,
								t_line *line,
								t_vector p1,
								t_vector p2)
{
	int			dx;
	int			dy;
	int			increment;
	int			error;

	dx = (int)(p2.x - p1.x);
	dy = (int)(p2.y - p1.y);
	increment = dy > 0 ? 1 : -1;
	dy *= dy > 0 ? 2 : -2;
	error = dy - dx;
	dx *= 2;
	while (p1.x <= p2.x)
	{
		img_update(hub, line, (int)p1.x, (int)p1.y);
		if (error > 0)
		{
			p1.y += increment;
			error -= dx;
		}
		error += dy;
		p1.x++;
	}
}

static void		draw_line_steep(t_hub *hub,
									t_line *line,
									t_vector p1,
									t_vector p2)
{
	int			dx;
	int			dy;
	int			error;
	float		increment;

	dx = (int)(p2.x - p1.x);
	dy = (int)(p2.y - p1.y);
	increment = dx > 0 ? 1 : -1;
	dx *= dx > 0 ? 2 : -2;
	error = dx - dy;
	dy *= 2;
	while (p1.y <= p2.y)
	{
		img_update(hub, line, (int)p1.x, (int)p1.y);
		if (error > 0)
		{
			p1.x += increment;
			error -= dy;
		}
		error += dx;
		p1.y++;
	}
}

void			draw_line(t_hub *hub, t_vector p1, t_vector p2)
{
	t_line		line;

	line.start = &p1;
	line.end = &p2;
	if (fabs((double)(p2.y - p1.y)) < fabs((double)(p2.x - p1.x)))
	{
		if (p2.x > p1.x)
			draw_line_low(hub, &line, p1, p2);
		else
			draw_line_low(hub, &line, p2, p1);
	}
	else
	{
		if (p2.y > p1.y)
			draw_line_steep(hub, &line, p1, p2);
		else
			draw_line_steep(hub, &line, p2, p1);
	}
}
