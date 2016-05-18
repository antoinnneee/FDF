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
# define CCYA 0X0000FFFF
# define CRED 0X00FF0000
# define CWHI 0X00FFFFFF
# define CORA 0X00FF7500
# define CYEL 0X00FFFF00
# define CGRE 0X0000FF00
# define CBLU 0X000000FF
# define CPIN 0X00FF00FF

# define RP0 (unsigned int)(((p_now - 0.) * 5.)* 0XFF/ 100.)
# define RP20 (unsigned int)(((p_now - 20.) * 5.)* 0XFF/ 100.)
# define RP40 (unsigned int)(((p_now - 40.) * 5.)* 0XFF/ 100.)
# define RP60 (unsigned int)(((p_now - 60.) * 5.)* 0XFF/ 100.)
# define RP80 (unsigned int)(((p_now - 80.) * 5.)* 0XFF/ 100.)


# define X1 t__mlx->coord->x
# define Y1 t__mlx->coord->y
# define X2 t__mlx->coord->nextx->x
# define Y2 t__mlx->coord->nextx->y
# define X3 t__mlx->coord->nexty->x
# define Y3 t__mlx->coord-nexty->y

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

typedef struct s_init
{
	t_coord	*coord;
	int		*rangen;
	int		wid;
	int		hei;
	int		rangc;
	int		hpadd;
	int		vpadd;
	void	*mlx;
	void	*win;
}t_init;

void		init_Fdf(const char *str, t_init t_init_mlx);
int			get_color(t_init *t__mlx, int per, int value, int next);
int			my_mouse_func(int button, int x, int y, void *param);
int			get_color_def(int p);
int			my_key_func(int keycode, void *param);
void		put_line(t_init *t__mlx, t_coord *coord);

#endif
