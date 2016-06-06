#ifndef __FDF_H
# define __FDF_H
# include "../libft/includes/libft.h"
# include "./get_next_line.h"
# include "./get_nbr.h"

# define WIDTH 650
# define HEIGHT 600
# define WIN_N "42 FDF map"
# define PADD 20
# define SPACE 15
# define CCYA 0X0000FFFF
# define CRED 0X00FF0000
# define CWHI 0X00FFFFFF
# define CORA 0X00FF7500
# define CYEL 0X00FFFF00
# define CGRE 0X0000FF00
# define CBLU 0X000000FF
# define CPIN 0X00FF00FF
# define CBLA 0X00000000

# define RP0 (unsigned int)(((p_now - 0.) * 5.)* 0XFF/ 100.)
# define RP20 (unsigned int)(((p_now - 20.) * 5.)* 0XFF/ 100.)
# define RP40 (unsigned int)(((p_now - 40.) * 5.)* 0XFF/ 100.)
# define RP60 (unsigned int)(((p_now - 60.) * 5.)* 0XFF/ 100.)
# define RP80 (unsigned int)(((p_now - 80.) * 5.)* 0XFF/ 100.)


# define X1 x
# define Y1 y
# define X2 nextx->x
# define Y2 nextx->y
# define X3 nexty->x
# define Y3 nexty->y

# define LOW_RANGE rangen[0]
# define MAX_RANGE rangen[1]
# define RANGE rangen[2]

typedef struct	s_dot
{
	int	x;
	int	y;
	int	z;
	
}t_dot;

typedef struct s_egment_param
{
	int	xa;
	int	xb;
	int	ya;
	int	yb;
	int	color;
}t_segment;


typedef struct	s_math
{
	float	dx;
	float	dy;
	float	dp;
	float	deltaE;
	float	deltaNE;
	int	x;
	int	y;

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
	float		an;
	int		space;
	int		isset;
	float		mod;
	int		clr;
	void		*mlx;
	void		*win;
	float		rotz;
	float		roty;
	float		val;
	float		val2;
	float		val3;
	float		val4;
}t_init;

typedef struct s_edr
{
	float ordo;
	float coeffdir;
}t_edr;
void		creat_window(t_init *t_init_mlx);
void		line_X_y(t_init *t__mlx);
void		line_X_x(t_init *t__mlx);
void		line_Y_y(t_init *t__mlx);
void		line_Y_x(t_init *t__mlx);
void		freecoord(t_coord *begin);
void		init_Fdf(const char *str, t_init t_init_mlx);
int		get_color(t_init *t__mlx, int per, int value, int next);
int		my_mouse_func(int button, int x, int y, void *param);
int		get_color_def(int p);
int		my_key_func(int keycode, void *param);
void		put_line(t_init *t__mlx, t_coord *coord);
void		setcoord(t_init *t_mlx, t_coord * coord);
int		percent(int low_range, int max_range, int value);
void		drawfunc(t_init *t__mlx);
void		drawfcase(t_coord *t_dot, t_init *t__mlx);
void		drawfcase2(t_coord *t_dot, t_init *t__mlx);
#endif
