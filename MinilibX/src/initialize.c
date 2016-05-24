/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:47:41 by abureau           #+#    #+#             */
/*   Updated: 2016/05/18 17:56:26 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include "../libft/includes/libft.h"
#include "../includes/get_nbr.h"
#include "../mlx/mlx.h"
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>


static void fullcolor1(t_init *t__mlx)
{
	int	color;
	t_coord	*tmp;
	t_coord	*cursorx;
	int	pix;
	float ordo;
	float coeffdir;
	int p;
	int VAL;

	cursorx = t__mlx->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		cursorx = cursorx->nextx;
		while (tmp != NULL && tmp->nexty != NULL)
		{
			pix = tmp->X1;
			if (tmp->X3 - tmp->X1 != 0)
			{
				coeffdir = (float) (tmp->Y3 - tmp->Y1 ) / (tmp->X3 - tmp->X1);
				while (pix != tmp->X3)
				{
				ordo = tmp->Y1 - (coeffdir * tmp->X1);
					VAL = tmp->Y1;
					while (VAL != tmp->Y3)
					{
					ordo = ordo+1;
					p = ((pix - tmp->X1) * 100 / (tmp->X3 - tmp->X1));
					color = get_color(t__mlx, p, tmp->z, tmp->nexty->z);
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, pix + t__mlx->hpadd, (coeffdir * pix) + ordo + t__mlx->vpadd, color);
					VAL = ( VAL > tmp->Y3 ) ? VAL - 1 : VAL + 1;
					}
					pix = ( pix > tmp->X3 ) ? pix - 1 : pix + 1;
				}
			}
			tmp = tmp->nexty;
		}
	}

}

static void	slide(t_init *t__mlx, t_coord *tmp)
{
	int pix = tmp->X1;
	int	piy;	
//	int p = ((pix - tmp->X1) * 100 / (tmp->X2 - tmp->X1));
//	int color = get_color(t__mlx, p, tmp->z, tmp->nextx->z);
	int coeffdir = (float) (tmp->Y2 - tmp->Y1 ) / (tmp->X2 - tmp->X1);
	int ordo = tmp->Y1 - (coeffdir * tmp->X1);
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;


	x1 = tmp->X1;
	x2 = tmp->X2;
	x3 = tmp->X3;
	x4 = tmp->nextx->nexty->x;
	y1 = tmp->Y1;
	y2 = tmp->Y2;
	y3 = tmp->Y3;
	y4 = tmp->nextx->nexty->y;
	coeffdir = (y3 - y1)/(x3 - x1);
	ordo = y1 - (coeffdir * x1);
	pix = x1;
	piy = y1;
	
mlx_pixel_put(t__mlx->mlx, t__mlx->win, x1 + t__mlx->hpadd , y1 + t__mlx->vpadd, CRED);
	mlx_pixel_put(t__mlx->mlx, t__mlx->win, x2 + t__mlx->hpadd , y2 + t__mlx->vpadd, CRED);
	mlx_pixel_put(t__mlx->mlx, t__mlx->win, x3 + t__mlx->hpadd , y3 + t__mlx->vpadd, CRED);
	mlx_pixel_put(t__mlx->mlx, t__mlx->win, x4 + t__mlx->hpadd , y4 + t__mlx->vpadd, CRED);

	while (pix != x2)
	{	
		while (piy != y2)
		{
			if(coeffdir == 0)
			mlx_pixel_put(t__mlx->mlx, t__mlx->win, piy-ordo + t__mlx->hpadd , piy + t__mlx->vpadd, CGRE);
			piy = ( piy > y2 ) ? piy - 1 : piy + 1;
		}
			piy = y1;
			pix = ( pix > x2 ) ? pix - 1 : pix + 1;
	}	



}

static void fullcolor2(t_init *t__mlx)
{
	int	color;
	t_coord	*tmp;
	t_coord	*cursorx;
	int	pix;
	float ordo;
	float coeffdir;
	int p;
	int VAL;
	int mod;

	cursorx = t__mlx->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		cursorx = cursorx->nextx;
		while (tmp != NULL && tmp->nextx != NULL && tmp->nexty)
		{
			pix = tmp->X1;
			mod = 0;
			if (tmp->X3 - tmp->X1 != 0)
			{
						slide(t__mlx, tmp);
			}
			tmp = tmp->nexty;
		}
	}
}


static void fullcolor(t_init *t__mlx)
{
	line_Y_x(t__mlx);
	line_Y_y(t__mlx);
	line_X_x(t__mlx);
	line_X_y(t__mlx);
//	fullcolor1(t__mlx);
//	fullcolor2(t__mlx);
}

static void	dot_printing(t_init *t__mlx)
{
	int	color;
	t_coord	*tmp;
	t_coord	*cursorx;

	cursorx = t__mlx->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		cursorx = cursorx->nextx;
		while (tmp != NULL)
		{
			color = get_color(t__mlx, 100, tmp->z,tmp->z);
			mlx_pixel_put(t__mlx->mlx, t__mlx->win, tmp->x , tmp->y , color);
			tmp = tmp->nexty;
		}
	}
}


static void	tryalloc(void *ptr)
{
	if (!ptr)
	{
		ft_putendl("init error");
		exit(0);
	}

}

static void	definition(t_init *t__mlx)
{
	t_coord		limit[4];
	int			index;
	int			pix;
	int			p;

	limit[0].x = WIDTH - PADD - 40;
	limit[0].y = PADD;
	limit[1].x = WIDTH - PADD - 30;
	limit[1].y = PADD;
	limit[2].x = limit[0].x;
	limit[2].y = PADD + 70;
	limit[3].x = limit[1].x;
	limit[3].y = limit[2].y;
	index = limit[0].y;
	pix = limit[0].x;	
	while(index != limit[2].y)
	{
		while (pix != limit[1].x)
		{
			p = (int)(index - limit[0].y) * 100. / (limit[2].y - limit[0].y);
			mlx_pixel_put(t__mlx->mlx, t__mlx->win, pix, index, get_color_def(p));
			pix ++;
			if (p == 0)
				mlx_string_put(t__mlx->mlx, t__mlx->win, limit[1].x + 2, index, get_color_def(p), ft_itoa(t__mlx->LOW_RANGE));
		}
		if (index == limit[2].y -1)	
			mlx_string_put(t__mlx->mlx, t__mlx->win, limit[1].x + 2, index, get_color_def(p), ft_itoa(t__mlx->MAX_RANGE));
		index++;
		pix = limit[0].x;
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
			ft_putendl("===================");
			ft_putstrnb("new value X : ", tmp->x);
			ft_putstrnb("new value Y : ", tmp->y);
			ft_putstrnb("new value Z : ", tmp->z);
			tmp = tmp->nexty;
		}
	}
}


static int	*get_range(t_coord *nbr)
{
	int	*rangen;
	t_coord *tmp;
	t_coord *cursorx;	

	rangen = (int*) ft_memalloc(sizeof(int) * 3);	
	LOW_RANGE = nbr->z;
	MAX_RANGE = nbr->z;
	tmp = nbr;
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


static void	explore(t_coord *begin)
{
	t_coord	*tmp;
	t_coord	*cursorx;

	tmp = begin;
	cursorx = begin;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		while (tmp->nexty != NULL)
		{
			ft_putstrnb("value z :", tmp->z);
			tmp = tmp->nexty;
		}
		ft_putstrnb("value z :", tmp->z);
		ft_putstrnb("next x -> value of x : ", cursorx->x);
		cursorx = cursorx->nextx;
	}
}

inline void	creat_window(t_init *t_init_mlx)
{
	tryalloc(t_init_mlx->win);
	//	line(t_init_mlx);

	//	lineR(t_init_mlx);
	//	lineD(t_init_mlx);
	definition(t_init_mlx);
	ft_putendl("Definition OK");
	get_real_value(t_init_mlx);
	ft_putendl("REAL VALUE Ok");
	explore(t_init_mlx->coord);
	ft_putendl("EXPLORE Ok");
	//	dot_printing(t_init_mlx);

	fullcolor(t_init_mlx);
	//	put_line(t_init_mlx, t_init_mlx->coord[0]);
}

void		init_fdf(const char *str, t_init *t_init_mlx)
{
	t_coord		*numberarray;
	int			fd;

	fd = open(str, O_RDONLY);
	ft_putendl("opening map ok");
	ft_putstrnb("fd : ", fd);
	numberarray = get_number(fd);
	ft_putendl("number array ok");

	/*
	   number_map = get_struct_value(numberarray);
	   tryalloc(number_map);
	 */

	t_init_mlx = (t_init*)ft_memalloc(sizeof(t_init));
	tryalloc(t_init_mlx);
	t_init_mlx->isset = 0;
	t_init_mlx->rotz = 0;
	t_init_mlx->roty = 0;
	t_init_mlx->coord = numberarray;
	t_init_mlx->hpadd = 20;
	t_init_mlx->vpadd = 20;	
	t_init_mlx->an = 0.;
	t_init_mlx->space = SPACE;


	//	t_init_mlx->nbr_map = number_map;
	t_init_mlx->wid = WIDTH;
	t_init_mlx->hei = HEIGHT;

	t_init_mlx->rangen = get_range(numberarray);
	//	print_map_number(t_init_mlx->nbr_map);
	explore(t_init_mlx->coord);
	ft_putendl("explore Ok");
	t_init_mlx->mlx = mlx_init();
	ft_putendl("Init MLX Ok");
	t_init_mlx->win = mlx_new_window(t_init_mlx->mlx, WIDTH, HEIGHT, WIN_N);
	creat_window(t_init_mlx);
	ft_putendl("Creation fenetre Ok");
	mlx_mouse_hook(t_init_mlx->win, my_mouse_func, &t_init_mlx);
	mlx_key_hook(t_init_mlx->win, my_key_func, t_init_mlx);
	mlx_loop(t_init_mlx->mlx);
}
