/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:07:40 by nnovikov          #+#    #+#             */
/*   Updated: 2018/11/25 20:01:33 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	print_map(t_table *map)
{
	int i;

	i = 0;
	while (i < map->map_size)
	{
		ft_putstr(map->map[i]);
		ft_putstr("\n");
		i++;
	}
}

int		main(int ac, char **av)
{
	t_list		*list;
	t_table		*map;
	int			fd;
	int			count;
	char		letter;

	if (ac == 2)
	{
		count = 0;
		letter = 'A';
		fd = open(av[1], O_RDONLY);
		if (!(list = read_from_file(fd, count, letter)))
			error();
		ft_lstrev(&list);
		map = solve(ft_lstcount(list), list);
		print_map(map);
		free_map(map);
		free_list(list);
	}
	else
	{
		ft_putstr("usage: ./fillit test_file\n");
		exit(1);
	}
	KWAAK;
}
