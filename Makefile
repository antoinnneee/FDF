#*****************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 12:47:45 by abureau           #+#    #+#              #
#    Updated: 2016/04/19 11:35:48 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#



NAME = pls

DIRSRC = ./includes/ \
		 ./src/

SRC = ./main.c \
	  ./src/count_nbr.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ GNL_NOFD/get_next_line.o -L/usr/local/lib/ -I/usr/local/include -I GNL_NOFD/libft/includes -L GNL_NOFD/libft/ -lft -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -I GNL_NOFD/libft/includes -o $@ -c $<

fclean:
	rm -f pls

re: fclean all


