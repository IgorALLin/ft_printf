# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichebota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/06 16:10:07 by ichebota          #+#    #+#              #
#    Updated: 2017/03/27 14:57:52 by ichebota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = includes/printf.h
SRC = ft_printf.c add_char.c add_flags.c char.c ft_check_format.c fun1.c ft_itoa_base_ll.c ft_itoa_base_ull_lower.c ft_itoa_base_ull.c hex.c int.c invalid_format.c octal.c pointer.c put_flags.c read_format.c string.c unsigned.c valid_format.c valid_width.c  ft_atoi.c ft_bzero.c ft_itoa.c ft_memalloc.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putstr.c ft_strcat.c ft_strcpy.c ft_strjoin.c ft_strlen.c ft_strmap.c ft_strncpy.c ft_strnew.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -c
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
clean:
		@rm -f $(OBJ)
fclean:
		make clean
		@rm -f $(NAME)
re:
		make fclean 
		make all
		@ar rc $(NAME) $(OBJ)
