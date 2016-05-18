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

int my_key_func(int keycode, void *param)
{
	int i = 0;
	static int j = 0;
	write(0, "key ", 5);
		ft_putnbrnl(keycode);
	if (keycode == 53 || keycode == 65307)
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
	init_fdf(b[1], &p);
	return(0);


}
