/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:52:58 by abureau           #+#    #+#             */
/*   Updated: 2016/04/12 15:33:50 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
static int mlx_mouse_hook(void *win, int, )

int main(void)
{
	void	*mlx_ptr = NULL;
	void	*win = NULL;
	int		i = 0;


	mlx_ptr = mlx_init();
	win = mlx_new_window(mlx_ptr, 300, 300, "42 FDF");
	while (i++ < 300)
		mlx_pixel_put(mlx_ptr, win, i, i, 0xffffff);
	mlx_loop(mlx_ptr);
	return(0);


}
