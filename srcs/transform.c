/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:45:28 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 11:08:58 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"

void				transform_build(t_transform *t)
{
	t_matrix		m;

	matrix_init(m);
	matrix_rotate(m, t->rotate_x, t->rotate_y, t->rotate_z);
	matrix_scale(m, t->scale_x, t->scale_y, t->scale_z);
	matrix_translate(m, t->translate_x, t->translate_y, t->translate_z);
	matrix_copy(t->matrix, m);
}

void				transform_build_world(t_transform *t)
{
	t_matrix		m;

	matrix_init(m);
	matrix_translate(m, t->translate_x, t->translate_y, t->translate_z);
	matrix_rotate(m, t->rotate_x, t->rotate_y, t->rotate_z);
	matrix_scale(m, t->scale_x, t->scale_y, t->scale_z);
	matrix_copy(t->matrix, m);
}

void				transform_apply(t_transform *t,
					t_vector **points, int width, int height)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			vect_mat_mul(&(points[i][j]), t->matrix);
			j++;
		}
		i++;
	}
}
