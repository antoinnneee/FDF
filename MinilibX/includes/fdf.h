#ifndef __FDF_H
# define __FDF_H
# include "../libft/includes/libft.h"
# include "./get_next_line.h"
# include "./get_nbr.h"

# define WIDTH 350
# define HEIGHT 600
# define WIN_N "42 FDF map"
# define PADD 15
# define SPACE 60
# define COLORCYA 0X0000FFFF
# define COLORRED 0X00FF0000
# define COLORWHI 0X00FFFFFF
# define COLORORA 0X00FF7500
# define COLORYEL 0X00FFFF00
# define COLORGRE 0X0000FF00
# define COLORBLU 0X000000FF
# define COLORPIN 0X00FF00FF
# define COLORGR2 0X00007500

# define X1 t__mlx->coord[line][cursor].x
# define Y1 t__mlx->coord[line][cursor].y
# define X2 t__mlx->coord[line][cursor+1].x
# define Y2 t__mlx->coord[line][cursor+1].y
# define X3 t__mlx->coord[line+1][cursor].x
# define Y3 t__mlx->coord[line+1][cursor].y

# define LOW_RANGE rangen[0]
# define MAX_RANGE rangen[1]
# define RANGE rangen[2]

typedef struct	s_dot
{
	int	x;
	int	y;
	int	z;
	
}t_dot;

typedef struct	s_math
{
	int delta_x;
	int delta_y;

}		t_math;

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
	t_coord	*coord;
	int		*rangen;
	int		wid;
	int		hei;
	int		rangc;
	int		hpadd;
	int		vpadd;
	
	void	*mlx;
	void	*win;

	int		nbpic;
	void	*mypic;
}t_init;

void		init_Fdf(const char *str, t_init t_init_mlx);
void		printsquare(t_params *p, int fill);
int			my_mouse_func(int button, int x, int y, void *param);
int			my_key_func(int keycode, void *param);
void		put_line(t_init *t__mlx, t_coord *coord);

#endif
