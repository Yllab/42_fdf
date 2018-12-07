/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:45:30 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 18:25:17 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "types.h"

void				matrix_init(t_matrix m, int identity);
void				matrix_copy(t_matrix m1, const t_matrix m2);

void				matrix_mul(t_matrix m1, const t_matrix m2);
void				matrix_inv(t_matrix m1);
void				matrix_apply(t_matrix m,
					t_vector **points, int width, int height);

void				matrix_rotate_x(t_matrix m, double theta);
void				matrix_rotate_y(t_matrix m, double theta);
void				matrix_rotate_z(t_matrix m, double theta);
void				matrix_rotate(t_matrix m,
					double theta_x, double theta_y, double theta_z);
void				matrix_translate(t_matrix m, float x, float y, float z);
void				matrix_scale(t_matrix m, float x, float y, float z);

#endif
