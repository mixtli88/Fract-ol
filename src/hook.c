/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:35:32 by mabril            #+#    #+#             */
/*   Updated: 2024/08/22 20:01:12 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	key_hook(void *param)
{
	t_data	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		close_frac(fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->move_y += 0.5 * fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->move_y -= 0.5 * fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->move_x += 0.5 * fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->move_x -= 0.5 * fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_2))
		data_init(param);
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
		fractal->zoom /= 1.05;
	else
		fractal->zoom *= 1.05;
	fractal_render(fractal);
}

void	close_frac(void *param)
{
	t_data	*fractal;

	fractal = (t_data *)param;
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_close_window(fractal->mlx);
	free(fractal);
	exit(EXIT_SUCCESS);
}
