/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:25:53 by hbally            #+#    #+#             */
/*   Updated: 2018/12/05 23:03:37 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# define BUFF_SIZE 32

typedef float	 	t_matrix[4][4];

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vector;

typedef struct		s_map
{
	t_vector		**points;
	int				width;
	int				height;
	int				zoom;
	int				move_y;
	int				move_x;
}					t_map;

typedef struct		s_win
{
	void			*self_id;
	void			*mlx_id;	
	int				w;
	int				h;
}					t_win;

typedef struct		s_img
{
	void			*self_id;
	char			*data;
	int				bpp;
	int				line_size;
	int				endian;
	int				color;
}					t_img;

typedef struct		s_hub
{
	t_win			*win;
	t_img			*img;
	t_map			*map;
}					t_hub;

int					get_next_line(const int fd, char **line);

t_map				*build_map(int fd);
t_list				*get_input(int fd, t_map *map);
void				start_window(t_hub *hub);
void 				draw_line(t_img *img, t_vector p1, t_vector p2);
int					key_hook2(int keycode, void *param);

//DEBUG
void					matrix_print(t_matrix m);
void					matrix_mul(t_matrix m1, t_matrix m2);
void					matrix_copy(t_matrix m1, t_matrix m2);

void					scale(t_matrix m, t_vector vect);
void					translate(t_matrix m, t_vector t);

#endif
