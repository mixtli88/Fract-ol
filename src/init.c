#include "../inc/fractol.h"
// #include "../lib/MLX42/include/MLX42/MLX42_Int.h"

void fractol_init(t_data *fractal)
{
	
	if(!(fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, false)))
		exit(EXIT_SUCCESS);
	if(!(fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(fractal->mlx);
		exit(EXIT_SUCCESS);
	}
	// printf("%f", fractal->dim_x_max);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}