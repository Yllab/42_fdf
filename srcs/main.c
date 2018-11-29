/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/11/29 20:21:32 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"

#include "mlx.h"

//debug
#include <stdio.h>
int			main(int argc, char **argv)
{
	int		fd;
	t_list	*map_raw;

	//TODO Usage
	if (argc != 2)
		return (0);	

	fd = open(argv[1], O_RDONLY);
	map_raw = get_input(fd);

	int i;
	while (map_raw->next != NULL)
	{
		i = 0;
		while (i < (int)(map_raw->content_size))
		{
			printf("%d ", *(int*)(map_raw->content + i));
			i++;
		}
		map_raw++;
	}
	return (-1);
}
