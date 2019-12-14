
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 13:33:40 by jrignell          #+#    #+#              #
#    Updated: 2019/12/05 15:40:30 by jrignell         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c \
	ft_isupper.c \
	ft_strlen.c \
	ft_atoi.c \
	ft_isdigit.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_isalnum.c \
	ft_islower.c \
	ft_strdup.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_isprint.c \
	ft_isascii.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_bzero.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_memalloc.c \
	ft_strnew.c \
	ft_isspace.c \
	ft_strjoin.c \
	ft_memdel.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strtrim.c \
	ft_strsub.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_lstnew.c \
	ft_copy.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstadd.c \
	ft_lstiter.c \
	get_next_line.c \
	ft_print_hex.c \
	ft_print_octal.c \
	ft_putnbr_ull_fb.c \
	ft_print_hex_ull.c \
	ft_print_octal_ull.c

OBJ  = ft_isalpha.o \
    ft_isupper.o \
    ft_strlen.o \
    ft_atoi.o \
    ft_isdigit.o \
    ft_strcpy.o \
    ft_strncpy.o \
    ft_isalnum.o \
    ft_islower.o \
    ft_strdup.o \
    ft_strcmp.o \
    ft_strncmp.o \
    ft_isprint.o \
    ft_isascii.o \
    ft_strstr.o \
    ft_strnstr.o \
    ft_bzero.o \
    ft_strcat.o \
    ft_strncat.o \
    ft_strlcat.o \
    ft_putchar.o \
    ft_putchar_fd.o \
    ft_putstr.o \
    ft_putstr_fd.o \
    ft_putendl.o \
    ft_putendl_fd.o \
    ft_putnbr.o \
    ft_putnbr_fd.o \
    ft_memset.o \
    ft_memcpy.o \
    ft_memccpy.o \
    ft_tolower.o \
    ft_toupper.o \
    ft_memmove.o \
    ft_memchr.o \
    ft_memcmp.o \
    ft_strchr.o \
    ft_strrchr.o \
    ft_memalloc.o \
    ft_strnew.o \
    ft_isspace.o \
    ft_strjoin.o \
    ft_memdel.o \
    ft_strdel.o \
    ft_strclr.o \
    ft_strequ.o \
    ft_strnequ.o \
    ft_striter.o \
    ft_striteri.o \
    ft_strtrim.o \
    ft_strsub.o \
    ft_strmap.o \
    ft_strmapi.o \
    ft_strsplit.o \
    ft_itoa.o \
    ft_lstnew.o \
    ft_copy.o \
    ft_lstdel.o \
    ft_lstdelone.o \
	ft_lstadd.o \
    ft_lstiter.o \
	get_next_line.o \
	ft_print_hex.o \
	ft_print_octal.o \
	ft_putnbr_ull_fb.o \
	ft_print_hex_ull.o \
	ft_print_octal_ull.o

INC = includes/

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCS) -I $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean