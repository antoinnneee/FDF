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
static void	tryalloc(void *ptr)
{
	if (!ptr)
	{
		ft_putendl("init error");
		exit(0);
	}

}
/*
static void	dot_printing(t_init *t__mlx)
{
	int	cursor;
	int	line;
	t_coord	**coord;
	int p;
	int color;

	coord = NULL;
	cursor = 0;
	line = 0;
	coord = (t_coord**) ft_memalloc(sizeof(t_coord*) * t__mlx->nbr_map->nb_dim);
	while (line < t__mlx->nbr_map->nb_dim)
	{
		coord[line] = (t_coord *) ft_memalloc(sizeof(t_coord) * t__mlx->nbr_map->non[line] );
		while (cursor < t__mlx->nbr_map->non[line])
		{
			color = get_color(t__mlx, 100, line,cursor);
			coord[line][cursor].x = cursor * SPACE + PADD;
			coord[line][cursor].y = line * SPACE + PADD;
			mlx_pixel_put(t__mlx->mlx, t__mlx->win, coord[line][cursor].x , coord[line][cursor].y , color);
			cursor++;
		}
		line++;
		cursor = 0;
	}
	t__mlx->coord = coord;
}
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
		}	
		index++;
		pix = limit[0].x;
	}
}

static void	creat_window(t_init *t_init_mlx)
{
	t_init_mlx->win = mlx_new_window(t_init_mlx->mlx, WIDTH, HEIGHT, WIN_N);
	tryalloc(t_init_mlx->win);
//	dot_printing(t_init_mlx);
	//	line(t_init_mlx);

//	lineR(t_init_mlx);
//	lineD(t_init_mlx);
	definition(t_init_mlx);
//	put_line(t_init_mlx, t_init_mlx->coord[0]);
//	fullcolor(t_init_mlx);
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

	t_init_mlx->coord = numberarray;
	

//	t_init_mlx->nbr_map = number_map;
	t_init_mlx->wid = WIDTH;
	t_init_mlx->hei = HEIGHT;
	explore(t_init_mlx->coord);
	ft_putendl("explore Ok");

	t_init_mlx->rangen = get_range(numberarray);
//	print_map_number(t_init_mlx->nbr_map);
	t_init_mlx->mlx = mlx_init();
	creat_window(t_init_mlx);
	mlx_mouse_hook(t_init_mlx->win, my_mouse_func, &t_init_mlx);
	mlx_key_hook(t_init_mlx->win, my_key_func, &t_init_mlx);
	mlx_loop(t_init_mlx->mlx);
	}
