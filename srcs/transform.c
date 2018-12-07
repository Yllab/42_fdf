/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:58:13 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 14:38:10 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"

void					translate(t_matrix m, t_vector vect)
{
	t_matrix 			translate;

	matrix_init(translate, 1);
	translate[3][0] = vect.x;
	translate[3][1] = vect.y;
	translate[3][2] = vect.z;
	matrix_mul(m, translate);
}

void					scale(t_matrix m, t_vector vect)
{
	t_matrix			scale;

	matrix_init(scale, 1);
	scale[0][0] = vect.x;
	scale[1][1] = vect.y;
	scale[2][2] = vect.z;
	matrix_mul(m, scale);
}
