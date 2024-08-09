#include "../inc/fractol.h"


int main (int ac, char **av)
{
	t_data *fractal = (t_data *)ft_calloc(1, sizeof(t_data));


	ft_parsing(ac, av, fractal);
	printf("%s", fractal->name);
	fractol_init(fractal);
	mlx_loop(fractal->mlx);
	mlx_terminate(fractal->mlx);
	
	return(0);
}
