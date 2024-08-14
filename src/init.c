#include "../inc/fractol.h"
// #include "../lib/MLX42/include/MLX42/MLX42_Int.h"

void ft_hook(void* param)
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
	// fractal_render(fractal);
}

void fractol_init(t_data *fractal)
{
	
	if(!(fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, false)))
		exit(EXIT_SUCCESS);
	if(!(fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(fractal->mlx);
		exit(EXIT_SUCCESS);
	}
	// mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
