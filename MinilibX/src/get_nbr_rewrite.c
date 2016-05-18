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
#include <string.h>
#include "../includes/get_nbr.h"

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


static void		init_coord(t_coord *elem, int zvalue)
{
	t_coord	*new_dot;

	new_dot = (t_coord*)ft_memalloc(sizeof(t_coord));
	new_dot->x = 0;
	new_dot->y = 0;
	new_dot->z = zvalue;
	new_dot->nextx = NULL;
	new_dot->nexty = NULL;
	elem = new_dot;
}


static t_coord		*add_last_coord(t_coord *elem, int zvalue, int yval)
{
	t_coord	*new_dot;
	t_coord	*tmp;
	int		index;

	new_dot = (t_coord*)ft_memalloc(sizeof(t_coord));
	new_dot->x = 0;
	new_dot->y = 0;
	new_dot->z = zvalue;
	new_dot->nextx = NULL;
	new_dot->nexty = NULL;
	index = 0;
	tmp = NULL;
	if (elem == NULL)
	{
		return (new_dot);
	}
	else
	{
		tmp = elem;
		while (tmp->nexty != NULL && index <= yval )
		{
			index++;
			tmp = tmp->nexty;
			new_dot->y = new_dot->y + 1;
		}
		if(index < yval && tmp->nexty == NULL)
		{
			new_dot->y = new_dot->y + 1;
			tmp->nexty = new_dot;
			return(elem);
		}
		new_dot->x = new_dot->x + 1;
		while (tmp->nextx != NULL)
		{
			tmp = tmp->nextx;
			new_dot->x = new_dot->x + 1;
		}
		tmp->nextx = new_dot;
	}
	return (elem);
}


static t_coord		*creat_list(t_coord *begin,int *tab_dim, int nbline)
{
	int	index;
	
	index = 1;
	while (index <= tab_dim[0])
	{
		begin = add_last_coord(begin, tab_dim[index], nbline);
		index++;
	}
	return(begin);
} 


static t_coord		*link_elem(t_coord *begin, int nbline, int nbdim)
{
	t_coord	*elemy;
	t_coord	*elem;
	t_coord	*cursor;
	int index;

	elem = begin;
	cursor = elem;
	elemy = elem->nexty;
	while (cursor->nexty != NULL)
	{
		elemy = elem->nexty;
		while (elem->nextx != NULL && elemy->nextx != NULL)
		{
			elem = elem->nextx;
			elemy = elemy->nextx;
			elem->nexty = elemy;
		}
		cursor = cursor->nexty;
		elem = cursor;
	}
	return (begin);
}

t_coord			*get_number(int fd)
{
	char	*line;
	int		nbline;
	int	*tab_dim;
	t_coord		*beg_dot;
	beg_dot = NULL;
	

	nbline = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (!parse_number(line))
			return (NULL);
		
		tab_dim = get_dim(ft_strtrim(line));
		beg_dot = creat_list(beg_dot, tab_dim, nbline - 1);		
		
		nbline++;
	}
	beg_dot = link_elem(beg_dot, nbline, nbline);
	return (beg_dot);
}
