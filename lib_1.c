/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:04:10 by nnovikov          #+#    #+#             */
/*   Updated: 2018/11/25 18:50:44 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	i = -1;
	str = b;
	while (++i < len)
		str[i] = c;
	return (b);
}

void	*ft_memalloc(size_t size)
{
	void	*area;

	if (!size)
		return (NULL);
	if (!(area = malloc(size)))
		return (NULL);
	else
		return (ft_memset(area, '\0', size));
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned long	i;

	i = 0;
	while (i < len)
	{
		if (src[i])
		{
			dst[i] = src[i];
		}
		else
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
		i++;
	}
	return (dst);
}

void	ft_putstr(char const *s)
{
	int i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;
	size_t	i;

	i = -1;
	pdst = dst;
	psrc = (char *)src;
	while (++i < n)
		pdst[i] = psrc[i];
	return (dst);
}
