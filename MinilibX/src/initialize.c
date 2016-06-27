/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:47:41 by abureau           #+#    #+#             */
/*   Updated: 2016/06/06 19:21:20 by abureau          ###   ########.fr       */
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

static void	definition(t_init *t__mlx)
{
	t_coord		limit[4];
	int			index;
	int			pix;
	int			p;

	limit[1].x = WIDTH - PADD - 30;
	index = PADD;
	pix = WIDTH - PADD - 40;
	while (index != PADD + 70)
	{
		while (++pix != limit[1].x)
		{
			p = (int)(index - PADD) * 100. / 70;
			mlx_pixel_put(t__mlx->mlx,
				t__mlx->win, pix, index, get_color_def(p));
			if (p == 0)
				mlx_string_put(t__mlx->mlx, t__mlx->win, limit[1].x + 2, index
						, get_color_def(p), ft_itoa(t__mlx->LOW_RANGE));
		}
		if (index == PADD + 69)
			mlx_string_put(t__mlx->mlx, t__mlx->win, limit[1].x + 2, index
					, get_color_def(p), ft_itoa(t__mlx->MAX_RANGE));
		index++;
		pix = WIDTH - PADD - 40;
	}
}

static void	get_real_value(t_init *t__mlx)
{
	t_coord	*tmp;
	t_coord	*cursorx;

	cursorx = t__mlx->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		cursorx = cursorx->nextx;
		setcoord(t__mlx, tmp);
		while (tmp != NULL)
		{
			setcoord(t__mlx, tmp);
			tmp = tmp->nexty;
		}
	}
}

static int	*get_range(t_coord *nbr)
{
	int		*rangen;
	t_coord	*tmp;
	t_coord	*cursorx;

	if (!nbr)
		fun_error("error while checking range, map error", NULL);
	rangen = (int*)ft_memalloc(sizeof(int) * 3);
	LOW_RANGE = nbr->z;
	MAX_RANGE = nbr->z;
	cursorx = nbr;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		while (tmp != NULL)
		{
			if (tmp->z < LOW_RANGE)
				LOW_RANGE = tmp->z;
			else if (tmp->z > MAX_RANGE)
				MAX_RANGE = tmp->z;
			tmp = tmp->nexty;
		}
		cursorx = cursorx->nextx;
	}
	RANGE = MAX_RANGE - LOW_RANGE;
	return (rangen);
}

void	creat_window(t_init *t__mlx)
{
	tryalloc(t__mlx->win);
	definition(t__mlx);
	get_real_value(t__mlx);
	mlx_pixel_put(t__mlx->mlx, t__mlx->win, t__mlx->coord->x + t__mlx->hpadd, t__mlx->coord->y + t__mlx->vpadd, CWHI);
	drawfunc(t__mlx);
}

void		init_fdf(const char *str, t_init *t_init_mlx)
{
	int			fd;

	fd = open(str, O_RDONLY);
	ft_putendl("opening map ok");
	ft_putstrnb("fd : ", fd);
	t_init_mlx = (t_init*)ft_memalloc(sizeof(t_init));
	tryalloc(t_init_mlx);
	t_init_mlx->isset = 0;
	t_init_mlx->coord = get_number(fd);
	t_init_mlx->hpadd = HEIGHT/2 - 40;
	t_init_mlx->vpadd = 20;
	t_init_mlx->an = 0.;
	t_init_mlx->space = SPACE;
	t_init_mlx->mod = 1;
	t_init_mlx->wid = WIDTH;
	t_init_mlx->hei = HEIGHT;
	t_init_mlx->rangen = get_range(t_init_mlx->coord);
	t_init_mlx->acwin = init_achi();
	t_init_mlx->mlx = mlx_init();
	t_init_mlx->win = mlx_new_window(t_init_mlx->mlx, WIDTH, HEIGHT, WIN_N);
	achievement(t_init_mlx);
	mlx_hook(t_init_mlx->win, 2, 1, my_key_func, t_init_mlx);
	mlx_loop(t_init_mlx->mlx);
}
