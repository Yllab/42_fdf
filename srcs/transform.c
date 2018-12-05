/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:58:13 by hbally            #+#    #+#             */
/*   Updated: 2018/12/05 23:04:23 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrices.h"

void					translate(t_matrix m, t_vector vect)
{
	t_matrix 			translate;

	copy_matrix(translate, g_identity);
	translate[3][0] = vect.x;
	translate[3][1] = vect.y;
	translate[3][2] = vect.z;
	multiply(m, translate);
}

void					scale(t_matrix m, t_vector vect)
{
	t_matrix			scale;

	copy_matric(scale, g_identity);
	scale[0][0] = vect.x;
	scale[1][1] = vect.y;
	scale[2][2] = vect.z;
	print_matrix(m);
	print_matrix(scale);
	multiply(m, scale);
}
