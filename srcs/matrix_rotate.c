/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:54:20 by hbally            #+#    #+#             */
/*   Updated: 2018/12/09 18:52:30 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "matrix.h"

void			matrix_rotate_x(t_matrix m, double theta)
{
	t_matrix	r;

	matrix_init(r);
	r[1][1] = (float)cos(theta);
	r[1][2] = (float)sin(theta);
	r[2][1] = (float)-sin(theta);
	r[2][2] = (float)cos(theta);
	matrix_mul(m, r);
}

void			matrix_rotate_y(t_matrix m, double theta)
{
	t_matrix	r;

	matrix_init(r);
	r[0][0] = (float)cos(theta);
	r[0][2] = (float)-sin(theta);
	r[2][0] = (float)sin(theta);
	r[2][2] = (float)cos(theta);
	matrix_mul(m, r);
}

void			matrix_rotate_z(t_matrix m, double theta)
{
	t_matrix	r;

	matrix_init(r);
	r[0][0] = (float)cos(theta);
	r[0][1] = (float)sin(theta);
	r[1][0] = (float)-sin(theta);
	r[1][1] = (float)cos(theta);
	matrix_mul(m, r);
}
