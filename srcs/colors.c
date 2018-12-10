/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:37:57 by hbally            #+#    #+#             */
/*   Updated: 2018/12/10 18:54:01 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>
#include <types.h>

int				find_color(t_vector point)
{
	if (point.level == 1)
		return (PASTEL_DARK_BLUE);
	if (point.level == 2)
		return (PASTEL_BLUE);
	if (point.level > 2 && point.level <= 5)
		return (MEDIUM_GRAY);
	if (point.level > 50)
		return (PASTEL_RED);
	return (MEDIUM_GRAY);
}
