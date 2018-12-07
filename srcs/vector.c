/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:27:51 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 14:48:28 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			vector_reset(t_vector *v)
{
	if (v)
	{
		v->x = 0;
		v->y = 0;
		v->z = 0;
		v->w = 0;
	}
}

void			vector_copy(t_vector *v1, const t_vector *v2)
{
	if (v1 && v2)
	{
		v1->x = v2->x;
		v1->y = v2->y;
		v1->z = v2->z;
		v1->w = v2->w;
	}
}

void			vect_mat_mul(t_vector *v1, const t_matrix m)
{
	t_vector v2;

	vector_copy(&v2, v1);
	v1->x = v2.x * m[0][0] + v2.y * m[1][0] + v2.z * m[2][0] + v2.w * m[3][0];
	v1->y = v2.x * m[0][1] + v2.y * m[1][1] + v2.z * m[2][1] + v2.w * m[3][1];
	v1->z = v2.x * m[0][2] + v2.y * m[1][2] + v2.z * m[2][2] + v2.w * m[3][2];
	v1->w = v2.x * m[0][3] + v2.y * m[1][3] + v2.z * m[2][3] + v2.w * m[3][3];
}