/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:58:13 by hbally            #+#    #+#             */
/*   Updated: 2018/12/08 09:39:17 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"

void					matrix_translate(t_matrix m, float x, float y, float z)
{
	t_matrix 			translate;

	matrix_init(translate, 1);
	if (x)
		translate[3][0] = x;
	if (y)
		translate[3][1] = y;
	if (z)
		translate[3][2] = z;
	matrix_mul(m, translate);
}

void					matrix_scale(t_matrix m, float x, float y, float z)
{
	t_matrix			scale;

	matrix_init(scale, 1);
	if (x)
		scale[0][0] = x;
	if (y)
		scale[1][1] = y;
	if (z)
		scale[2][2] = z;
	matrix_mul(m, scale);
}

void					matrix_rotate(t_matrix m,
		double theta_x, double theta_y, double theta_z)
{
	if (theta_x != 0)
		matrix_rotate_x(m, theta_x);
	if (theta_y != 0)
		matrix_rotate_y(m, theta_y);
	if (theta_z != 0)
		matrix_rotate_z(m, theta_z);
}
