/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:46:58 by hbally            #+#    #+#             */
/*   Updated: 2018/12/12 17:32:04 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "colors.h"

/*

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

static inline int iabs(float nb) {return ((int)((nb < 0) ? -nb : nb));}

	int			td = iabs(line->start->x - line->end->x);
	int			rd = iabs((float)x - line->end->x);
	double		c = (td > 0) ? ((double)rd / (double)td) : 0.0;
	double a = ((double)line->start->altitude * c + (double)line->end->altitude * (1.0 - c));
	color = yui((1 - ((a - hub->map->min_y) / (double)(hub->map->max_y - hub->map->min_y))) * 0.8 + 0.1);

*/

void			img_update(t_hub *hub, t_line *line, int x, int y)
{
	int			color;
	color = hub->img.night_mode ? LIGHT_GRAY : DARK_GRAY;

	//DEBUG
	line = NULL;

	if (x < hub->img.win_width &&
		y < hub->img.win_height &&
		x > 0 && y > 0)
		ft_memmove(&(hub->img.data[(y * hub->img.line_size) + (x * 4)]),
						&color, sizeof(int));
}
