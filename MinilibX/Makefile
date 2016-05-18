#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 14:43:26 by abureau           #+#    #+#              #
#    Updated: 2016/05/17 14:43:26 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = test_fdf

SRC = ./src/divert.c \
	./src/initialize.c \
	./src/geometry.c \
	./src/main.c \
	./src/get_next_line.c \
	./src/get_nbr_rewrite.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g

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
