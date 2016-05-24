#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/19 15:55:28 by abureau           #+#    #+#              #
#    Updated: 2016/05/19 15:55:28 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = test_fdf

SRC = ./src/divert.c \
	./src/color.c \
	./src/initialize.c \
	./src/main.c \
	./src/calc.c \
	./src/line.c \
	./src/get_next_line.c \
	./src/get_nbr_rewrite.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra

.ONESHELL:
all: LIBCOMPILE $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -I libft/includes -L libft/ -lft -L mlx/ -lmlx -lXext -lX11 -lm -lbsd

LIBCOMPILE:
	make -C libft/
	./mlx/configure

%.o: %.c
	$(CC) $(CFLAGS) -I libft/includes -I mlx -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean
	./mlx/configure clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	./mlx/configure fclean

re: fclean all
