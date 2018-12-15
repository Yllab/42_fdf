/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:32 by hbally            #+#    #+#             */
/*   Updated: 2018/12/15 14:43:10 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"

int			main(int argc, char **argv)
{
	int			fd;
	t_hub		hub;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			ft_bzero(&hub, sizeof(t_hub));
			build_map(fd, &hub);
			start_window(&hub);
		}
		else
			fdf_input_exit(NULL, NULL,
								"Map does not exist or could not be read.");
	}
	else
	{
		ft_putendl("Usage : fdf [map.fdf]");
		ft_putstr("(Note : map.fdf should contain only integers separated");
		ft_putstr(" by a single space. Map must be rectangular.)\n");
		return (0);
	}
}
