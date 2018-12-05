/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:45:30 by hbally            #+#    #+#             */
/*   Updated: 2018/12/06 00:07:28 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "fdf.h"

typedef float		t_matrix[4][4];
extern const		t_matrix g_identity;
extern const		t_matrix g_empty;
void				rotate_x(t_matrix m, double theta);
void				rotate_y(t_matrix m, double theta);
void				rotate_z(t_matrix m, double theta);

#endif
