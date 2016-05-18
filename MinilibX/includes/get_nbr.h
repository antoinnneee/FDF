/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:44:23 by abureau           #+#    #+#             */
/*   Updated: 2016/04/26 14:12:40 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NBR_H
#define GET_NBR_H

#include "../includes/get_next_line.h"
#include "../libft/includes/libft.h"

typedef struct	s_coord
{
	int		x;
	int		y;
	int		z;
	struct s_coord	*nextx;
	struct s_coord	*nexty;
}t_coord;

typedef struct	s_map
{
	int		*non;
	int		nb_dim;
	int		**nbr_array;
}t_map;

t_coord		*get_number(int fd);
int		ft_satoi(char *str);
void	print_map_number(t_map *array);
int		parse_number(char *line);
int		ft_issignednumber(const char c);
t_map	*get_struct_value(int **arraynum);

#endif
