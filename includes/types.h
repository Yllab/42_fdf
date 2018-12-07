/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:14:51 by hbally            #+#    #+#             */
/*   Updated: 2018/12/07 18:57:32 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

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
	t_transform		transform;
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
	t_win			win;
	t_img			img;
	t_map			*map;
}					t_hub;

#endif
