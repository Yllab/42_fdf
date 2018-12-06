/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:45:30 by hbally            #+#    #+#             */
/*   Updated: 2018/12/06 17:14:05 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef float		t_matrix[4][4];

//debug
void				matrix_print(t_matrix m);

extern const		t_matrix g_identity;
extern const		t_matrix g_empty;

void				rotate_x(t_matrix m, double theta);
void				rotate_y(t_matrix m, double theta);
void				rotate_z(t_matrix m, double theta);

void				matrix_mul(t_matrix m1, const t_matrix m2);
void				matrix_copy(t_matrix m1, const t_matrix m2);
void				matrix_inv(t_matrix m1);

#endif
