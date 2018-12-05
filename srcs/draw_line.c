/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:29:26 by hbally            #+#    #+#             */
/*   Updated: 2018/12/05 14:23:27 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void		update_img(t_img *img, int x, int z)
{
	x = x * 4;
	ft_memmove(&(img->data[z * img->line_size + x]), &(img->color), 4);
}

static void 	draw_line_low(t_img *img, t_vector p1, t_vector p2)
{
	int 		dx;
	int 		dz;
	int 		yi;
	int 		e;

	dx = (int)(p2.x - p1.x);
	dz = (int)(p2.z - p1.z);
	yi = dz > 0 ? 1 : -1;
	dz *= dz > 0 ? 2 : -2;
	e = dz - dx;
	dx *= 2;

	while (p1.x <= p2.x)
	{
		update_img(img, (int)p1.x, (int)p1.z);
		if (e > 0)
		{
			p1.z += yi;
			e -= dx;
		}
		e += dz;
		p1.x++;
	}
}

static void 	draw_line_steep(t_img *img, t_vector p1, t_vector p2)
{
	int 		dx;
	int 		dz;
	int 		e;
	float 		xi;

	dx = (int)(p2.x - p1.x);
	dz = (int)(p2.z - p1.z);
	xi = dx > 0 ? 1 : -1;
	dx *= dx > 0 ? 2 : -2;
	e = dx - dz;
	dz *= 2;

	while (p1.z <= p2.z)
	{
		update_img(img, (int)p1.x, (int)p1.z);
		if (e > 0)
		{
			p1.x += xi;
			e -= dz;
		}
		e += dx;
		p1.z++;
	}
}

void 			draw_line(t_img *img, t_vector p1, t_vector p2)
{
	if (fabs((double)(p2.z - p1.z)) < fabs((double)(p2.x - p1.x)))
	{
		if (p2.x > p1.x)
			draw_line_low(img, p1, p2);
		else
			draw_line_low(img, p2, p1);
	}
	else
	{
		if (p2.z > p1.z)
			draw_line_steep(img, p1, p2);	
		else
			draw_line_steep(img, p2, p1);
	}
}
