
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

void	line_X_y(t_init *t__mlx)
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
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, (piy - ordo) /  coeffdir + t__mlx->hpadd, piy + t__mlx->vpadd, color);
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


void	line_X_x(t_init *t__mlx)
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

void	line_Y_y(t_init *t__mlx)
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
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, (piy - ordo) / coeffdir + t__mlx->hpadd, piy  + t__mlx->vpadd, color);
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


void	line_Y_x(t_init *t__mlx)
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
			else
			{
				while (pix != tmp->X3)
				{
					p = ((pix - tmp->Y1) * 100 / (tmp->X3 - tmp->X1));
					color = get_color(t__mlx, p, tmp->z, tmp->nexty->z);
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, tmp->X3 + t__mlx->hpadd, pix  + t__mlx->vpadd, color);
					pix = ( pix > tmp->Y3 ) ? pix - 1 : pix + 1;
				}
			}
			tmp = tmp->nexty;
		}
	}
}


void	drawfunc(t_init *t__mlx)
{
	t_coord	*tmp;
	t_coord	*cursorx;

	cursorx = t__mlx->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		cursorx = cursorx->nextx;
		while (tmp != NULL)
		{
			if (tmp->nextx)
				drawfcase(tmp, t__mlx);
//			if (tmp->nexty)
//				drawfcase2(tmp, t__mlx);
			tmp = tmp->nexty;
		}
	}
}
static int invert2coord(t_coord *t_dot)
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
static void	init2draw(t_coord *dot, t_math *value)
{
	if (dot->X1 >= dot->X3)
	{
		value->dx = dot->X1 - dot->X3;
		value->dy = dot->Y1 - dot->Y3;
	}
	else
	{
		value->dx = dot->X3 - dot->X1;
		value->dy = dot->Y1 - dot->Y3;
	}
	if (value->dx >= value->dy)
	{
		value->dp = 2 * value->dy - value->dx;
		value->deltaE = 2 * value->dy;
		value->deltaNE = 2 * (value->dy - value->dx) ;
	}
	else
	{
		value->dp = 2 * value->dx - value->dy;
		value->deltaE = 2 * value->dx;
		value->deltaNE = 2 * (value->dx - value->dy);
	}
	value->x = dot->X3;
	value->y = dot->Y3;

}

void	drawfcase2(t_coord *t_dot, t_init *t__mlx)
{
	t_math	value;
	int	inv;
	int	p;
	int	color;

	inv = 0;
	if (t_dot->Y1 < t_dot->Y3)
	{
		inv = 1;
		invert2coord(t_dot);
	}
	init2draw(t_dot, &value);
	mlx_pixel_put(t__mlx->mlx, t__mlx->win, value.x+ t__mlx->hpadd, value.y + t__mlx->vpadd, CBLU);
	while (value.x != t_dot->X1)
    	{
		if (value.dp <= 0)             /* On choisit le point E */
		{
			value.dp = value.dp + value.deltaE;    /* Nouveau dp */
			if (t_dot->X1 >= t_dot->X3)
			{
				if (value.dx >= value.dy)
					value.x++;
				else
					value.y++;
			}
			else
			{
				if (value.dx >= value.dy)
					value.x--;
				else
				{
					value.y++;
				}
			}
		}
		else                     /* On choisit le point NE */
		{
			value.dp = value.dp + value.deltaNE;   /* Nouveau dp */
			if (t_dot->X1 >= t_dot->X3)
			{
					value.x++;
					value.y++;
			}
			else
			{
					value.x--;
					value.y++;
			}
		}
		if (t_dot->X1 < t_dot->X3)
			p = 100 - ((value.x - t_dot->X1) * 100 / (t_dot->X3 - t_dot->X1));
		else
			p = ((value.x - t_dot->X1) * 100 / (t_dot->X3 - t_dot->X1));
		color = get_color(t__mlx, p, t_dot->z, t_dot->nexty->z);
		mlx_pixel_put(t__mlx->mlx, t__mlx->win, value.x+ t__mlx->hpadd, value.y + t__mlx->vpadd, color);
	}
	while (value.x == t_dot->X1 && value.y != t_dot->Y1)
	{
		p = 100 - ((value.y - t_dot->Y1) * 100 / (t_dot->Y3 - t_dot->Y1));
		color = get_color(t__mlx, p, t_dot->z, t_dot->nexty->z);
		mlx_pixel_put(t__mlx->mlx, t__mlx->win, value.x+ t__mlx->hpadd, ++value.y + t__mlx->vpadd, color);
	}
	if (inv)
	{
	invert2coord(t_dot);
	}
}

static int invertcoord(t_coord *t_dot)
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
static void	initdraw(t_coord *dot, t_math *value)
{
	if (dot->X1 >= dot->X2)
	{
		value->dx = dot->X1 - dot->X2;
		value->dy = dot->Y1 - dot->Y2;
	}
	else
	{
		value->dx = dot->X2 - dot->X1;
		value->dy = dot->Y1 - dot->Y2;
	}
	if (value->dx >= value->dy)
	{
		value->dp = 2 * value->dy - value->dx;
		value->deltaE = 2 * value->dy;
		value->deltaNE = 2 * (value->dy - value->dx) ;
	}
	else
	{
		value->dp = 2 * value->dx - value->dy;
		value->deltaE = 2 * value->dx;
		value->deltaNE = 2 * (value->dx - value->dy);
	}
	value->x = dot->X2;
	value->y = dot->Y2;

}



void	drawfcase(t_coord *t_dot, t_init *t__mlx)
{
	t_math	value;
	int	inv;

	inv = 0;
	int p;
	if (t_dot->Y1 < t_dot->Y2)
	{
		inv = 1;
		invertcoord(t_dot);
	}		
	initdraw(t_dot, &value);
	mlx_pixel_put(t__mlx->mlx, t__mlx->win, value.x+ t__mlx->hpadd, value.y + t__mlx->vpadd, CBLU);
	mlx_pixel_put(t__mlx->mlx, t__mlx->win, t_dot->X2 + t__mlx->hpadd, t_dot->Y2 + t__mlx->vpadd, CBLU);
	while (value.x != t_dot->X1)
    	{
		if (value.dp <= 0)             /* On choisit le point E */
		{
			value.dp = value.dp + value.deltaE;    /* Nouveau dp */
			if (t_dot->X1 >= t_dot->X2)
			{
				if (value.dx >= value.dy)
					value.x++;
				else
					value.y++;
			}
			else
			{
				if (value.dx >= value.dy)
					value.x--;
				else
				{
					value.y++;
				}
			}
		}
		else                     /* On choisit le point NE */
		{
			value.dp = value.dp + value.deltaNE;   /* Nouveau dp */
			if (t_dot->X1 >= t_dot->X2)
			{
					value.x++;
					value.y++;
			}
			else
			{
					value.x--;
					value.y++;
			}
		}
			if (inv)
			p = 100 - ((value.x - t_dot->X1) * 100 / (t_dot->X2 - t_dot->X1));
			else
			p = ((value.x - t_dot->X1) * 100 / (t_dot->X2 - t_dot->X1));
		int color = get_color(t__mlx, p, t_dot->z, t_dot->nextx->z);
		mlx_pixel_put(t__mlx->mlx, t__mlx->win, value.x+ t__mlx->hpadd, value.y + t__mlx->vpadd, color);
	}
	while (value.x == t_dot->X1 && value.y != t_dot->Y1)
	{
		mlx_pixel_put(t__mlx->mlx, t__mlx->win, value.x+ t__mlx->hpadd, ++value.y + t__mlx->vpadd, CORA);
	}
	if (inv)
	{
	invertcoord(t_dot);
	}
}




