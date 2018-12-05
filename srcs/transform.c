/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:58:13 by hbally            #+#    #+#             */
/*   Updated: 2018/12/05 23:45:16 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrices.h"

void					translate(t_matrix m, t_vector vect)
{
	t_matrix 			translate;

	matrix_copy(translate, g_identity);
	translate[3][0] = vect.x;
	translate[3][1] = vect.y;
	translate[3][2] = vect.z;
	matrix_mul(m, translate);
}

void					scale(t_matrix m, t_vector vect)
{
	t_matrix			scale;

	matrix_copy(scale, g_identity);
	scale[0][0] = vect.x;
	scale[1][1] = vect.y;
	scale[2][2] = vect.z;
	matrix_mul(m, scale);
}
