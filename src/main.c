/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:52:58 by abureau           #+#    #+#             */
/*   Updated: 2016/04/26 15:52:33 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include <fcntl.h>

//static int mlx_mouse_hook(void *win, int, )
/*typedef struct void* mlxparam{
	void *mlx;
	void *win;
} mlp;
*/
void	printsquare(t_params *p, int fill)
{
	int		xbeg;
	int		ybeg;
	int		xend;
	int		yend;
	int		xc;
	int		yc;


	xbeg = *((int*) p->p1) - *((int*) p->p3) / 2;
	yend = *((int*) p->p2) + *((int*) p->p3) / 2;
	xend = *((int*) p->p1) + *((int*) p->p3) / 2;
	ybeg = *((int*) p->p2) - *((int*) p->p3) / 2;
	xc = xbeg;
	yc = ybeg;

	while (xc <= xend && yc <= yend)
	{
		while (xc <= xend)
		{
			if (fill)
				mlx_pixel_put(p->mlx, p->win, xc, yc, 0x00FF0000);
			else
			{
				if (xc == xbeg || xc == xend || yc == yend || yc == ybeg)
				mlx_pixel_put(p->mlx, p->win, xc, yc, p->color);
			}
			xc++;
		}
		yc++;
		xc = xbeg;
	}
}

int	my_mouse_func(int button, int x, int y, void *param)
{
	ft_putstr("X value :");ft_putnbrnl(x);
	ft_putstr("Y value :");ft_putnbrnl(y);
	return (0);
}

int my_key_func(int keycode, void *param)
{
	int i = 0;
	static int j = 0;
	write(0, "key ", 5);
		ft_putnbrnl(keycode);
	if (keycode == 53)
	{
		exit(0);
	}
	//	printf("coucou");
	//	mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0x00FFFFFF);
	return(0);
}

int main(int a, char **b)
{
	t_init	p;
	Init_fdf(b[1], &p);
	mlx_mouse_hook(p.win, my_mouse_func, &p);
	mlx_key_hook(p.win, my_key_func, &p);
	mlx_loop(p.mlx);
	return(0);


}
