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

void			img_update(t_img *img, t_line *line, int x, int y)
{
	int			color;
	if (line->start->altitude < line->end->altitude)
		color = line->start_color;
	else
		color = line->end_color;
	if (!(x >= img->win_width || y >= img->win_height || x < 0 || y < 0))
		ft_memmove(&(img->data[y * img->line_size + x * 4]), &color, 4);
}
