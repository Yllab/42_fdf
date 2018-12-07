/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:45:30 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 14:50:40 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef float		t_matrix[4][4];

void				rotate_x(t_matrix m, double theta);
void				rotate_y(t_matrix m, double theta);
void				rotate_z(t_matrix m, double theta);

void				matrix_init(t_matrix m, int identity);
void				matrix_mul(t_matrix m1, const t_matrix m2);
void				matrix_copy(t_matrix m1, const t_matrix m2);
void				matrix_inv(t_matrix m1);
void				rotate(t_matrix m,
					double theta_x, double theta_y, double theta_z)

#endif
