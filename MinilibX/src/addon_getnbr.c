/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addon_getnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:05:40 by abureau           #+#    #+#             */
/*   Updated: 2016/06/06 20:16:30 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_coord	*link_elem(t_coord *begin)
{
	t_coord	*elemy;
	t_coord	*elem;
	t_coord	*cursor;

	if (!begin)
		fun_error("init error", begin);
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

void			freecoord(t_coord *begin)
{
	t_coord	*tmp;
	t_coord	*cursorx;
	t_coord *cursory;

	cursorx = begin;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		while (tmp->nexty != NULL)
		{
			cursory = tmp;
			tmp = tmp->nexty;
			cursory->nextx = NULL;
			cursorx->nexty = NULL;
			free(cursory);
		}
		tmp->nextx = NULL;
		tmp->nexty = NULL;
		free(tmp);
		cursorx = cursorx->nextx;
	}
	free(begin);
	begin = NULL;
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
