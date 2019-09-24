/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_them_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:09:05 by nnovikov          #+#    #+#             */
/*   Updated: 2018/11/25 19:19:43 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tetromino(t_table *tetromino)
{
	int i;

	i = 0;
	while (i < tetromino->height)
	{
		free(tetromino->arr[i]);
		i++;
	}
	free(tetromino->arr);
	free(tetromino);
}

t_list	*free_list(t_list *list)
{
	while (list)
	{
		free_tetromino((t_table *)list->content);
		free(list);
		list = list->next;
	}
	return (NULL);
}

void	free_map(t_table *map)
{
	int i;

	i = 0;
	while (i < map->map_size)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}
