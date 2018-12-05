/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/05 22:32:03 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"
#include "mlx.h"

//DEBUG
#include <stdio.h>

int			main(int argc, char **argv)
{
	int			fd;
	t_hub		hub;
	
	//DEBUG

	t_matrix m;
	
	init_matrix(m, 1);

	t_vector v1;
	v1.x = 3;
	v1.y = 4;
	v1.z = 5;

	t_vector v2;
	v2.x = 4;
	v2.y = 5;
	v2.z = 6;

	scale(m, v2);	
	translate(m, v1);
	print_matrix(m);

	return(0);

	//END DEBUG

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
