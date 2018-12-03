/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:29:26 by hbally            #+#    #+#             */
/*   Updated: 2018/12/03 15:30:38 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

//DEBUG
	#include <stdio.h>

static void		update_img(t_img *img, int x, int y)
{
	x = x * 4 + img->endian;
	img->data[y * img->line_size + x] = 0xFF;
	img->data[y * img->line_size + x + 1] = 0xFF;
	img->data[y * img->line_size + x + 2] = 0xFF;
}

static void 	draw_line_low(t_img *img, t_vector p1, t_vector p2)
{
	int 		dx;
	int 		dy;
	int 		yi;
	int 		e;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	yi = dy > 0 ? 1 : -1;
	dy *= dy > 0 ? 2 : -2;
	e = dy - dx;
	dx *= 2;

	while (p1.x <= p2.x)
	{
		update_img(img, p1.x, p1.y);
		if (e > 0)
		{
			p1.y += yi;
			e -= dx;
		}
		e += dy;
		p1.x++;
	}
}

static void 	draw_line_steep(t_img *img, t_vector p1, t_vector p2)
{
	int 		dx;
	int 		dy;
	int 		xi;
	int 		e;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	xi = dx > 0 ? 1 : -1;
	dx *= dx > 0 ? 2 : -2;
	e = dx - dy;
	dy *= 2;

	while (p1.y <= p2.y)
	{
		update_img(img, p1.x, p1.y);
		if (e > 0)
		{
			p1.x += xi;
			e -= dy;
		}
		e += dx;
		p1.y++;
	}
}

void 			draw_line_pilot(t_vector p1, t_vector p2, t_img *img)
{
	if (fabs((double)(p2.y - p1.y)) < fabs((double)(p2.x - p1.x)))
	{
		if (p2.x > p1.x)
			draw_line_low(img, p1, p2);
		else
			draw_line_low(img, p2, p1);
	}
	else
	{
		if (p2.y > p1.y)
			draw_line_steep(img, p1, p2);	
		else
			draw_line_steep(img, p2, p1);
	}
}
