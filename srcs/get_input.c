/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:47:24 by hbally            #+#    #+#             */
/*   Updated: 2018/12/10 14:29:29 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static	void	ft_tabfree(char **tab, int i)
{
	while (i--)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}

static int		tab_len(char **tab)
{
	static int	row_count;
	static int	len;
	int			i;

	ft_putstr("Loading - Line ");
	ft_putnbr(row_count++);
	ft_putstr("\n");
	i = 0;
	while (tab[i] != NULL)
		i++;
	if (!len)
		len = i;
	else if (len != i)
		return (0);
	return (len);
}

static void		free_row(void *row, size_t row_size)
{
	ft_memdel(&row);
	row_size = 0;
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
		*result = (int*)ft_memalloc(len * sizeof(int));
		if (result)
		{
			i = 0;
			while (split_result[i] != NULL)
			{
				*(*result + i) = ft_atoi(split_result[i]);
				i++;
			}
			ft_tabfree(split_result, len - 1);
			return (len);
		}
	}
	ft_tabfree(split_result, len - 1);
	return (0);
}

t_list			*get_input(int fd, t_map *map)
{
	t_list		*origin;
	t_list		*map_raw;
	char		*line;
	int			*row;
	int			ret;

	map_raw = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		map->width = get_row(line, &row);
		if (map->width < 1)
			return (NULL);
		origin = map_raw;
		if (!map_raw)
			map_raw = ft_lstnew((int*)row, sizeof(int) * map->width);
		else
			ft_lstadd(&map_raw, ft_lstnew((int*)row, sizeof(int) * map->width));
		if (!map_raw)
		{
			ft_lstdel(&origin, &free_row);
			return (NULL);
		}
		map->height++;
	}
	return (ret == -1 ? NULL : map_raw);
}
