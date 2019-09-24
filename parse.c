/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:12:33 by nnovikov          #+#    #+#             */
/*   Updated: 2018/11/26 12:42:29 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_table		*create_map(int size)
{
	t_table	*new;
	int		i;
	int		j;

	i = 0;
	if (!(new = ft_memalloc(sizeof(t_table))))
		return (NULL);
	new->map_size = size;
	new->map = ft_memalloc(sizeof(char *) * (size + 1));
	new->letter = SPACE;
	while (i < size)
	{
		new->map[i] = ft_memalloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
		{
			new->map[i][j] = new->letter;
			j++;
		}
		i++;
	}
	return (new);
}

t_table		*define_dot(int x, int y)
{
	t_table	*new;

	new = ft_memalloc(sizeof(t_table));
	new->x = x;
	new->y = y;
	return (new);
}

void		define_mm(char *buf, t_table *min, t_table *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (buf[i] == BLOCK)
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_table		*get_tetremino(char *buf, char letter)
{
	t_table	*min;
	t_table	*max;
	t_table	*tetromino;
	char	**arr;
	int		i;

	min = define_dot(3, 3);
	max = define_dot(0, 0);
	define_mm(buf, min, max);
	arr = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		arr[i] = ft_memalloc(max->x - min->x + 2);
		ft_strncpy(arr[i], buf + min->x + (i + min->y) * 5,
										max->x - min->x + 1);
		i++;
	}
	tetromino = ft_memalloc(sizeof(t_table));
	tetromino->arr = arr;
	tetromino->widht = max->x - min->x + 1;
	tetromino->height = max->y - min->y + 1;
	tetromino->letter = letter;
	return (tetromino);
}

t_list		*read_from_file(int fd, int count, char letter)
{
	char	*buf;
	t_list	*list;
	t_table	*tetromino;
	int		ret;
	int		prev_ret;

	list = NULL;
	buf = ft_memalloc(SIZE + 1);
	while ((ret = read(fd, buf, SIZE)) >= SIZE - 1)
	{
		prev_ret = ret;
		if (!(check_newlines(buf)) || !(check_range(count + 1)) ||
				!(check_connections(buf)) || !(check_char(buf, ret)))
			return (NULL);
		tetromino = get_tetremino(buf, letter);
		ft_lstadd(&list, ft_lstnew(tetromino, sizeof(t_table)));
		free(tetromino);
		letter++;
		count++;
	}
	if ((ret == 0 && prev_ret == SIZE) || ret != 0)
		return (NULL);
	free(buf);
	return (list);
}
