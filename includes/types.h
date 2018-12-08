/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:14:51 by hbally            #+#    #+#             */
/*   Updated: 2018/12/08 17:03:36 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/*
** Transformation matrix builder
*/

typedef float		t_matrix[4][4];

typedef struct		s_transform
{
	double			rotate_x;
	double			rotate_y;
	double			rotate_z;
	float			scale_x;
	float			scale_y;
	float			scale_z;
	float			translate_x;
	float			translate_y;
	float			translate_z;
	t_matrix		matrix;
}					t_transform;

/*
** Vect4 with w parameter (1 = point, 0 = vector)
*/

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
	float			w;
	int				color;//
}					t_vector;

/*
** Objects in the scene + Transform
*/

typedef struct		s_map
{
	t_transform		t;
	t_vector		**points;
	int				width;
	int				height;
}					t_map;

typedef struct		s_camera
{
	t_transform		t;
	float			canvas_w;
	float			canvas_h;
	int				win_w;
	int				win_h;
}					t_camera;

/*
** Window management
*/

typedef struct		s_win
{
	void			*self_id;
	void			*mlx_id;	
}					t_win;

/*
** Rendered image storage
*/

typedef struct		s_img
{
	void			*self_id;
	char			*data;
	int				bpp;
	int				line_size;
	int				endian;
	int				color;
}					t_img;

/*
** Main access structure
*/

typedef struct		s_hub
{
	t_win			win;
	t_img			img;
	t_camera		camera;
	t_map			*map;
}					t_hub;

#endif
