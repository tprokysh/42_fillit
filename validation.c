/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:10:31 by nnovikov          #+#    #+#             */
/*   Updated: 2018/11/25 19:04:30 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_newlines(char *tetrimino)
{
	int i;

	i = 4;
	while (i < SIZE - 1)
	{
		if (tetrimino[i] != '\n')
			KWAAK;
		i += 5;
	}
	if (tetrimino[SIZE] != '\n' && tetrimino[SIZE] != '\0')
		KWAAK;
	MEOW;
}

int		check_range(int count)
{
	if (count > 26 || count < 0)
		KWAAK;
	MEOW;
}

int		check_connections(char *str)
{
	int i;
	int count;
	int block;

	i = -1;
	count = 0;
	block = 0;
	while (str[++i])
	{
		if (str[i] == BLOCK)
		{
			if (str[i - 1] == BLOCK)
				count++;
			if (str[i + 1] == BLOCK)
				count++;
			if (str[i - 5] == BLOCK)
				count++;
			if (str[i + 5] == BLOCK)
				count++;
			block++;
		}
	}
	if ((count == 6 || count == 8) && block == 4)
		MEOW;
	KWAAK;
}

int		check_char(char *str, int ret)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i < ret - 1 && i % 5 < 4)
		{
			if (str[i] != BLOCK && str[i] != SPACE)
				KWAAK;
		}
		else
		{
			if (str[i] != '\n' && str[i] != '\0')
				KWAAK;
		}
		i++;
	}
	MEOW;
}
