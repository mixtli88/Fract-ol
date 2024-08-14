#include "../inc/fractol.h"
// #include "../lib/MLX42/include/MLX42/MLX42_Int.h"

void data_init(void* param)
{
	t_data *fractal = param;

	fractal->zoomin_in =true;
	fractal->zoom_scrol = 1;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->zoom_speed = 0.05;
	fractal->state = 0;
}


void ft_hooks(void *param)
{
	t_data *fractal = param;

	key_hook(fractal);
	mlx_scroll_hook(fractal->mlx, scrol_hook, fractal);
	// mlx_mouse_hook(fractal->mlx, mause_hook, fractal);
}

void fractol_init_mlx(t_data *fractal)
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
