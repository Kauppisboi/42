# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 15:53:22 by jrignell          #+#    #+#              #
#    Updated: 2019/12/18 12:27:44 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXEC = ft_printf
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = ft_printf.c ft_parse_str_char_ptr.c main.c ft_parse_hh_ll_diouxX.c \
ft_parse_h_l_diouxX.c ft_parse_diouxX.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	@make -C libft/
	@$(CC) -c $(SRC) -I libft/ $(CFLAGS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) -o $(EXEC) $(NAME) -L libft/ -lft $(CFLAGS)

clean:
	@/bin/rm -rf $(OBJ)
	@make -C libft/ clean

fclean:
	@/bin/rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

compile:
	@$(CC) -c $(SRC) -I libft/ $(CFLAGS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) -o $(EXEC) $(NAME) -L libft/ -lft $(CFLAGS)

.PHONY: all clean fclean re