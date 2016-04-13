/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:52:58 by abureau           #+#    #+#             */
/*   Updated: 2016/04/13 16:03:26 by abureau          ###   ########.fr       */
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

int my_key_func(int keycode, void *param)
{
	int i = 0;
	static int j = 0;
	t_params *p;
	write(0, "key", 4);
	p = (t_params*) param;
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

	mlx_key_hook(p.win, my_key_func, &p);
	mlx_loop(p.mlx);
	return(0);


}
