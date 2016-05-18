/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_rewrite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:52:36 by abureau           #+#    #+#             */
/*   Updated: 2016/05/18 17:42:13 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/get_nbr.h"

static void		myrealloc(int **dim, int **buffer, int count)
{
	*buffer = (int*)ft_memalloc(sizeof(int) * (count));
	ft_memmove(*buffer, *dim, sizeof(int) * count);
	*dim = (int*)ft_memalloc(sizeof(int) * (count + 2));
	ft_memmove(*dim, *buffer, sizeof(int) * count);
}

static int		*get_dim(const char *ln)
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

static t_coord	*creat_dot(int zvalue, t_coord **tmp, t_coord *elem)
{
	t_coord	*new_dot;

	new_dot = (t_coord*)ft_memalloc(sizeof(t_coord));
	new_dot->x = 0;
	new_dot->y = 0;
	new_dot->z = zvalue;
	new_dot->nextx = NULL;
	new_dot->nexty = NULL;
	*tmp = elem;
	return (new_dot);
}

static t_coord	*add_last_coord(t_coord *elem, int zvalue, int yval)
{
	t_coord	*new_dot;
	t_coord	*tmp;

	new_dot = creat_dot(zvalue, &tmp, elem);
	if (elem == NULL)
		return (new_dot);
	while (tmp->nexty != NULL && 0 <= yval--)
	{
		tmp = tmp->nexty;
		new_dot->y = new_dot->y + 1;
	}
	if (0 < yval && tmp->nexty == NULL)
	{
		new_dot->y = new_dot->y + 1;
		tmp->nexty = new_dot;
		return (elem);
	}
	while (tmp->nextx != NULL)
	{
		new_dot->x = new_dot->x + 1;
		tmp = tmp->nextx;
	}
	new_dot->x = new_dot->x + 1;
	tmp->nextx = new_dot;
	return (elem);
}

static t_coord	*creat_list(t_coord *begin, int *tab_dim, int nbline)
{
	int	index;

	index = 1;
	while (index <= tab_dim[0])
	{
		begin = add_last_coord(begin, tab_dim[index], nbline);
		index++;
	}
	return (begin);
}

static t_coord	*link_elem(t_coord *begin)
{
	t_coord	*elemy;
	t_coord	*elem;
	t_coord	*cursor;

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
	int		*tab_dim;
	t_coord	*beg_dot;

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
	beg_dot = link_elem(beg_dot);
	return (beg_dot);
}
