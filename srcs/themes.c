/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   themes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:51:37 by hbally            #+#    #+#             */
/*   Updated: 2018/12/14 16:07:08 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void		theme_purple(t_theme *theme)
{
	theme->deep_sea = 0x422c6b;
	theme->sea = 0x503e8a;
	theme->plains_low = 0x5a5898;
	theme->plains_high = 0x6272af;
	theme->mountain_low = 0x7687af;
	theme->mountain_high = 0xACB7CF;
}

void		theme_cafe(t_theme *theme)
{
	theme->deep_sea = 0x3c2f2f;
	theme->sea = 0x4b3832;
	theme->plains_low = 0xbe9b7b;
	theme->plains_high = 0xfff4e6;
	theme->mountain_low = 0x854442;
	theme->mountain_high = 0x743a51;
}

void		theme_red(t_theme *theme)
{
	theme->deep_sea = 0x602320;
	theme->sea = 0xa32020;
	theme->plains_low = 0xe0301e;
	theme->plains_high = 0xeb8c00;
	theme->mountain_low = 0xdc6900;
	theme->mountain_high = 0xE6964C;
}

void		theme_pink(t_theme *theme)
{
	theme->deep_sea = 0xff084a;
	theme->sea = 0xfc3468;
	theme->plains_low = 0xff6289;
	theme->plains_high = 0xff93ac;
	theme->mountain_low = 0xffc2cd;
	theme->mountain_high = 0xFFE0E6;
}

void		theme_catalog(t_theme *theme)
{
	theme->deep_sea = 0x004046;
	theme->sea = 0x00a0b0;
	theme->plains_low = 0xedc951;
	theme->plains_high = 0xeb6841;
	theme->mountain_low = 0xcc2a36;
	theme->mountain_high = 0x4f372d;
}
