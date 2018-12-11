/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:37:57 by hbally            #+#    #+#             */
/*   Updated: 2018/12/11 18:50:42 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>
#include <types.h>
#include "libft.h"

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
