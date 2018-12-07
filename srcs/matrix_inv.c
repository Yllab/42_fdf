/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:19:21 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 14:41:04 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "matrix.h"
#include "math.h"

static void				row_swap(t_matrix m1, int i, int j)
{
	t_matrix			swap;
	int					k;

	matrix_copy(swap, m1);
	k = 0;
	while (k < 4)
	{
		m1[i][k] = swap[j][k];
		m1[j][k] = swap[i][k];
		k++;
	}
}

static void				set_pivot(t_matrix m1, t_matrix m2)
{
	int					i;
	int					j;
	int					max;

	i = 0;
	while (i < 4)
	{
		if (m1[i][i] == 0)
		{
			max = i;
			j = 0;
			while (j < 4)
			{
				if (fabs((double)m1[j][i]) > fabs((double)m1[max][i]))
					max = j;
				j++;
			}
			if (max == i)
				exit(1);
			row_swap(m1, i, max);
			row_swap(m2, i, max);
		}
		i++;
	}
}

static void				set_zero(t_matrix m1, t_matrix m2, int i)
{
	int					j;
	int					k;
	float				coeff;

	j = 0;
	while (j < 4)
	{
		if (j != i)
		{
			coeff = m1[j][i];
			k = 0;
			while (k < 4)
			{
				m1[j][k] -= coeff * m1[i][k];
				m2[j][k] -= coeff * m2[i][k];
				k++;
			}
		}
		j++;
	}
}

static void				set_one(t_matrix m1, t_matrix m2, int i)
{
	int 				j;
	float 				pivot;

	pivot = m1[i][i];
	if (pivot != 1)
	{
		j = 0;
		while (j < 4)
		{
			m1[i][j] /= pivot;
			m2[i][j] /= pivot;
			j++;
		}
	}
}

void					matrix_inv(t_matrix m1)
{
	t_matrix			m2;
	int					i;

	matrix_init(m2, 1);
	set_pivot(m1, m2);
	i = 0;
	while (i < 4)
	{
		set_one(m1, m2, i);
		set_zero(m1, m2, i);
		i++;
	}
	matrix_copy(m1, m2);
}
