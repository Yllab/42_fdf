/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:29:26 by hbally            #+#    #+#             */ /*   Updated: 2018/12/10 08:54:17 by hbally           ###   ########.fr       */ /*                                                                            */ /* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void		draw_line_low(t_img *img, t_line *line,
								t_vector p1, t_vector p2, t_hub *hub)
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
		img_update(img, line, (int)p1.x, (int)p1.y, hub);
		if (error > 0)
		{
			p1.y += increment;
			error -= dx;
		}
		error += dy;
		p1.x++;
	}
}

static void		draw_line_steep(t_img *img, t_line *line,
								t_vector p1, t_vector p2, t_hub *hub)
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
		img_update(img, line, (int)p1.x, (int)p1.y, hub);
		if (error > 0)
		{
			p1.x += increment;
			error -= dy;
		}
		error += dx;
		p1.y++;
	}
}

void			draw_line(t_img *img, t_vector p1, t_vector p2, t_hub *hub)
{
	t_line		line;

	line.start = &p1;
	line.end = &p2;
	line.start_color = find_color(p1);
	line.end_color = find_color(p2);
	if (fabs((double)(p2.y - p1.y)) < fabs((double)(p2.x - p1.x)))
	{
		if (p2.x > p1.x)
			draw_line_low(img, &line, p1, p2, hub);
		else
			draw_line_low(img, &line, p2, p1, hub);
	}
	else
	{
		if (p2.y > p1.y)
			draw_line_steep(img, &line, p1, p2, hub);
		else
			draw_line_steep(img, &line, p2, p1, hub);
	}
}
