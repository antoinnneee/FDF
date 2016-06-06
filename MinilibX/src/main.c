/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:52:58 by abureau           #+#    #+#             */
/*   Updated: 2016/05/18 17:59:37 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include <fcntl.h>

int	my_mouse_func(int button, int x, int y, void *param)
{
	ft_putstr("X value :");ft_putnbrnl(x);
	ft_putstr("Y value :");ft_putnbrnl(y);
	return (0);
}

void inline blackscreen(t_init *t__mlx)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while(x <= WIDTH)
	{
		x++;
		while (y <= HEIGHT)
		{
			mlx_pixel_put(t__mlx->mlx, t__mlx->win, x, y, 0X00);
			y++;
			
		}
		y = 0;
	}


}

int my_key_func(int keycode, void *param)
{
	int i = 0;
	static int j = 0;
	t_init *tmp;
		tmp = (t_init*)param;

	if (keycode == 53 || keycode == 65307)
	{
	//	freecoord((t_coord*)param->coord);
		exit(0);
	}
		blackscreen((t_init*)param);
	//	printf("coucou");
	if (keycode == 111)
	{
		tmp->an = tmp->an + 0.1;	
		tmp->clr = 1;	
	}
	if (keycode == 112)
	{
		tmp->an = tmp->an - 0.1;
		tmp->clr = 0;	
	}
	if (keycode == 65361)
	{
		tmp->hpadd = tmp->hpadd - 40;	
	}
	if (keycode == 65362)
	{
		tmp->vpadd = tmp->vpadd - 35;	
	}
	if (keycode == 65363)
	{
		tmp->hpadd = tmp->hpadd + 40;	
	}
	if (keycode == 65364)
	{
		tmp->vpadd = tmp->vpadd + 35;	
	}
	if (keycode == 38)
	{
		tmp->space = tmp->space + 50;
	}
	if (keycode == 233)
	{
		tmp->space = tmp->space - 1;
	}
	if (keycode == 40)
	{
//		tmp->rotz = tmp->rotz + 0.1;
	}
	if (keycode == 45)
	{
//		tmp->rotz = tmp->rotz - 0.1;
	}
	if (keycode == 39)
	{
		tmp->mod = tmp->mod + 0.5;
	}
	if (keycode == 34)
	{
		tmp->mod = tmp->mod - 0.5;
	}
		creat_window(tmp);
	//	printf("coucou");
	//	printf("coucou");
	//	mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0x00FFFFFF);
	return(0);
}

int main(int a, char **b)
{
	t_init	p;
	init_fdf(b[1], &p);
	return(0);


}
