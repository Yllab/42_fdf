/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:30:50 by hbally            #+#    #+#             */
/*   Updated: 2018/12/15 14:49:27 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void			free_input_row(void *row, size_t row_size)
{
	ft_memdel(&row);
	row_size = 0;
}

static void		fdf_close(char *msg)
{
	if (msg)
	{
		ft_putstr("Error : ");
		ft_putendl(msg);
		exit(EXIT_FAILURE);
	}
		exit(EXIT_SUCCESS);
}

void			fdf_input_exit(t_map *map, t_list *map_raw, char *msg)
{
	ft_lstdel(&map_raw, &free_input_row);
	map = NULL;
	fdf_close(msg);
}

void			fdf_window_exit(t_hub *hub, char *msg)
{
	hub = NULL;
	fdf_close(msg);
}
