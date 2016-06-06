#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/18 16:20:34 by abureau           #+#    #+#              #
#    Updated: 2016/06/06 18:04:26 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = test_fdf

SRC = ./src/main.c \
	./src/get_next_line.c \
	./src/get_nbr_rewrite.c \
	./src/color.c \
	./src/initialize.c \
	./src/line.c \
	./src/calc.c \
	./src/addon_getnbr.c\
	./src/divert.c \
	./src/divert_number.c \
	./src/draw_p1.c \
	./src/draw_p2.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror

all: LIBCOMPILE $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -I libft/includes -L libft/ -lft -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

LIBCOMPILE:
	 make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) -I libft/includes -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
