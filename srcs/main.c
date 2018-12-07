/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 14:49:20 by hbally           ###   ########.fr       */
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
	//DEBUG

	t_vector 	v;

	v.x = 5;
	v.y = 6;
	v.z = 7;
	v.w = 1;

	t_matrix m =
	{
		{0.718, 0.615, -0.324, 0},
		{-0.393, 0.744, 0.539, 0},
		{0.573, -0.259, 0.777, 0},
		{0.526, 1.254, -2.532, 1}
	};
	
	matrix_init(m, 1);
	matrix_rotate(m, 0, M_PI_2, 0);
	matrix_print(m);
	return (0);
	vect_mat_mul(&v, m);

	

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
	matrix_print(m);

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
