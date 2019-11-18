# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttampio <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 08:37:30 by ttampio           #+#    #+#              #
#    Updated: 2019/11/18 19:54:01 by ttampio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = fillit.c ft_read_input.c ft_err_and_exit.c ft_pack_tetr.c \
	  ft_grow_grid.c ft_return_minimum_grid.c ft_print_grid.c \
	  ft_pack_tetr_hlprs.c ft_create_tet_struct.c

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	@make -C libft/
	$(CC) -c $(SRC) -I libft/ $(CFLAGS)
	$(CC) -o $(NAME) $(OBJ) -L libft/ -lft $(CFLAGS)

clean:
	/bin/rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft/ fclean

re : fclean all

.PHONY: all clean fclean re
