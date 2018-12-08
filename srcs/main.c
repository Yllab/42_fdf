/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/08 15:29:17 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "matrix.h"

/*
** map->transform.matrix needs to be an identity matrix before the first call
** to this function otherwise behavior is undefined
*/

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
		}
	}
	return (0);
}
