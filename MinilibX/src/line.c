
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
					mlx_pixel_put(t__mlx->mlx, t__mlx->win, (piy - ordo) / coeffdir + t__mlx->hpadd, piy + t__mlx->vpadd, color);
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
			tmp = tmp->nexty;
		}
	}
}

