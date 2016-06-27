/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:41:20 by abureau           #+#    #+#             */
/*   Updated: 2016/06/06 15:23:15 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	tryalloc(void *ptr)
{
	if (!ptr)
	{
		ft_putendl("init error");
		exit(0);
	}
}

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

int		parse_letter(char *line)
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
