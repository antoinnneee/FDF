#include "../includes/fdf.h"
#include "../includes/achievement.h"

static void	drawachievement(t_init *t__mlx, char *str)
{
	int			limR;
	int			limD;
	int			index;
	int			pix;

	limR = WIDTH - 100;
	limD = HEIGHT - 40;
	index = 100;
	pix = limD - 150;
	while (index != limR)
	{
		while (++pix != limD)
		{
			if (pix < limD - 110)
				mlx_pixel_put(t__mlx->mlx,t__mlx->win, index, pix, CGRE);
			else
				mlx_pixel_put(t__mlx->mlx,t__mlx->win, index, pix, 0X00C0C0C0);

		}
		index++;
		pix = limD - 150;
	}
}

static t_ggwin	init_elem(const char *str, int state)
{
	t_ggwin	achi;

	achi.str = ft_strdup(str);
	achi.isobtain = state;
	return (achi);
}

t_ggwin		*init_achi()
{
	t_ggwin *tabachi;

	tabachi = (t_ggwin*) ft_memalloc(sizeof(t_ggwin) * 5);
	tabachi[0] = init_elem("./fdf [map]\0", 1);
	tabachi[1] = init_elem("Earn achievement\0", 1);
	tabachi[2] = init_elem("MULTI ACHIEVEMENT, you receive 2 achievement in same time\0", 1);
	tabachi[3] = init_elem("DO A BARREL ROLL\0", 0);
	tabachi[4] = init_elem("More relief, more beauty\0", 0);
	return (tabachi);
}

void		achievement(t_init *t__mlx)
{
	int	id;

	id = 0;
	while (id < 5)
	{
		if (1 == t__mlx->acwin[id].isobtain)
		{
			drawachievement(t__mlx, t__mlx->acwin[id].str);
			t__mlx->acwin[id].isobtain = 2;
			mlx_string_put(t__mlx->mlx, t__mlx->win, 120, HEIGHT - 165, CRED, "New achievement earn");
			mlx_string_put(t__mlx->mlx, t__mlx->win, 120, HEIGHT - 135, CRED, t__mlx->acwin[id].str);
			sleep(2);
			creat_window(t__mlx);
		}
	id++;
	}
	blackscreen(t__mlx);
	creat_window(t__mlx);
}
