/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:02:51 by nnovikov          #+#    #+#             */
/*   Updated: 2018/11/25 18:41:46 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BLOCK '#'
# define SPACE '.'
# define SIZE 21
# define MEOW return (1)
# define BARK return (-1)
# define KWAAK return (0)

typedef struct		s_list
{
	int				content_size;
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_table
{
	int				height;
	int				widht;
	char			letter;
	char			**arr;
	int				map_size;
	char			**map;
	int				x;
	int				y;
}					t_table;

char				*ft_strnew(size_t size);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				*ft_memcpy(void *dst, const void *src, size_t n);

char				*ft_strncpy(char *dst, const char *src, size_t len);

void				ft_putstr(char const *s);

void				*ft_memalloc(size_t size);

void				*ft_memset(void *b, int c, size_t len);

void				error(void);

void				free_tetromino(t_table *tetromino);

t_list				*free_list(t_list *list);

int					ft_lstcount(t_list *list);

int					sq(int nb);

void				free_map(t_table *map);

t_table				*define_dot(int x, int y);

t_table				*create_map(int size);

void				print_map(t_table *map);

void				ft_lstrev(t_list **alst);

t_table				*solve(int tet, t_list *list);

void				define_mm(char *buf, t_table *min, t_table *max);

int					check_char(char *str, int ret);

int					check_connections(char *str);

int					check_range(int count);

int					check_newlines(char *tetrimino);

t_table				*get_tetremino(char *buf, char letter);

void				ft_lstadd(t_list **alst, t_list *new);

t_list				*ft_lstnew(void const *content, size_t content_size);

t_list				*read_from_file(int fd, int count, char letter);

void				place_tetr(t_table *tetromino, t_table *map, int x, int y);

void				del_tetr(t_table *tetromino, t_table *map, int x, int y);

int					is_place(t_table *tetromino, t_table *map, int i, int j);

int					fillit(t_table *map, t_list *list);

#endif
