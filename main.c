/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:52:58 by abureau           #+#    #+#             */
/*   Updated: 2016/04/12 16:51:37 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//static int mlx_mouse_hook(void *win, int, )
/*typedef struct void* mlxparam{
	void *mlx;
	void *win;
} mlp;
*/

int my_key_func(int keycode, void *param)
{
	static int i = 0;
	printf("key code : %d", keycode);
//		mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0x00FFFFFF);
	exit(0);
	return(0);
}

int main(void)
{
	printf("loob begin");
	void	*mlx_ptr;
	void	*win_ptr;
	int		i = 0;


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "42 FDF");
	while (i++ < 300)
		mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0x00FFFFFF);

	mlx_key_hook(win_ptr, my_key_func, 0);
	mlx_loop(mlx_ptr);
	return(0);


}
