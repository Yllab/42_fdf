/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:35:20 by hbally            #+#    #+#             */
/*   Updated: 2018/12/10 12:54:42 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"

void			img_set_background(t_img *img, int color)
{
	int			i;
	int 		j;
	int 		max_x;
	int 		max_y;

	i = 0;
	j = 0;
	max_x = img->win_width;
	max_y = img->win_height;
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

void			img_update(t_img *img, t_line *param, int x, int y)
{
	param = NULL;
	if (!(x >= img->win_width || y >= img->win_height || x < 0 || y < 0))
		ft_memmove(&(img->data[y * img->line_size + x * 4]), &img->map_color, 4);
}
