/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 21:09:10 by hbally            #+#    #+#             */
/*   Updated: 2018/12/16 00:08:36 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "types.h"

# define DARK_GRAY 0x212121
# define MEDIUM_GRAY 0x515151
# define GRAY 0x8F8F8F
# define LIGHT_GRAY 0xF5F5F5
# define PASTEL_WHITE 0xDFD8D1
# define PASTEL_PINK 0xF66666
# define PASTEL_AZURE 0xA7DFDC
# define PASTEL_YELLOW 0xF0D38C

void		theme_purple(t_theme *theme);
void		theme_cafe(t_theme *theme);
void		theme_red(t_theme *theme);
void		theme_pink(t_theme *theme);
void		theme_catalog(t_theme *theme);

#endif
