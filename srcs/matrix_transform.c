/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:58:13 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 19:15:02 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"

void					matrix_translate(t_matrix m, float x, float y, float z)
{
	t_matrix 			translate;

	if (x || y || z)
	{
		matrix_init(translate, 1);
		translate[3][0] = x;
		translate[3][1] = y;
		translate[3][2] = z;
		matrix_mul(m, translate);
	}
}

void					matrix_scale(t_matrix m, float x, float y, float z)
{
	t_matrix			scale;

	if (x || y || z)
	{
		matrix_init(scale, 1);
		scale[0][0] = x;
		scale[1][1] = y;
		scale[2][2] = z;
		matrix_mul(m, scale);
	}
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
