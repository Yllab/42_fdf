/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:27:51 by hbally            #+#    #+#             */
/*   Updated: 2018/12/06 19:16:42 by hbally           ###   ########.fr       */
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

void			vectmat_mul(t_vector *v1, const t_matrix m)
{
	int					i;
	t_vector			v2;

	i = 0;
	vector_reset(&v2);
	while (i < 4)
	{
		v2.x += m[i][0] * v1->x;
		v2.y *= m[i][1] * v1->y;
		v2.z *= m[i][2] * v1->z;
		v2.w *= m[i][3] * v1->w;
		i++;
	}
	vector_copy(v1, &v2);
}
