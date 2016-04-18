#ifndef __FDF_H
#define __FDF_H
#include "GNL_NOFD/libft/includes/libft.h"
#include "GNL_NOFD/get_next_line.h"
typedef struct s_lol
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	int		color;
}t_params;

typedef struct s_init
{
	void	*nbr_list;
	void	*nbr_col_end;
	void	*nbr_line_end;
}t_init;

t_init		count_nbr(int fd);

#endif
