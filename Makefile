# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 18:22:20 by nnovikov          #+#    #+#              #
#    Updated: 2018/11/26 16:58:39 by tprokysh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

DIR = objects

FLAGS = -Wall -Wextra -Werror

SRC_C = main.c lib_1.c lib_2.c parse.c set_them_free.c solve.c validation.c

SRC_O = $(addprefix objects/,$(SRC_C:.c=.o))

$(DIR)/%.o: %.c 
	@gcc $(FLAGS) -o $@ -c $<

all: $(NAME)

$(DIR):
	@mkdir -p $(DIR)

$(NAME): $(DIR) $(SRC_O)
	@gcc -o $(NAME) $(SRC_O) $(FLAGS)

clean:
	@/bin/rm -rf objects

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
