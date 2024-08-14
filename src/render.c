#include "../inc/fractol.h"



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