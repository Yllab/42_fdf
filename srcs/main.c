/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/06 19:14:22 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
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

	v.x = 0.5;
	v.y = 0.5;
	v.z = 0.5;
	v.w = 1;

	t_matrix m =
	{
		{0.718, 0.615, -0.324, 0},
		{-0.393, 0.744, 0.539, 0},
		{0.573, -0.259, 0.777, 0},
		{0.526, 1.254, -2.532, 1}
	};

	vectmat_mul(&v, m);
	printf("x = %f\n", v.x);
	printf("y = %f\n", v.y);
	printf("z = %f\n", v.z);
	printf("w = %f\n", v.w);

	return (0);
	
	matrix_inv(m);
	matrix_print(m);

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
