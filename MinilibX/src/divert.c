/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:01:10 by abureau           #+#    #+#             */
/*   Updated: 2016/06/06 15:32:50 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_nbr.h"

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

int		percent(int low_range, int max_range, int value)
{
	float p;

	p = (float)((value - low_range) * 100. / (max_range - low_range));
	return (p);
}

void	fun_error(const char *str, void *ptr)
{
	if (ptr)
		free(ptr);
	ft_putendl(str);
	exit(0);
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
		}
		nbrm->nbr_array = new_array;
	}
	return (nbrm);
}
