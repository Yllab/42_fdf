/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:14:51 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 18:21:42 by hbally           ###   ########.fr       */
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
	double			alti;
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
	int				scale;
	double			min_y;
	double			max_y;
}					t_map;

typedef struct		s_camera
{
	t_transform		t;
	int				proj;
	float			canvas;
	float			speed;
	int				fullrender;
	int				autorotate;
	float			iso_depth;
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
** Image drawing
*/

typedef struct		s_img
{
	void			*self_id;
	char			*data;
	int				win_width;
	int				win_height;
	int				bpp;
	int				line_size;
	int				endian;
	int				night_mode;
	int				background_color;
	int				show_ui;
}					t_img;

typedef struct		s_line
{
	t_vector		*start;
	t_vector		*end;
}					t_line;

typedef struct		s_ui
{
	int				color;
	int				a_x;
	int				a_y;
	int				line;
	int				line_increment;
}					t_ui;

typedef struct		s_theme
{
	int				deep_sea;
	int				sea;
	int				plains_low;
	int				plains_high;
	int				mountain_low;
	int				mountain_high;
}					t_theme;

/*
** Main access structure
*/

typedef struct		s_hub
{
	t_win			win;
	t_img			img;
	t_camera		camera;
	t_theme			theme;
	t_map			*map;
}					t_hub;

#endif
