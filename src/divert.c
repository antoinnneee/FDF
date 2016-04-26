/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:41:20 by abureau           #+#    #+#             */
/*   Updated: 2016/04/26 14:54:17 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_number.h"

int		ft_issignednumber(const char c)
{
	if (ft_isdigit(c) || c == '+' || c == '-')
		return (1);
	return (0);
}

void	print_map_number(t_map *array)
{
	int	index;
	int	line;

	index = 0;
	line = 0;
	ft_putstrnb("print_map_number : number of line : ", array->nb_dim);
	while (line < array->nb_dim)
	{
		while (index < array->non[line])
		{
			ft_putnbr(array->nbr_array[line][index]);
			ft_putchar(' ');
			index++;
		}
		ft_putchar('\n');
		index = 0;
		line++;
	}
}

int		parse_number(char *line)
{
	int	i;
	int state;

	i = 0;
	state = 0;
	if (!ft_strlen(line))
		return (0);
	while (line[i] != 0)
	{
		if (ft_issignednumber(line[i]) == 1)
		{
			while (ft_issignednumber(line[i]) ^ ft_isdigit(line[i]))
				i++;
			while (ft_isdigit(line[i]))
			{
				i++;
				state++;
			}
			if (!(line[i] == ' ' ^ line[i] == '\0') || state == 0)
				return (0);
			state = 0;
		}
		i++;
	}
	return (1);
}

int		ft_satoi(char *str)
{
	unsigned int	signe;
	int				i;
	int				j;
	int				countsigne;

	j = 0;
	countsigne = 0;
	while (!ft_isdigit(str[j]) && (str[j]) != 0)
	{
		if (str[j] == '-')
		{
			countsigne++;
			i = j;
		}
		j++;
	}
	signe = (countsigne % 2) ? 0 : 1;
	if (!signe)
	{
		str[j - 1] = '-';
	}
	else
		countsigne = 0;
	return ((countsigne > 0) ? ft_atoi(&str[j - 1]) : ft_atoi(&str[j]));
}

t_map	*get_struct_value(int **arraynbr)
{
	t_map	*nbrm;
	int		**new_array;
	int		cu;
	int		col;

	nbrm = NULL;
	if (arraynbr)
	{
		nbrm = (t_map*)ft_memalloc(sizeof(t_map));
		nbrm->nb_dim = arraynbr[0][0] - 1;
		nbrm->non = (int *)ft_memalloc(sizeof(int) * nbrm->nb_dim);
		new_array = (int **)ft_memalloc(sizeof(int*) * nbrm->nb_dim);
		cu = -1;
		while (++cu < nbrm->nb_dim)
		{
			col = -1;
			nbrm->non[cu] = arraynbr[cu + 1][0];
			new_array[cu] = (int*)ft_memalloc(sizeof(int) * nbrm->non[cu]);
			while (++col < nbrm->non[cu])
				new_array[cu][col] = arraynbr[cu + 1][col + 1];
			free(arraynbr[cu]);
		}
		nbrm->nbr_array = new_array;
	}
	return (nbrm);
}
