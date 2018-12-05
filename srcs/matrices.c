/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:28:57 by hbally            #+#    #+#             */
/*   Updated: 2018/12/05 23:45:01 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrices.h"

void					matrix_copy(t_matrix m1, const t_matrix m2)
{
	int 				i;
	int					j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;	
		while (j < 4)
		{
			m1[i][j] = m2[i][j];	
			j++;
		}
		i++;
	}
}

void					matrix_mul(t_matrix m1, const t_matrix m2)
{
	int					i;
	int					j;
	int					k;
	t_matrix			m3;

	i = 0;
	j = 0;
	k = 0;
	matrix_copy(m3, g_empty);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	matrix_copy(m1, m3);
}
