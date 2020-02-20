# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 15:53:22 by jrignell          #+#    #+#              #
#    Updated: 2020/02/17 16:24:47 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXEC = ft_printf
CFLAGS = -Wall -Wextra -Werror
CC = gcc

OBJ_DIR := ./obj
INC_DIR := ./includes
SRC_DIR := ./srcs
DEB_DIR := ./debug

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

DEBUG := $(addprefix $(DEB_DIR)/,$(SRC:.c))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

#$(DEB_DIR):
#	@mkdir -p $(DEB_DIR)

#$(DEB_DIR)/%.c:$(SRC_DIR)/%.c
#	@$(CC) -g $(CFLAGS) -I $(INC_DIR) -I libft/includes 
	#-o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C libft/
	@cp libft/libft.a ./libftprintf.a
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJ)
	@make -C libft/ clean

fclean:
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(OBJ)
	@make -C libft/ fclean

re: fclean all

#debug: $(DEB_DIR) $(DEBUG)
	

main: $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) -o $(EXEC) $(NAME) main.c $(CFLAGS)
	
.PHONY: all clean fclean re
