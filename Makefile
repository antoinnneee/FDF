#*****************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 12:47:45 by abureau           #+#    #+#              #
#    Updated: 2016/04/13 16:48:24 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#



NAME = pls

DIRSRC = ./includes/

SRC = ./main.c
CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -L/usr/local/lib/ -I/usr/local/include -I GNL_NOFD/libft/includes -L GNL_NOFD/libft/ -lft -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -I libft/includes -o $@ -c $<

fclean:
	rm -f get_next_line.o
	rm -f pls
	rm -f main.o

re: fclean all


