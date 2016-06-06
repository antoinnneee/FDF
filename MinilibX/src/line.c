/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 16:08:51 by abureau           #+#    #+#             */
/*   Updated: 2016/06/06 19:45:41 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include "../libft/includes/libft.h"
#include "../includes/get_nbr.h"
#include <mlx.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>

void	drawfunc(t_init *t__mlx)
{
	t_coord	*tmp;
	t_coord	*cursorx;

	cursorx = t__mlx->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		cursorx = cursorx->nexty;
		while (tmp != NULL)
		{
			ft_putstrnb("z value :", tmp->z);
			if (tmp->nextx)
				drawfcase(tmp, t__mlx);
			if (tmp->nexty)
				drawfcase2(tmp, t__mlx);
			tmp = tmp->nextx;
		}
	}
}

int		invertcoord(t_coord *t_dot)
{
	int	tmpxa;
	int	tmpya;
	int	tmpxb;
	int	tmpyb;

	tmpxa = t_dot->X1;
	tmpya = t_dot->Y1;
	tmpxb = t_dot->X2;
	tmpyb = t_dot->Y2;
	t_dot->X1 = tmpxb;
	t_dot->Y1 = tmpyb;
	t_dot->X2 = tmpxa;
	t_dot->Y2 = tmpya;
	return (0);
}

int		invert2coord(t_coord *t_dot)
{
	int	tmpxa;
	int	tmpya;
	int	tmpxb;
	int	tmpyb;

	tmpxa = t_dot->X1;
	tmpya = t_dot->Y1;
	tmpxb = t_dot->X3;
	tmpyb = t_dot->Y3;
	t_dot->X1 = tmpxb;
	t_dot->Y1 = tmpyb;
	t_dot->X3 = tmpxa;
	t_dot->Y3 = tmpya;
	return (0);
}
