/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:45:55 by mabril            #+#    #+#             */
/*   Updated: 2024/08/19 20:01:46 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	data_init(void *param)
{
	t_data	*fractal;

	fractal = param;
	fractal->zoom_in = true;
	fractal->zoom = 1;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->factor_zoom = 0.5;
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
		exit(EXIT_SUCCESS);
	if (!fractal->img)
	{
		mlx_close_window(fractal->mlx);
		exit(EXIT_SUCCESS);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	data_init(fractal);
}
