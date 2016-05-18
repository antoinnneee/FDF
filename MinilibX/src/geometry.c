
#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include "../libft/includes/libft.h"
#include "../includes/get_nbr.h"
#include "../mlx/mlx.h"

void	put_line(t_init *t__mlx, t_coord *coord)
{
	t_coord t_vector;
	int		pix;
	int		piy;
	t_vector.x = coord[1].x - coord[0].x;
	t_vector.y = coord[1].y - coord[0].y;
	pix = coord[0].x;
	piy = coord[0].y;
	while (pix < coord[1].x)
	{
		int x = t_vector.x * pix;
		int	y = t_vector.y * piy;
		mlx_pixel_put(t__mlx->mlx, t__mlx->win, x , y, COLORBLU);
		pix += pix * t_vector.x;
		piy += piy * t_vector.y;
	}
}





