/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:37:57 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 13:53:00 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "colors.h"
#include "types.h"

//debug
#include "fdf.h"
void			img_set_background(t_img *img)
{
	int			i;
	int 		j;
	int 		max_x;
	int 		max_y;
	int 		color;

	i = 0;
	j = 0;
	max_x = img->win_width;
	max_y = img->win_height;
	if (img->night_mode)
		color = DARK_GRAY;
	else
		color = img->background_color;
	while (i < max_y)
	{
		j = 0;
		while (j < max_x)
		{
			ft_memmove(&(img->data[i * img->line_size + j * 4]), &color, 4);
			j++;
		}
		i++;
	}
}

int				pixel_color(t_hub *hub, t_line *line, int x, int y)
{
	double		total;
	double		remaining;
	double		coeff;
	double		alti;
	int			color;

	y = 0;

	total = fabs((double)(line->start->x - line->end->x));
	printf("total %f\n", total);
	remaining = fabs((double)((float)x - line->end->x));
	printf("remaining %f\n", remaining);
	coeff = total > 0.0 ? remaining / total : 0.0;
	printf("coeff %f\n", coeff);
	alti = coeff * (line->start->alti / line->end->alti) * (1.0 - coeff);
	printf("alti %f\n", alti);
	coeff = 1 - (alti - hub->map->min_y) / (hub->map->max_y - hub->map->min_y);


	color = coeff * 0xFFFFFF;
	printf("%d\n", color);
	return (color);
}

/*
color = yui((1 - ((a - hub->map->min_y) / (double)(hub->map->max_y - hub->map->min_y))) * 0.8 + 0.1);
static int		yui(double n)
{
	if (n < 1.0/3.0)
	{
		return (int)(0xFF0000 * (n * 2.0)) & 0xFF0000;
	}
	else if (n < 2.0 / 3.0)
	{
		return ((int)((int)(0x00FF00 * ((n - 1.0/3.0) * 2.0)) & 0x00FF00) | (int)((int)(0xFF0000 * (1.0 - (n - 1.0/3.0) * 2.0)) & 0xFF0000));
	}
	else
	{
		return ((int)((int)(0x0000FF * ((n - 2.0/3.0) * 3.0)) & 0x0000FF) | (int)((int)(0x00FF00 * (1.0 - (n - 2.0/3.0) * 2.0)) & 0x00FF00));
	}

}

int				find_color(t_vector point) //
{
	if (point.level == 1)
		return (PASTEL_DARK_BLUE);
	if (point.level == 2)
		return (PASTEL_BLUE);
	if (point.level > 2 && point.level <= 5)
		return (MEDIUM_GRAY);
	if (point.level > 50)
		return (PASTEL_RED);
	return (MEDIUM_GRAY);
}

*/

