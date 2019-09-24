/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:24:45 by nnovikov          #+#    #+#             */
/*   Updated: 2018/11/25 19:18:00 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_tetr(t_table *tetromino, t_table *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetromino->height)
	{
		j = 0;
		while (j < tetromino->widht)
		{
			if (tetromino->arr[i][j] == BLOCK)
				map->map[x + i][y + j] = map->letter;
			j++;
		}
		i++;
	}
}

void	place_tetr(t_table *tetromino, t_table *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetromino->height)
	{
		j = 0;
		while (j < tetromino->widht)
		{
			if (tetromino->arr[i][j] == BLOCK)
				map->map[x + i][y + j] = tetromino->letter;
			j++;
		}
		i++;
	}
}

int		is_place(t_table *tetromino, t_table *map, int i, int j)
{
	int		x;
	int		y;

	x = 0;
	while (x < tetromino->height)
	{
		y = 0;
		while (y < tetromino->widht)
		{
			if (tetromino->arr[x][y] == BLOCK &&
					map->map[x + i][y + j] != SPACE)
				KWAAK;
			y++;
		}
		x++;
	}
	place_tetr(tetromino, map, i, j);
	MEOW;
}

int		fillit(t_table *map, t_list *list)
{
	int		i;
	int		j;
	t_table	*tetromino;

	if (list == NULL)
		MEOW;
	tetromino = (t_table *)list->content;
	i = 0;
	while (i <= map->map_size - tetromino->height)
	{
		j = 0;
		while (j <= map->map_size - tetromino->widht)
		{
			if (is_place(tetromino, map, i, j))
			{
				if (fillit(map, list->next))
					MEOW;
				else
					del_tetr(tetromino, map, i, j);
			}
			j++;
		}
		i++;
	}
	KWAAK;
}

t_table	*solve(int tet, t_list *list)
{
	t_table	*solved_map;

	solved_map = create_map(sq(tet * 4));
	while (!fillit(solved_map, list))
	{
		tet++;
		free_map(solved_map);
		solved_map = create_map(sq(tet * 4));
	}
	return (solved_map);
}
