/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/11/30 13:23:51 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"

#include "mlx.h"

int			main(int argc, char **argv)
{
	int		fd;
	void	*id;
	t_list	*map;
	
	if (argc != 2)
		return (0);	

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);

	id = mlx_init();
	if (!id)
		return (0);
	map = get_input(fd);

	return (0);
}
