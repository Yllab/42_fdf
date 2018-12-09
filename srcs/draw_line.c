/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:29:26 by hbally            #+#    #+#             */
/*   Updated: 2018/12/09 23:10:18 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static int		draw_line_low(t_img *img, t_line *line,
								t_vector p1, t_vector p2)
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
		if (!(img_update(img, line, (int)p1.x, (int)p1.y)))
			return (0);
		if (error > 0)
		{
			p1.y += increment;
			error -= dx;
		}
		error += dy;
		p1.x++;
	}
	return (1);
}

static int		draw_line_steep(t_img *img, t_line *line,
								t_vector p1, t_vector p2)
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
		if (!img_update(img, line, (int)p1.x, (int)p1.y))
			return (0);
		if (error > 0)
		{
			p1.x += increment;
			error -= dy;
		}
		error += dx;
		p1.y++;
	}
	return (1);
}

void			draw_line(t_img *img, t_vector p1, t_vector p2)
{
	t_line		line;
	int			reverse;

	reverse = 0;
	line.start_x = p1.x;
	line.start_y = p1.y;
	line.end_x = p2.x;
	line.end_y = p2.y;
	if ((p1.x >= img->win_width ||
		p1.y >= img->win_height ||
		p1.x < 0 || p1.y < 0) &&
		(p2.x >= 0 && p2.y >= 0 &&
		 p2.x < img->win_width &&
		 p2.y < img->win_height))
		reverse = 1;
	if (fabs((double)(p2.y - p1.y)) < fabs((double)(p2.x - p1.x)))
	{
		if (p2.x > p1.x)
			!reverse ? draw_line_low(img, &line, p1, p2) : draw_line_low(img, &line, p2, p1);
		else
			!reverse ? draw_line_low(img, &line, p2, p1) : draw_line_low(img, &line, p1, p2);
	}
	else
	{
		if (p2.y > p1.y)
			!reverse ? draw_line_steep(img, &line, p1, p2) : draw_line_steep(img, &line, p2, p1);
		else
			!reverse ? draw_line_steep(img, &line, p2, p1) : draw_line_steep(img, &line, p1, p2);
	}
}
