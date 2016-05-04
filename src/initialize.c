/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:47:41 by abureau           #+#    #+#             */
/*   Updated: 2016/05/02 15:33:06 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include "../includes/get_number.h"
#include <mlx.h>

static void	dot_printing(t_init *t__mlx)
{
	int	cursor;
	int	line;

	cursor = 0;
	line = 0;

	while (line < t__mlx->nbr_map->nb_dim)
	{
		while (cursor < t__mlx->nbr_map->non[line])
		{
			mlx_pixel_put(t__mlx->mlx, t__mlx->win, cursor * 50 , line * 50 , 0x00FFFFFF);
			cursor++;
		}
	line++;
	cursor = 0;
	}
//	mlx_put_image_to_window(t__mlx->mlx, t__mlx->win, t__mlx->mypic, 10, 10);
}

static void	creat_window(t_init *t_init_mlx)
{
	t_init_mlx->win = mlx_new_window(t_init_mlx->mlx, WIDTH, HEIGHT, WIN_N);
	tryalloc(t__mlx->win);
	t_init_mlx->mypic = mlx_new_image(t_init_mlx->mlx, WIDTH, HEIGHT);
	tryalloc(t__mlx->mypic);
	dot_printing(t_init_mlx);
}

static void	tryalloc(void *ptr)
{
	if (!ptr)
	{
		ft_putendl("init error");
		exit(0);
	}
}

void		init_fdf(const char *str, t_init *t_init_mlx)
{
	int		**numberarray;
	t_map	*number_map;
	int		fd;

	fd = open(str, O_RDONLY);
	number_map = get_struct_value(get_number(open(str, O_RDONLY)));
	tryalloc(number_map);
	t_init_mlx = (t_init*)ft_memalloc(sizeof(t_init));
	tryalloc(t_init_mlx);
	t_init_mlx->nbr_map = number_map;
	t_init_mlx->wid = WIDTH;
	t_init_mlx->hei = HEIGHT;
	print_map_number(t_init_mlx->nbr_map);
	t_init_mlx->mlx = mlx_init();
	creat_window(t_init_mlx);
	mlx_mouse_hook(t_init_mlx->win, my_mouse_func, &t_init_mlx);
	mlx_key_hook(t_init_mlx->win, my_key_func, &t_init_mlx);
	mlx_loop(t_init_mlx->mlx);
}
