/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:47:24 by hbally            #+#    #+#             */
/*   Updated: 2018/11/30 13:21:27 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

// TODO ERROR

static int		tab_len(char **tab)
{
	static int	len;
	int			i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	if (!len)
		len = i;
	else if (len != i)
		return (0);
	return (len);
}

static int		get_row(char *line, int **result)
{
	int			i;
	int			len;
	char		**split_result;

	split_result = ft_strsplit(line, ' ');
	len = tab_len(split_result);
	if (split_result && len)
	{
		*result = ft_memalloc(len * sizeof(int));
		if (!result)
			return (-1);
		i = 0;
		while (split_result[i] != NULL)
		{
			*(*result + i) = ft_atoi(split_result[i]);
			i++;
		}
		return (len);
	}
	return (-1);
}

t_list			*get_input(int fd)
{
	t_list	*map;
	char	*line;
	int		*row;
	int		ret;
	int		size;

	map = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		size = get_row(line, &row);
		if (size == -1)
			return (NULL);
		if (!map)
			map = ft_lstnew((int*)row, sizeof(int) * size);
		else
			ft_lstadd(&map, ft_lstnew((int*)row, sizeof(int) * size));
		if (!map)
			return (NULL);
	}
	if (ret == -1 || map == NULL)
		return (NULL);
	return (map);
}
