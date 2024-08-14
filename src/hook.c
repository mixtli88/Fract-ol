#include "../inc/fractol.h"

// void key_hook(struct mlx_key_data key, void *param)
 void key_hook(void *param)
{
	t_data *fractal = param;
   
	
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	 if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->move_y += 0.5;
	 if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->move_y -= 0.5;
	 if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->move_x -= 0.5;
	 if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->move_x  += 0.5;
	if(mlx_is_key_down(fractal->mlx, MLX_KEY_1))
		loop_zoom(fractal);
	fractal_render(fractal);
}


void scrol_hook(double xdelta, double ydelta, void* param)
{
	t_data *fractal= param;
	xdelta = 0;
	if(ydelta > 0 && xdelta == 0)
		fractal->zoom_scrol	/= 1.05;
	else
		fractal->zoom_scrol	*= 1.05;

	fractal_render(fractal);
}

void loop_zoom(void* param)
{
    t_data *fractal = (t_data *)param;
		
		
	 

	// if (fractal->dim_x_max == 2)
	// 	fractal->zoomin_in = true;
	// else if (are_floats_equal(fractal->dim_x_max, zoom_speed))
		// fractal->zoomin_in= false;
    if (fractal->zoomin_in == true)
	{
		fractal->zoom_scrol -= fractal->zoom_speed;
		if(fractal->zoom_scrol < -0.1)
			fractal->zoomin_in = false;
	} 
	else 
		fractal->zoom_scrol += fractal->zoom_speed;
			if(fractal->zoom_scrol > 3)
				fractal->zoomin_in = false;
	fractal_render(fractal);
}