/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_const.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:27:14 by hbally            #+#    #+#             */
/*   Updated: 2018/12/06 00:03:30 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "matrices.h"

const t_matrix g_identity =
{
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
};

const t_matrix g_empty =
{
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}
};

void	rotate_x(t_matrix m, double theta)
{
	matrix_copy(m, g_identity);
	m[1][1] = (float)cos(theta);
	m[1][2] = (float)sin(theta);
	m[2][1] = (float)-sin(theta);
	m[2][2] = (float)cos(theta);
}

void	rotate_y(t_matrix m, double theta)
{
	matrix_copy(m, g_identity);
	m[0][0] = (float)cos(theta);
	m[0][2] = (float)-sin(theta);
	m[2][0] = (float)sin(theta);
	m[2][2] = (float)cos(theta);
}

void	rotate_z(t_matrix m, double theta)
{
	matrix_copy(m, g_identity);
	m[0][0] = (float)cos(theta);
	m[0][1] = (float)sin(theta);
	m[1][0] = (float)-sin(theta);
	m[1][1] = (float)cos(theta);
}
