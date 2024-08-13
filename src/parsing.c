#include "../inc/fractol.h"
// #include "../lib/MLX42/include/MLX42/MLX42_Int.h"
int	ft_parsing(int ac, char **av, t_data *fractal)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		ft_putstr_fd("LOOK MANDELBROT", 1);
		fractal->name = av[1];
		return (0);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		ft_putstr_fd("JULIA\n", 1);
		fractal->juli_x = ft_atodbl(-1, 1, 0, av[2]);
		fractal->juli_y = ft_atodbl(-1, 1, 0, av[3]);
		fractal->name = av[1];
		
		return (0);
	}
	else
		msg_error();
	return (0);
}
