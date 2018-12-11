/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:34:49 by hbally            #+#    #+#             */
/*   Updated: 2018/12/11 20:32:04 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

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
	ft_putstr("FUUUUUU\n");
	while (p1.x <= p2.x)
	{
		ft_putstr("KKKKKKK\n");
		img_update(hub, line, (int)p1.x, (int)p1.y);
		ft_putstr("KKKKKKK\n");
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
	ft_putstr("5\n");
	while (p1.y <= p2.y)
	{
		ft_putstr("6\n");
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

	ft_putstr("draw line\n");
	ft_putstr("1\n");
	line.start = &p1;
	line.end = &p2;
	line.start_color = find_color(p1); //
	line.end_color = find_color(p2); //
	ft_putstr("2\n");
	if (fabs((double)(p2.y - p1.y)) < fabs((double)(p2.x - p1.x)))
	{
	ft_putstr("3\n");
		if (p2.x > p1.x)
			draw_line_low(hub, &line, p1, p2);
		else
			draw_line_low(hub, &line, p2, p1);
	}
	else
	{
	ft_putstr("4\n");
		if (p2.y > p1.y)
			draw_line_steep(hub, &line, p1, p2);
		else
			draw_line_steep(hub, &line, p2, p1);
	}
}
