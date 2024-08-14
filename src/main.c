#include "../inc/fractol.h"
#define EPSILON 0.5 

bool are_floats_equal(float a, float b)
{
	return((a - b) < EPSILON);
} 



int main (int ac, char **av)
{
		t_data *fractal = (t_data *)ft_calloc(1, sizeof(t_data));
	
		
		printf("%d", fractal->zoomin_in);
		ft_parsing(ac, av, fractal);
		data_init(fractal);
		fractol_init_mlx(fractal);
		fractal_render(fractal);
		mlx_loop_hook(fractal->mlx, ft_hooks, fractal);
		// mlx_loop_hook(fractal->mlx, update_scene, fractal);
		
		mlx_loop(fractal->mlx);
		mlx_terminate(fractal->mlx);

	
	
	return(0);
}
