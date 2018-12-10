/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/10 14:22:05 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "matrix.h"

int			main(int argc, char **argv)
{
	int			fd;
	t_hub		hub;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			ft_putstr("Loading Map...\n");
			hub.map = build_map(fd);
			if (hub.map)
				start_window(&hub);
		}
	}
	return (0);
}
