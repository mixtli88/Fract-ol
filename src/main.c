#include "../inc/fractol.h"

void update_scene(void *param)
{
    t_data *fractal = (t_data *)param;

    // Aquí va tu lógica para actualizar los límites de zoom
    double zoom_speed = 0.5; // Puedes ajustar esto según sea necesario
	
    static bool zooming_in = false;
    if (fractal) 
	{
		zooming_in
        fractal->dim_x_max += zoom_speed;
        fractal->dim_x_min -= zoom_speed;
        fractal->dim_y_max += zoom_speed;
        fractal->dim_y_min -= zoom_speed;

        if (fractal->dim_x_max == 0.5 || fractal->dim_x_min == -0.5 ||
            fractal->dim_y_max == 0.5 || fractal->dim_y_min == -0.5) 
		{
            zooming_in = false; // Cambiar a estado de alejamiento
        }
    }
	 else 
	 {
        fractal->dim_x_max -= zoom_speed;
        fractal->dim_x_min += zoom_speed;
        fractal->dim_y_max -= zoom_speed;
        fractal->dim_y_min += zoom_speed;

        if (fractal->dim_x_max == 2 || fractal->dim_x_min == -2 ||
            fractal->dim_y_max == 2 || fractal->dim_y_min == -2) 
			{
            zooming_in = true; // Cambiar a estado de acercamiento
        }
    }
	fractal_render(fractal);
    // Luego de actualizar los límites, puedes llamar a tu función de renderizado aquí
    // Por ejemplo: fractal_render(fractal);
}

int main (int ac, char **av)
{
	t_data *fractal = (t_data *)ft_calloc(1, sizeof(t_data));
	
	
		ft_parsing(ac, av, fractal);
		fractol_init(fractal);
		fractal->dim_x_max = 2;
		fractal->dim_x_min = -2;
		fractal->dim_y_max = 2;
		fractal->dim_y_min = -2;
		printf("%s\n", "hola");
		fractal_render(fractal);
		mlx_loop_hook(fractal->mlx, update_scene, fractal);
		mlx_loop(fractal->mlx);
		
		mlx_terminate(fractal->mlx);

	
	
	return(0);
}
