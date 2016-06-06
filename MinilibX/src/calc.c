/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:55:08 by abureau           #+#    #+#             */
/*   Updated: 2016/06/06 14:56:06 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

static void	resetcoord(t_init *t__mlx, t_coord *coord)
{
	int	tmpnz;
	int	angz;
	int	fangz;

	if (coord->nexty)
	{
		tmpnz = percent(t__mlx->LOW_RANGE, t__mlx->MAX_RANGE, coord->nexty->z);
		angz = percent(t__mlx->LOW_RANGE, t__mlx->MAX_RANGE, coord->nexty->z)
			- percent(t__mlx->LOW_RANGE, t__mlx->MAX_RANGE, coord->z);
		fangz = (angz) * (t__mlx->space * t__mlx->mod) / 100.;
		t__mlx->val3 = 1 * cos(t__mlx->an + M_PI / 2 + t__mlx->rotz)
			- 1 * sin(t__mlx->an + M_PI / 2 - t__mlx->rotz);
		coord->nexty->x = t__mlx->val3 * t__mlx->space + coord->x;
		t__mlx->val4 = 1 * sin(t__mlx->an + M_PI / 2 + t__mlx->roty)
			+ 1 * cos(t__mlx->an + M_PI / 2 + t__mlx->roty);
		coord->nexty->y = t__mlx->val4 * t__mlx->space + coord->y - fangz;
	}
}

void		setcoord(t_init *t__mlx, t_coord *coord)
{
	int	tmpnz;
	int	angz;
	int	fangz;

	if (coord)
	{
		if (coord->nextx)
		{
			tmpnz = percent(t__mlx->LOW_RANGE, t__mlx->MAX_RANGE,
					coord->nextx->z);
			angz = tmpnz - percent(t__mlx->LOW_RANGE, t__mlx->MAX_RANGE,
					coord->z);
			fangz = (angz) * (t__mlx->space * t__mlx->mod) / 100;
			t__mlx->val = (1 * cos(t__mlx->an + t__mlx->rotz))
				- (1 * sin(t__mlx->an - t__mlx->rotz));
			t__mlx->val2 = (1 * sin(t__mlx->an + t__mlx->roty))
				+ (1 * cos(t__mlx->an - t__mlx->roty));
			coord->nextx->x = t__mlx->val * t__mlx->space + coord->x;
			coord->nextx->y = t__mlx->val2 * t__mlx->space + coord->y - fangz;
		}
		resetcoord(t__mlx, coord);
	}
}
