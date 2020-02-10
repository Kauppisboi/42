# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 15:53:22 by jrignell          #+#    #+#              #
#    Updated: 2020/02/10 18:02:14 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXEC = ft_printf
CFLAGS = -Wall -Wextra -Werror
CC = gcc

OBJ_DIR := ./obj
INC_DIR := ./includes
SRC_DIR := ./srcs

SRC := 	ft_printf.c \
		ft_parse_diouxf.c \
		ft_parse_hh_h_ll_l.c \
		check_bef_format.c \
		check_bef_format_u.c \
		ft_parse_width.c \
		ft_parse_f.c \
		ft_precision.c \
		ft_parse_csp_percent.c \
		ft_parse_flags.c \
		ft_helpers.c \
		ft_helpers_check_functions.c \
		ft_parse_brk.c

OBJ :=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C libft/
	@cp libft/libft.a ./libftprintf.a
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) -o $(EXEC) $(NAME) main.c $(CFLAGS)

clean:
	@/bin/rm -rf $(OBJ)
	@make -C libft/ clean

fclean:
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(OBJ)
	@make -C libft/ fclean

re: fclean all

compile: $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) -o $(EXEC) $(NAME) main.c $(CFLAGS)
	
.PHONY: all clean fclean re
