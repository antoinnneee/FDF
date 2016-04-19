/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:52:58 by abureau           #+#    #+#             */
/*   Updated: 2016/04/19 10:28:35 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"


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
	t_params	*p;
	int			len;

	ft_putstr("X value :");ft_putnbrnl(x);
	ft_putstr("Y value :");ft_putnbrnl(y);
	len = 50;
	p = (t_params*) param;
	p->p1 = &x;
	p->p2 = &y;
	p->p3 = &len; 
	
	printsquare(p, 0);
	return (0);
}

int my_key_func(int keycode, void *param)
{
	int i = 0;
	static int j = 0;
	t_params *p;
	write(0, "key", 4);
	p = (t_params*) param;
		ft_putnbrnl(keycode);
	if (keycode == 53)
	{
		exit(0);
	}
	else if (keycode == 125)
	{
		if (p->color == 0x00FF0000)
			p->color = 0x000000FF;
		else if (p->color == 0x000000FF)
			p->color = 0x0000FF00;
		else if (p->color == 0x0000FF00)
			p->color = 0x00FF0000;
		else
			p->color = 0x000000FF;
	}
	while (i++ < p->height)
	{
			mlx_pixel_put(p->mlx, p->win, i, i, j+=1);
	}
	//	printf("coucou");
	//	mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0x00FFFFFF);
	return(0);
}

int main(void)
{
	printf("loob begin\n");
	void			*mlx_ptr;
	void			*win_ptr;
	int				i = 0;
	unsigned int	j;
	t_params		p;

	j = 0;
	p.mlx = mlx_init();
	p.width = 1000;
	p.height = 1000;
	p.win = mlx_new_window(p.mlx, p.width, p.height, "42 FDF");
	while (i++ < 1000)
	{
			mlx_pixel_put(p.mlx, p.win, i, i, j+=0x00FF00);
	}

	mlx_mouse_hook(p.win, my_mouse_func, &p);
	mlx_key_hook(p.win, my_key_func, &p);
	mlx_loop(p.mlx);
	return(0);


}
