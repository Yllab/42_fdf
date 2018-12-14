/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:37:57 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 15:42:28 by hbally           ###   ########.fr       */
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

int				pick_color(t_hub *hub, t_line *line, double coeff)
{
	if (line->start->alti < 0 || line->end->alti < 0)
	{
		if (line->start->alti < 0 && line->end->alti < 0)
			return (hub->theme.deep_sea);
		else
			return (hub->theme.plains_low);
	}
	if (!(int)line->start->alti || !(int)line->end->alti)
	{
		if (!(int)line->start->alti && !(int)line->end->alti)
			return (hub->theme.sea);
		else
			return (hub->theme.plains_low);
	}
	if (coeff >= 0 && coeff < 0.25)
		return (hub->theme.plains_low);
	if (coeff >= 0.25 && coeff < 0.50)
		return (hub->theme.plains_high);
	if (coeff >= 0.50 && coeff < 0.75)
		return (hub->theme.mountain_low);
	else
		return (hub->theme.mountain_high);
}

int				pixel_color(t_hub *hub, t_line *line, int x)
{
	double		total;
	double		remaining;
	double		coeff;
	double		alti;

	total = fabs((double)(line->start->x - line->end->x));
	remaining = fabs((double)((float)x - line->end->x));
	coeff = total > 0.0 ? remaining / total : 0.0;
	alti = line->start->alti * coeff + line->end->alti * (1.0 - coeff);
	coeff = alti / hub->map->max_y;
	return (pick_color(hub, line, coeff));
}
