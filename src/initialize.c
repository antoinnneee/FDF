/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:47:41 by abureau           #+#    #+#             */
/*   Updated: 2016/04/26 16:18:48 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include "../includes/get_number.h"
#include <mlx.h>

static void creat_window(t_init *i_mlx)
{
	;
}

static void	tryalloc(void	*ptr)
{
	if (!ptr)
	{
		ft_putendl("init error");
		exit(0);
	}
}

void	Init_fdf(const char *str, t_init *t_init_mlx)
{
	int	**numberarray;
	t_map	*number_map;

	int fd = open(str, O_RDONLY);
	number_map = get_struct_value(get_number(open(str, O_RDONLY)));
	tryalloc(number_map);
	t_init_mlx = (t_init*)ft_memalloc(sizeof(t_init));
	tryalloc(t_init_mlx);
	t_init_mlx->nbr_map = number_map;
	t_init_mlx->wid = WIDTH;
	t_init_mlx->hei = HEIGHT;
	ft_putstr("print tab \n");
	print_map_number(t_init_mlx->nbr_map);
	t_init_mlx->mlx = mlx_init();
	t_init_mlx->win = mlx_new_window(t_init_mlx->mlx, WIDTH, HEIGHT, WIN_N);
	mlx_mouse_hook(t_init_mlx->win, my_mouse_func, &t_init_mlx);
	mlx_key_hook(t_init_mlx->win, my_key_func, &t_init_mlx);
	mlx_loop(t_init_mlx->mlx);

}





