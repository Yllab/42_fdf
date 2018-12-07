/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:01:46 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 13:15:25 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void					matrix_print(t_matrix m)
{
	int					i;
	int					j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			printf("%*f%c", 5, m[i][j], j != 3 ? ' ' : '\n');
	}
	printf("______________\n");
}

void					vector_print(t_vector *v)
{
	printf("x = %f ", v->x);
	printf("y = %f ", v->y);
	printf("z = %f ", v->z);
	printf("w = %f\n", v->w);
}
