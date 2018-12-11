/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/11 18:30:29 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"

int			main(int argc, char **argv)
{
	int			fd;
	t_hub		hub;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			hub.map = build_map(fd);
			if (hub.map)
				start_window(&hub);
			exit(1);
		}
	}
	else
	{
		ft_putstr("Input file not provided / Read error\n");
		ft_putstr("Usage : ~~/fdf [map.fdf]\n");
		ft_putstr("(Note : map.fdf must contain only integers separated by\n");
		ft_putstr(" a single space. Map must be rectangular.)\n");
		return (0);
	}
}
