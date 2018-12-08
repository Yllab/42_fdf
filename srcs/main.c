/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/08 11:18:26 by hbally           ###   ########.fr       */
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
			//DEBUG
			t_matrix m;
			t_vector v;
			v.x = 2;
			v.y = 2;
			v.z = 2;
			matrix_init(m, 1);
			matrix_rotate(m, -(M_PI / 3), 0, 0);
			vect_mat_mul(&v, m);
			vector_print(&v);
			matrix_init(m, 1);
			matrix_rotate_y(m, -(M_PI / 2));
			v.x = 2;
			v.y = 2;
			v.z = 2;
			vect_mat_mul(&v, m);
			vector_print(&v);
			return (0);
			//END DEBUG
			if (hub.map)
				start_window(&hub);
		}
	}
	return (0);
}
