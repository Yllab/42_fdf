/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:25:53 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 11:23:05 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "types.h"

# define BUFF_SIZE 32

//DEBUG

# include <stdio.h>
# include <stdlib.h>
void				vector_print(t_vector *v);
void				matrix_print(t_matrix m);

//END DEBUG

t_map				*build_map(int fd);
t_list				*get_input(int fd, t_map *map);
int					get_next_line(const int fd, char **line);

void				start_window(t_hub *hub);
int					keyboard_hooks(int keycode, void *param);
int					loop_hook(void *param);

void				vector_reset(t_vector *v);
void				vect_mat_mul(t_vector *v1, const t_matrix m);

void				transform_build(t_transform *t);
void				transform_build_world(t_transform *t);
void				transform_apply(t_transform *t,
									t_vector **points,
									int width,
									int height);

void				startup_scene(t_hub *hub);
void				startup_camera(t_camera *camera, t_map *map);
void				reset_canvas(t_camera *camera, t_map *map);

void				transform_map(t_map *map,
									float delta_elevation,
									float delta_scale);

void				map_assign_alti(t_map *map,
										int granularity);

void				render(t_hub *hub);
void				world_to_screen(t_hub *hub);
void				draw_line(t_hub *hub, t_vector p1, t_vector p2);

int					find_color(t_vector point);
int					pixel_color(t_hub *hub, t_line *line, int x, int y);
void				img_set_background(t_img *img);

void				draw_ui(t_img *img, t_win *win);

#endif
