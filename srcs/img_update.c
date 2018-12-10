/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:35:20 by hbally            #+#    #+#             */
/*   Updated: 2018/12/10 18:43:00 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"
#include <math.h>

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

static int		yui(double n)
{
	if (n < 1.0/3.0)
	{
		return (int)(0xFF0000 * (n * 2.8)) & 0xFF0000;
	}
	else if (n < 2.0 / 3.0)
	{
		return ((int)((int)(0x00FF00 * ((n - 1.0/3.2) * 2.8)) & 0x00FF00) | (int)((int)(0xFF0000 * (1.0 - (n - 1.0/3.2) * 2.8)) & 0xFF0000));
	}
	else
	{
		return ((int)((int)(0x0000FF * ((n - 2.0/3.2) * 2.8)) & 0x0000FF) | (int)((int)(0x00FF00 * (1.0 - (n - 2.0/3.2) * 2.8)) & 0x00FF00));
	}
}

static inline int iabs(float nb) {return ((int)((nb < 0) ? -nb : nb));}

void			img_update(t_img *img, t_line *line, int x, int y, t_hub *hub)
{
	int			color;
	int			td = iabs(line->start->x - line->end->x);
	int			rd = iabs((float)x - line->end->x);
	double		c = (td > 0) ? ((double)rd / (double)td) : 0.0;
	double a = ((double)line->start->altitude * c + (double)line->end->altitude * (1.0 - c));
	color = yui((1 - ((a - hub->map->min_y) / (double)(hub->map->max_y - hub->map->min_y))) * 0.8 + 0.1);

	//if (line->start->altitude < line->end->altitude)
	//	color = line->start_color;
	//else
	//	color = line->end_color;
	if (!(x >= img->win_width || y >= img->win_height || x < 0 || y < 0))
		ft_memmove(&(img->data[y * img->line_size + x * 4]), &color, 4);
}
