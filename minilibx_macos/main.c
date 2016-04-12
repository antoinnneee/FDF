/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:52:58 by abureau           #+#    #+#             */
/*   Updated: 2016/04/12 15:12:29 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
	void	*mlx_ptr = NULL;
	void	*win = NULL;

	mlx_ptr = mlx_init();
	mlx_loop(mlx_ptr);
	win = mlx_new_windows(mlx_ptr, 100, 100, "42 FDF Test");
	return(0);


}
