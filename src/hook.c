#include "../inc/fractol.h"

// void key_hook(struct mlx_key_data key, void *param)
void	key_hook(void *param)
{
	t_data	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(fractal->mlx,fractal->img);
		mlx_close_window(fractal->mlx);
		free(fractal);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->move_y += 0.5 * fractal->zoom_scrol;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->move_y -= 0.5* fractal->zoom_scrol;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->move_x += 0.5* fractal->zoom_scrol;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->move_x -= 0.5* fractal->zoom_scrol;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_1))
		mlx_loop_hook(fractal->mlx, loop_zoom, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_2))
	 {
		fractal->zoom_scrol = 1;
	 }
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_ADD))
		fractal->iterations += 10;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_SUBTRACT))
		fractal->iterations -= 10;

	fractal_render(fractal);
}

void	scrol_hook(double xdelta, double ydelta, void *param)
{
	t_data	*fractal;

	fractal = param;
	xdelta = 0;
	if (ydelta > 0 && xdelta == 0)
		fractal->zoom_scrol /= 1.05;
	else
		fractal->zoom_scrol *= 1.05;
	fractal_render(fractal);
}

void	loop_zoom(void *param)
{
	t_data *fractal = (t_data *)param;

	if (fractal->zoomin_in == true)
		fractal->zoom_scrol -= fractal->zoom_speed;
	if (fractal->zoom_scrol < 0.3)
		fractal->zoomin_in = false;
	if (fractal->zoomin_in == false)
		fractal->zoom_scrol += fractal->zoom_speed;
	if (fractal->zoom_scrol > 1.5)
		fractal->zoomin_in = true;
	fractal_render(fractal);
}
