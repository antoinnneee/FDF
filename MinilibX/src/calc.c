#include "../includes/fdf.h"
#include <math.h>

static void	resetcoord(t_init *t__mlx, t_coord *coord);

void	setcoord(t_init *t__mlx, t_coord *coord)
{
		resetcoord(t__mlx, coord);
		return ;
//
		t__mlx->val = 01. * cos(t__mlx->an) - 1 * sin(t__mlx->an );
		t__mlx->val2 = 1. * sin(t__mlx->an) + 1 * cos(t__mlx->an);
		t__mlx->val3 = ( 1 * cos(t__mlx->an) - 1 * sin(t__mlx->an));
		t__mlx->val4 = ( 1 * sin(t__mlx->an) + 1 * cos(t__mlx->an));

//		t__mlx->val3 = 1. * cos(90 + t__mlx->an % 90) - 1. * sin(90 + t__mlx->an % 90);
//		t__mlx->val4 = 1. * sin(90 + t__mlx->an % 90) + 1. * cos(90 + t__mlx->an % 90);

		if (coord)
		{
			if (coord->nextx)
			{
				coord->nextx->x = t__mlx->val * t__mlx->space + (coord->x);
				coord->nextx->y = t__mlx->val2 * t__mlx->space + (coord->y);
			}
			if (coord->nexty)
			{
				coord->nexty->x = t__mlx->val3 * t__mlx->space + coord->x;
				coord->nexty->y = t__mlx->val4 * t__mlx->space + coord->y;
			}
		}
	t__mlx->isset = 1;
}


static void	resetcoord(t_init *t__mlx, t_coord *coord)
{
//				1. * cos(t__mlx->an) - 1. * sin(t__mlx->an);
//		t__mlx->val2 =				1. * sin(t__mlx->an) + 1. * cos(t__mlx->an);

//		t__mlx->val3 =  			( 1. * cos(t__mlx->an + 2) - 1. * sin(t__mlx->an + 2));
//		t__mlx->val4 = 	 		( 1. * sin(t__mlx->an + 2) + 1. * cos(t__mlx->an + 2));

//		t__mlx->val3 = 1. * cos(90 + t__mlx->an % 90) - 1. * sin(90 + t__mlx->an % 90);
//		t__mlx->val4 = 1. * sin(90 + t__mlx->an % 90) + 1. * cos(90 + t__mlx->an % 90);
// percent( t__mlx->LOW_RANGE, t__mlx->MAX_RANGE, coord->z )
	if (coord)
	{
		if (coord->nextx)
		{
			int tmpnz = percent(t__mlx->LOW_RANGE , t__mlx->MAX_RANGE, coord->nextx->z);
			int angz = tmpnz - percent(t__mlx->LOW_RANGE , t__mlx->MAX_RANGE, coord->z);
//			angz = (0.25) * angz / 100;
			ft_putstrnb("angz value : " , angz);
			int fangz = (angz ) * (t__mlx->space*t__mlx->mod) / 100;
			t__mlx->val = (1 * cos(t__mlx->an + t__mlx->rotz)) - (1 * sin(t__mlx->an - t__mlx->rotz));
			t__mlx->val2 = (1 * sin(t__mlx->an + t__mlx->roty))+ (1 * cos(t__mlx->an - t__mlx->roty));
			coord->nextx->x = t__mlx->val * t__mlx->space + coord->x;
			coord->nextx->y = t__mlx->val2 * t__mlx->space + coord->y - fangz;
		}
		if (coord->nexty)
		{
			int tmpnz = 0;
			tmpnz = percent(t__mlx->LOW_RANGE , t__mlx->MAX_RANGE, coord->nexty->z);
			int angz = 0;
				angz = percent(t__mlx->LOW_RANGE , t__mlx->MAX_RANGE, coord->nexty->z)  - percent(t__mlx->LOW_RANGE , t__mlx->MAX_RANGE, coord->z);
			float fangz = (angz) * (t__mlx->space * t__mlx->mod)/100.;
				t__mlx->val3 = 1 * cos(t__mlx->an + M_PI/2 + t__mlx->rotz ) - 1 * sin(t__mlx->an + M_PI/2 - t__mlx->rotz);
				coord->nexty->x = t__mlx->val3 * t__mlx->space + coord->x;
				t__mlx->val4 = 1 * sin(t__mlx->an + M_PI/2 + t__mlx->roty) + 1 * cos(t__mlx->an + M_PI/2 + t__mlx->roty);
				coord->nexty->y =  t__mlx->val4 * t__mlx->space  + coord->y - fangz;

		}
	}
}

/*
   if (coord->nextx)
   {
   coord->nextx->x = (float)t__mlx->val * SPACE + (coord->x);
   coord->nextx->y = (float)t__mlx->val2 * SPACE + (coord->y);
   }
   if (coord->nexty)
   {
   coord->nexty->x = (float)t__mlx->val3 * SPACE + coord->x;
   coord->nexty->y = (float)t__mlx->val4 * SPACE + coord->y;
   }

 */
