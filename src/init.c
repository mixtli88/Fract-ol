#include "../inc/fractol.h"

void fractol_init(t_data *fractal)
{
	
	if(!(fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, false)))
		exit(EXIT_SUCCESS);
	if(!(fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(fractal->mlx);
		exit(EXIT_SUCCESS);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	
}