/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:42:07 by abureau           #+#    #+#             */
/*   Updated: 2016/06/06 20:16:22 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include <fcntl.h>

inline void	blackscreen(t_init *t__mlx)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (x <= WIDTH)
	{
		while (y <= HEIGHT)
		{
			mlx_pixel_put(t__mlx->mlx, t__mlx->win, x, y, 0X00);
			y++;
		}
		x++;
		y = 0;
	}
}

int		my_key_func(int keycode, void *param)
{
	t_init	*tmp;

	tmp = (t_init*)param;
	if (keycode == 53 || keycode == 65307)
		exit(0);
	if (keycode == 65362 || keycode == 126)
		tmp->vpadd = tmp->vpadd - 35;
	if (keycode == 65364 || keycode == 125)
		tmp->vpadd = tmp->vpadd + 35;
	if (keycode == 38 || keycode == 19)
		tmp->space = tmp->space + 5;
	if (keycode == 233 || keycode == 18)
		tmp->space = tmp->space - 5;
	if (keycode == 39 || keycode == 21)
		tmp->mod = tmp->mod + 0.5;
	if (keycode == 34 || keycode == 20)
		tmp->mod = tmp->mod - 0.5;
	tmp->an = (keycode == 35 || keycode == 111) ? tmp->an + 1 : tmp->an;
	tmp->an = (keycode == 31 || keycode == 112) ? tmp->an - 1 : tmp->an;
	tmp->acwin[4].isobtain = ((tmp->acwin[4].isobtain == 0 && (keycode == 34 || keycode == 20 || keycode == 39 || keycode == 21))) ? 1: tmp->acwin[4].isobtain;
	tmp->acwin[3].isobtain = ((tmp->acwin[3].isobtain == 0 && (keycode == 35 || keycode == 111 || keycode == 31 || keycode == 112))) ? 1: tmp->acwin[3].isobtain;
	tmp->hpadd = (keycode == 123) ? tmp->hpadd - 40 : tmp->hpadd;
	tmp->hpadd = (keycode == 124) ? tmp->hpadd + 40 : tmp->hpadd;
//	blackscreen((t_init*)param);
	achievement(tmp);
	return (0);
}

int		main(int a, char **b)
{
	t_init	p;

	if (a != 2)
		return (0);
	init_fdf(b[1], &p);
	return (0);
}
