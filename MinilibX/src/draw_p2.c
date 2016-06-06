/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:43:17 by abureau           #+#    #+#             */
/*   Updated: 2016/06/06 17:58:18 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		chose_dpne2(t_math *value, t_coord *t_dot)
{
	value->dp = value->dp + value->deltaNE;
	if (t_dot->X1 >= t_dot->X3)
		ft_inctwovar(&value->y, &value->x);
	else
		ft_incdecvar(&value->y, &value->x);
}

static void		chose_dpe2(t_math *value, t_coord *t_dot)
{
	value->dp = value->dp + value->deltaE;
	if (t_dot->X1 >= t_dot->X3)
	{
		if (value->dx >= value->dy)
			value->x++;
		else
			value->y++;
	}
	else
	{
		if (value->dx >= value->dy)
			value->x--;
		else
			value->y++;
	}
}

static void		weirdcase2(t_math *value, t_coord *t_dot, int *p, t_init *t_mlx)
{
	while (value->x == t_dot->X1 && value->y != t_dot->Y1)
	{
		if (value->inv)
			*p = 100 - ((value->y - t_dot->Y1) * 100 / (t_dot->Y3 - t_dot->Y1));
		else
			*p = ((value->y - t_dot->Y1) * 100 / (t_dot->Y3 - t_dot->Y1));
		mlx_pixel_put(t_mlx->mlx, t_mlx->win, value->x + t_mlx->hpadd,
	++value->y + t_mlx->vpadd, get_clr(t_mlx, *p, t_dot->z, t_dot->nexty->z));
	}
	if (value->inv)
		invert2coord(t_dot);
}

static void		init2draw(t_coord *dot, t_math *value)
{
	if (dot->X1 >= dot->X3)
	{
		value->dx = dot->X1 - dot->X3;
		value->dy = dot->Y1 - dot->Y3;
	}
	else
	{
		value->dx = dot->X3 - dot->X1;
		value->dy = dot->Y1 - dot->Y3;
	}
	if (value->dx >= value->dy)
	{
		value->dp = 2 * value->dy - value->dx;
		value->deltaE = 2 * value->dy;
		value->deltaNE = 2 * (value->dy - value->dx);
	}
	else
	{
		value->dp = 2 * value->dx - value->dy;
		value->deltaE = 2 * value->dx;
		value->deltaNE = 2 * (value->dx - value->dy);
	}
	value->x = dot->X3;
	value->y = dot->Y3;
}

void			drawfcase2(t_coord *t_dot, t_init *t__mlx)
{
	t_math	value;
	int		p;

	value.inv = 0;
	if (t_dot->Y1 < t_dot->Y3)
	{
		value.inv = 1;
		invert2coord(t_dot);
	}
	init2draw(t_dot, &value);
	while (value.x != t_dot->X1)
	{
		if (value.dp <= 0)
			chose_dpe2(&value, t_dot);
		else
			chose_dpne2(&value, t_dot);
		if (value.inv)
			p = 100 - ((value.x - t_dot->X1) * 100 / (t_dot->X3 - t_dot->X1));
		else
			p = ((value.x - t_dot->X1) * 100 / (t_dot->X3 - t_dot->X1));
		mlx_pixel_put(t__mlx->mlx, t__mlx->win, value.x + t__mlx->hpadd, value.y
	+ t__mlx->vpadd, get_clr(t__mlx, p, t_dot->z, t_dot->nexty->z));
	}
	weirdcase2(&value, t_dot, &p, t__mlx);
}
