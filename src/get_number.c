/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:37:28 by abureau           #+#    #+#             */
/*   Updated: 2016/04/26 14:53:03 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_number.h"

static int	*initfirst(int chose)
{
	int	count;
	int	*dim;

	count = 0;
	dim = (int*)ft_memalloc(sizeof(int) * (count + 1));
	dim[count] = chose;
	return (dim);
}

static void	myrealloc(int **dim, int **buffer, int count)
{
	*buffer = (int*)ft_memalloc(sizeof(int) * (count));
	ft_memmove(*buffer, *dim, sizeof(int) * count);
	*dim = (int*)ft_memalloc(sizeof(int) * (count + 2));
	ft_memmove(*dim, *buffer, sizeof(int) * count);
}

static int	*get_dim(const char *ln)
{
	int	*dim;
	int	*buffer;
	int	count;
	int	cur;
	int	tmpcursor;

	ft_initthreevar(&count, &cur, &tmpcursor);
	while (ln[cur] != 0)
	{
		if (ft_issignednumber(ln[cur]))
		{
			tmpcursor = cur;
			while (ft_issignednumber(ln[cur]))
				cur++;
			count++;
		}
		else if (count > 0)
			myrealloc(&dim, &buffer, count);
		dim[count] = ft_satoi(ft_strsub(ln, tmpcursor, cur - tmpcursor));
		cur++;
	}
	dim[count + 1] = ft_satoi(ft_strsub(ln, tmpcursor, cur - tmpcursor));
	dim[0] = count;
	return (dim);
}

int			**get_number(int fd)
{
	int		**tabnumber;
	int		**buffer;
	char	*line;
	int		nbline;

	nbline = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (!parse_number(line))
			return (NULL);
		buffer = (int**)ft_memalloc(sizeof(int*) * (nbline + 1));
		ft_memmove(buffer, tabnumber, sizeof(int*) * nbline + 1);
		tabnumber = (int**)ft_memalloc(sizeof(int*) * (nbline + 2));
		ft_memmove(tabnumber, buffer, sizeof(int*) * nbline + 1);
		tabnumber[nbline] = get_dim(ft_strtrim(line));
		nbline++;
	}
	tabnumber[0] = initfirst(nbline);
	return (tabnumber);
}
