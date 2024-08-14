#include "../inc/fractol.h"

void ft_zoom_in(t_data *fractal)
{
	double zoom_factor = 0.5;

	fractal->dim_x_max -= zoom_factor;
	fractal->dim_x_min += zoom_factor;
	fractal->dim_y_max -= zoom_factor;
	fractal->dim_y_min += zoom_factor;
}

void ft_zoom_out(t_data *fractal)
{
	double zoom_factor = 0.5;

	fractal->dim_x_max += zoom_factor;
	fractal->dim_x_min -= zoom_factor;
	fractal->dim_y_max += zoom_factor;
	fractal->dim_y_min -= zoom_factor;
}


void fractal_render(t_data *fractal)
{
    int x;
    int y;
	
	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
			pixel_frac(x, y, fractal);
	}
	// mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}