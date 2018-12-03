/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:39:50 by hbally            #+#    #+#             */
/*   Updated: 2018/12/03 15:43:50 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			key_hook(int keycode, void *param)
{
	t_vector	p1;
	t_vector	p2;

	if (keycode == 125)
	{
		draw_line_pilot(p1, p2, ((t_hub*)param)->img);
		mlx_put_image_to_window(((t_hub*)param)->win->mlx_id,
								((t_hub*)param)->win->self_id,
								((t_hub*)param)->img->self_id, 0, 0);
	}
	return (0);
}
