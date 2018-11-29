/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:47:24 by hbally            #+#    #+#             */
/*   Updated: 2018/11/29 20:23:46 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static int		get_row(char *line, int **result)
{
	int			i;
	char		**split_result;
	static int	row_size;

	split_result = ft_strsplit(line, ' ');
	if (split_result)
	{
		ft_putstr("HO\n");
		i = 0;
		while (split_result[i] != NULL)
			i++;
		if (!row_size)
			row_size = i;
		else if (row_size != i)
			return (-1);
		*result = ft_memalloc(row_size);
		i = 0;
		if (result)
			while (*split_result != NULL)
				(*result)[i++] = ft_atoi(*(split_result++));
		else
			return (-1);
		return (row_size);
	}
	return (-1);
}

t_list			*get_input(int fd)
{
	t_list	*map_raw;
	char 	*line;
	int		ret;
	int		*row;
	int		size;

	map_raw = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr("HEY\n");
		size = get_row(line, &row);
		if (size == -1)
			return (NULL);
		if (!map_raw)
			map_raw = ft_lstnew(row, size);
		else
			ft_lstadd(&map_raw, ft_lstnew(row, size));
		if (!map_raw)
			return (NULL);
	}
	if (ret == -1)
	   return (NULL);
	return (map_raw);	
}
