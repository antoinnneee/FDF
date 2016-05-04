#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/26 15:16:18 by abureau           #+#    #+#              #
#    Updated: 2016/05/02 14:51:34 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = test_fdf

SRC = ./src/get_number.c \
	./src/main.c \
	./src/get_next_line.c \
	./src/initialize.c \
	./src/divert.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra

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
