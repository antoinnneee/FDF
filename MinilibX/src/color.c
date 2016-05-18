/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:57:36 by abureau           #+#    #+#             */
/*   Updated: 2016/05/18 18:05:57 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include "../libft/includes/libft.h"
#include "../includes/get_nbr.h"
#include "../mlx/mlx.h"

static int		color_chose(double p_now)
{
	if (p_now == 0)
		return (CWHI);
	else if (p_now <= 20)
	{
		return (CWHI - (RP0 << 16) - (RP0 << 8));
	}
	else if (p_now <= 40)
	{
		return (CBLU + (RP20 << 8));
	}
	else if (p_now <= 60)
	{
		return (CCYA - (RP40));
	}
	else if (p_now <= 80)
	{
		return (CGRE + (RP60 << 16));
	}
	else
	{
		return (CYEL - (RP80 << 8));
	}
}

int get_color_def(int p)
{
	double p_now;
	
	p_now = p;
	return (color_chose(p_now));
}

int		get_color(t_init *t__mlx, int per, int value, int next)
{
	double p_start;
	double p_now;
	double p_end;

	if (value == next)
	{
		p_start = (value - t__mlx->LOW_RANGE) * 100 / t__mlx->RANGE;
		p_now = p_start;
		per = p_start;
	}
	else
	{
		p_start = (value - t__mlx->LOW_RANGE) * 100 / t__mlx->RANGE;
		p_end = (next - t__mlx->LOW_RANGE) * 100 / t__mlx->RANGE;
		p_now = p_start + (per * ((p_end - p_start) / 100));
	}
	return (color_chose(p_now));
}
