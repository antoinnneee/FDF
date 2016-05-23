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

/*

   static int get_colorD(t_init *t__mlx, int per , int line, int cursor)
   {
   int percent;
   int value;

   value = t__mlx->nbr_map->nbr_array[line + 1][cursor] - t__mlx->nbr_map->nbr_array[line][cursor];
//	ft_putstrnb("col per   : ", per);
ft_putstrnb("col value : " , value);
if (value == 0)
percent = (t__mlx->nbr_map->nbr_array[line][cursor] - t__mlx->LOW_RANGE) * 100 / t__mlx->RANGE;
else
percent = value * per / 100;
ft_putstr("colonne =====NEWPIXEL=======\n");
ft_putstrnb("colonne range : " , value);
ft_putstrnb("colonne percent : " , percent);
ft_putstrnb("colonne value : " , t__mlx->nbr_map->nbr_array[line][cursor]);
ft_putstrnb("colonne per :", per);
if (percent == 0)
return (COLORWHI);
else if (percent <= 24)
return (COLORWHI - (percent * (0x00FF00FF )/ 100));
else if (percent <= 49)
return (COLORGRE - (percent * (0X00FF0000 )/ 100));
else if (percent <= 74)
return (COLORYEL - (percent * (0X00007500 )/ 100));
else if (percent >= 98)
return (COLORRED);
else
return (COLORORA - (percent * (0x00007500)/ 100));

return (COLORGRE);
}
 */

/*
   static void	line(t_init *t__mlx)
   {
   int		cursor;
   int		line;
   int		pix;
   int		piy;
   long long	color;
   int		coeffdir[2];
   int		ordo[2];
   int		p;

   line = 0;
   cursor = 0;
   while (line <= t__mlx->nbr_map->nb_dim - 2)
   {
   while (cursor < t__mlx->nbr_map->non[line])
   {
   pix = X1;
   coeffdir[0] = ( Y2 - Y1 ) / (X2 - X1);
   ordo[0] = Y1 - (coeffdir[0] * X1);
   if (X3 - X1 == 0 && cursor < t__mlx->nbr_map->non[line])
   {
   piy = Y1;
   while (piy != Y3)
   {
   p = (piy - Y1)* 100 / (Y3 - Y1);
   color = get_colorD(t__mlx, p, line, cursor);
   mlx_pixel_put(t__mlx->mlx, t__mlx->win, X1, piy, color);
   piy = ( piy > Y3 ) ? piy - 1 : piy + 1;
   }
   }
   else
   {
   piy = X1;
   coeffdir[1] = ( Y3 - Y1 ) / (X3 - X1);
   ordo[1] = Y1 - (coeffdir[1] * X1);
   while (piy != X3)
   {
   p = ((pix - X1) * 100 / (X2 - X1));
   color = get_colorD(t__mlx, p, line,cursor);
   mlx_pixel_put(t__mlx->mlx, t__mlx->win, pix , (coeffdir[1] * pix) + ordo[1], color);
   pix = ( pix > X2 ) ? pix - 1 : pix + 1;
   }

   }
   while (pix != X2)
   {
   p = ((pix - X1) * 100 / (X2 - X1));
   color = get_colorR(t__mlx, p, line,cursor);
   mlx_pixel_put(t__mlx->mlx, t__mlx->win, pix , (coeffdir[0] * pix) + ordo[0], color);
   pix = ( pix > X2 ) ? pix - 1 : pix + 1;
   }

   cursor++;
   }
   cursor = 0;
   line ++;
   }
   }
 */
/*
   static void	lineR(t_init *t__mlx)
   {
   int	cursor;
   int	line;
   int	pix;
   long long color;
   line = 0;
   cursor = 0;
   int coeffdir = 0;
   int ordo = 0;
   int p;
   while (line <= t__mlx->nbr_map->nb_dim - 1)
   {
   ft_putendl("new line");
   while (cursor < t__mlx->nbr_map->non[line] - 1)
   {
   color = COLORWHI;
   pix = X1;
   coeffdir = ( Y2 - Y1 ) / (X2 - X1);
   ordo = Y1 - (coeffdir * X1);
   if (X2 != 0)
   {
   while (pix != X2)
   {
   if (pix > X2)
   p = ((pix - X1) * 100 / (X2 - X1));
   else
   p = ((pix - X1) * 100 / (X2 - X1));
   color = get_color(t__mlx, p, t__mlx->nbr_map->nbr_array[line][cursor], t__mlx->nbr_map->nbr_array[line][cursor + 1]);
   mlx_pixel_put(t__mlx->mlx, t__mlx->win, pix , (coeffdir * pix) + ordo, color);
   pix = ( pix > X2 ) ? pix - 1 : pix + 1;
   }
   cursor++;
   }
   }
   cursor = 0;
   line ++;
   }
   }


   static void	lineD(t_init *t__mlx)
   {
   int			cursor;
   int			line;
   int			piy;
   long long	color;
   int			p;

   line = 0;
   cursor = 0;
   while (line <= t__mlx->nbr_map->nb_dim - 2)
   {
   ft_putendl("new colonne");
   while (cursor < t__mlx->nbr_map->non[line])
   {
   piy = Y1;
   color = COLORRED;
   if (Y3 != 0)
   {
   while (piy != Y3)
   {
   p = ((piy - Y1) * 100 / (Y3 - Y1));
   color = get_color(t__mlx, p, t__mlx->nbr_map->nbr_array[line][cursor],t__mlx->nbr_map->nbr_array[line + 1][cursor]);
   mlx_pixel_put(t__mlx->mlx, t__mlx->win, X1, piy, color);
   piy = ( piy > Y3 ) ? piy - 1 : piy + 1;
   }
   }
   cursor++;
   }
cursor = 0;
line ++;
}
}

static void fullcolor(t_init t__mlx)
{
	;	

}
*/
/*
   static void	line_D(t_init *t__mlx)
   {
   int	color;
   t_coord	*tmp;
   t_coord	*cursorx;
   int	piy;
   int p;

   cursorx = t__mlx->coord;
   while (cursorx != NULL)
   {
   tmp = cursorx;
   cursorx = cursorx->nextx;
   while (tmp->nexty != NULL)
   {
   piy = tmp->Y1;
   if (tmp->Y3 != NULL)
   {
   while (piy != tmp->Y3)
   {
   p = ((piy - tmp->Y1) * 100 / (tmp->Y3 - tmp->Y1));
   color = get_color(t__mlx, p, tmp->z, tmp->nexty->z);
   mlx_pixel_put(t__mlx->mlx, t__mlx->win, tmp->X1, piy, color);
   piy = ( piy > tmp->Y3 ) ? piy - 1 : piy + 1;
   }
   }
   tmp = tmp->nexty;
   }
   }
   }
 */

/*
   static void	line_D(t_init *t__mlx)
   {
   int	color;
   t_coord	*tmp;
   t_coord	*cursorx;
   int	piy;
   int p;
   int ordo;
   int coeffdir;

   cursorx = t__mlx->coord;
   while (cursorx != NULL)
   {
   tmp = cursorx;
   cursorx = cursorx->nextx;
   while (tmp->nexty != NULL)
   {
   piy = tmp->Y1;
   coeffdir = (float) (tmp->Y3 - tmp->Y1 ) / (tmp->X3 - tmp->X1);
   ordo = tmp->Y1 - (coeffdir * tmp->X1);
   if (tmp->Y3 != NULL)
   {
   while (piy != tmp->Y3)
   {
   p = ((piy - tmp->Y1) * 100 / (tmp->Y3 - tmp->Y1));
   color = get_color(t__mlx, p, tmp->z, tmp->nexty->z);
   mlx_pixel_put(t__mlx->mlx, t__mlx->win, (coeffdir * piy + ordo) + PADD, piy + PADD, color);
   piy = ( piy > tmp->Y3 ) ? piy - 1 : piy + 1;
   }
   }
   tmp = tmp->nexty;
   }
   }
   }

 */

static inline void	line_X_y(t_init *t__mlx)
{
	int	color;
	t_coord	*tmp;
	t_coord	*cursorx;
	int	piy;
	float ordo;
	float coeffdir;
	int p;

	cursorx = t__mlx->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		cursorx = cursorx->nextx;
		while (tmp != NULL && tmp->nextx != NULL)
		{
			piy = tmp->Y1;
			if (tmp->X2 - tmp->X1 != 0)
			{
				coeffdir = (float) (tmp->Y2 - tmp->Y1 ) / (tmp->X2 - tmp->X1);
				ordo = tmp->Y1 - (coeffdir * tmp->X1);
				while (piy != tmp->Y2)
				{
					p = ((piy - tmp->Y1) * 100 / (tmp->Y2 - tmp->Y1));
					color = get_color(t__mlx, p, tmp->z, tmp->nextx->z);
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, (-piy + ordo) / - coeffdir + t__mlx->hpadd, piy + t__mlx->vpadd, color);
					piy = ( piy > tmp->Y2 ) ? piy - 1 : piy + 1;
				}
			}
			else
			{
				while (piy != tmp->Y2)
				{
					p = ((piy - tmp->Y1) * 100 / (tmp->Y2 - tmp->Y1));
					color = get_color(t__mlx, p, tmp->z, tmp->nextx->z);
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, tmp->X2 + t__mlx->hpadd, piy + t__mlx->vpadd, color);
					piy = ( piy > tmp->Y2 ) ? piy - 1 : piy + 1;
				}

			}
			tmp = tmp->nexty;
		}
	}
}


static inline void	line_X_x(t_init *t__mlx)
{
	int	color;
	t_coord	*tmp;
	t_coord	*cursorx;
	int	pix;
	float ordo;
	float coeffdir;
	int p;

	cursorx = t__mlx->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		cursorx = cursorx->nextx;
		while (tmp != NULL && tmp->nextx != NULL)
		{
			pix = tmp->X1;
			coeffdir = (float) (tmp->Y2 - tmp->Y1 ) / (tmp->X2 - tmp->X1);
			ordo = tmp->Y1 - (coeffdir * tmp->X1);
			if (tmp->X2 - tmp->X1 != 0)
			{
				while (pix != tmp->X2)
				{
					int piy = coeffdir * pix + ordo;
					p = ((pix - tmp->X1) * 100 / (tmp->X2 - tmp->X1));
					color = get_color(t__mlx, p, tmp->z, tmp->nextx->z);
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, pix + t__mlx->hpadd, (coeffdir * pix) + ordo + t__mlx->vpadd, color);
					pix = ( pix > tmp->X2 ) ? pix - 1 : pix + 1;
				}
			}
			tmp = tmp->nexty;
		}
	}
}

static inline void	line_Y_y(t_init *t__mlx)
{
	int	color;
	t_coord	*tmp;
	t_coord	*cursorx;
	int	piy;
	float ordo;
	float coeffdir;
	int p;

	cursorx = t__mlx->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		cursorx = cursorx->nextx;
		while (tmp != NULL && tmp->nexty != NULL)
		{
			piy = tmp->Y1;
			if ( tmp->X3 - tmp->X1 != 0)
			{
				coeffdir = (float) (tmp->Y3 - tmp->Y1 ) / (tmp->X3 - tmp->X1);
				ordo = tmp->Y1 - (coeffdir * tmp->X1);
				while (piy != tmp->Y3)
				{
					p = ((piy - tmp->Y1) * 100 / (tmp->Y3 - tmp->Y1));
					color = get_color(t__mlx, p, tmp->z, tmp->nexty->z);
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, (-piy + ordo) / - coeffdir + t__mlx->hpadd, piy  + t__mlx->vpadd, color);
					piy = ( piy > tmp->Y3 ) ? piy - 1 : piy + 1;
				}
			}
			else
			{
				while (piy != tmp->Y3)
				{
					p = ((piy - tmp->Y1) * 100 / (tmp->Y3 - tmp->Y1));
					color = get_color(t__mlx, p, tmp->z, tmp->nexty->z);
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, tmp->X3 + t__mlx->hpadd, piy  + t__mlx->vpadd, color);
					piy = ( piy > tmp->Y3 ) ? piy - 1 : piy + 1;
				}
			}
			tmp=tmp->nexty;
		}
	}
}


static inline void	line_Y_x(t_init *t__mlx)
{
	int	color;
	t_coord	*tmp;
	t_coord	*cursorx;
	int	pix;
	float ordo;
	float coeffdir;
	int p;

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
				ordo = tmp->Y1 - (coeffdir * tmp->X1);
				while (pix != tmp->X3)
				{
					p = ((pix - tmp->X1) * 100 / (tmp->X3 - tmp->X1));
					color = get_color(t__mlx, p, tmp->z, tmp->nexty->z);
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, pix + t__mlx->hpadd, (coeffdir * pix) + ordo + t__mlx->vpadd, color);
					pix = ( pix > tmp->X3 ) ? pix - 1 : pix + 1;
				}
			}
			tmp = tmp->nexty;
		}
	}
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

	line_Y_x(t_init_mlx);
	line_Y_y(t_init_mlx);
	line_X_x(t_init_mlx);
	line_X_y(t_init_mlx);
	//	put_line(t_init_mlx, t_init_mlx->coord[0]);
	//	fullcolor(t_init_mlx);
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
