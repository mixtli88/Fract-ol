#include "../inc/fractol.h"

void update_scene(void *param)
{
    t_data *fractal = (t_data *)param;
		printf("%f\n", fractal->dim_x_max);
		// printf("%d", fractal->zoomin_in);
	// static bool zooming_in; 
	
	double zoom_speed = 0.2; 

	if (fractal->dim_x_max == 2)
		fractal->zoomin_in = true;
	else if (fractal->dim_x_max == 0.0000 || (fractal->dim_x_max < 0))
		fractal->zoomin_in= false;

    if (fractal->zoomin_in == true) 
	{
		fractal->dim_x_max -= zoom_speed;
        fractal->dim_x_min += zoom_speed;
        fractal->dim_y_max -= zoom_speed;
        fractal->dim_y_min += zoom_speed;
       

        // if (fractal->dim_x_max == 0.5 || fractal->dim_x_min == -0.5 ||
        //     fractal->dim_y_max == 0.5 || fractal->dim_y_min == -0.5) 
		// {
        //     zooming_in = false; 
        // }
    }
	 else 
	 {
        fractal->dim_x_max += zoom_speed;
        fractal->dim_x_min -= zoom_speed;
        fractal->dim_y_max += zoom_speed;
        fractal->dim_y_min -= zoom_speed;

        // if (fractal->dim_x_max == 2 || fractal->dim_x_min == -2 ||
        //     fractal->dim_y_max == 2 || fractal->dim_y_min == -2) 
		// 	{
        //     zooming_in = true; // Cambiar a estado de acercamiento
        // }
    }
	fractal_render(fractal);
	
}

int main (int ac, char **av)
{
	

	t_data *fractal = (t_data *)ft_calloc(1, sizeof(t_data));
	
		fractal->zoomin_in =true;
		printf("%d", fractal->zoomin_in);
		ft_parsing(ac, av, fractal);
		fractol_init(fractal);
		fractal->dim_x_max = 2;
		fractal->dim_x_min = -2;
		fractal->dim_y_max = 2;
		fractal->dim_y_min = -2;
		fractal_render(fractal);
		mlx_loop_hook(fractal->mlx, update_scene, fractal);
		mlx_loop(fractal->mlx);
		
		mlx_terminate(fractal->mlx);

	
	
	return(0);
}
