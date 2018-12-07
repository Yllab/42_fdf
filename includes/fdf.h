/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:25:53 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 19:45:30 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "types.h"

# define BUFF_SIZE 32

//DEBUG

# include <stdio.h>
void				vector_print(t_vector *v);
void				matrix_print(t_matrix m);

//END DEBUG

int					get_next_line(const int fd, char **line);

t_map				*build_map(int fd);
t_list				*get_input(int fd, t_map *map);
void				start_window(t_hub *hub);
void 				draw_line(t_img *img, t_vector p1, t_vector p2);
int					key_hook2(int keycode, void *param);

void				vector_reset(t_vector *v);
void				vector_copy(t_vector *v1, const t_vector *v2);
void				vect_mat_mul(t_vector *v1, const t_matrix m);

void				transform_apply(t_transform *t,
					t_vector **points, int width, int height);
void				transform_build(t_transform *t);
#endif
