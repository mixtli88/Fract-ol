#include "../inc/fractol.h"

void key_hook(void* param)
{
	t_data *fractal= param;

	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	 if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
	{
		fractal->dim_y_max += 0.5;
		fractal->dim_y_min += 0.5;
	}
	 if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
	{
		fractal->dim_y_max -= 0.5;
		fractal->dim_y_min -= 0.5;
	}
	 if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
	{
		fractal->dim_x_max += 0.5;
		fractal->dim_x_min += 0.5;
	}
	 if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
	{
		fractal->dim_x_max -= 0.5;
		fractal->dim_x_min -= 0.5;
	}
	fractal_render(fractal);
}


void scrol_hook(double xdelta, double ydelta, void* param)
{
	t_data *fractal= param;
	xdelta = 0;
	if(ydelta > 0)
		fractal->zoom_scrol	*= 1.05;
	else
		fractal->zoom_scrol	/= 1.05;

	fractal_render(fractal);
}