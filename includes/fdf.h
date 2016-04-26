#ifndef __FDF_H
# define __FDF_H
# include "../libft/includes/libft.h"
# include "./get_next_line.h"
# include "./get_number.h"

# define WIDTH 100
# define HEIGHT 100
# define WIN_N "42 FDF map"

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
	t_map	*nbr_map;
	int		wid;
	int		hei;

	void	*mlx;
	void	*win;

	int		nbpic;
	void	**mypic;
}t_init;

void		Init_Fdf(const char *str, t_init t_init_mlx);
void		printsquare(t_params *p, int fill);
int			my_mouse_func(int button, int x, int y, void *param);
int			my_key_func(int keycode, void *param);

#endif
