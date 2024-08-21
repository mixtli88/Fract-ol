/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:45:55 by mabril            #+#    #+#             */
/*   Updated: 2024/08/21 13:04:45 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_parsing(int ac, char **av, t_data *fractal)
{
	double	n1;
	double	n2;

	n1 = ft_atodbl(0, 1, 0, av[2]);
	n2 = ft_atodbl(0, 1, 0, av[3]);
	printf("%f, %f\n", n1, n2);
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		ft_putstr_fd("MANDELBROT\n", 1);
		fractal->name = av[1];
		return (0);
	}
	else if (ac == 4 && !(ft_strncmp(av[1], "julia", 5)) && (-2.0 <= n1
			&& n1 <= 2.0) && (n2 >= -2.0 && n2 <= 2.0))
	{
		printf("%f, %f\n", n1, n2);
		ft_putstr_fd("JULIA\n", 1);
		fractal->juli_x = n1;
		fractal->juli_y = n2;
		fractal->name = av[1];
		return (0);
	}
	else
		msg_error();
	return (0);
}

void	data_init(void *param)
{
	t_data	*fractal;

	fractal = param;
	fractal->zoom_in = true;
	fractal->zoom = 1;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->factor_zoom = 1.5;
	fractal->iterations = 80;
}

void	ft_hooks(void *param)
{
	t_data	*fractal;

	fractal = param;
	key_hook(fractal);
	mlx_scroll_hook(fractal->mlx, scrol_hook, fractal);
}

void	fractol_init(t_data *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, false);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->mlx)
	{
		free(fractal);
		exit(EXIT_SUCCESS);
	}
	if (!fractal->img)
	{
		mlx_close_window(fractal->mlx);
		free(fractal);
		exit(EXIT_SUCCESS);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	data_init(fractal);
}
