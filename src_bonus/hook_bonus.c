/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:35:32 by mabril            #+#    #+#             */
/*   Updated: 2024/08/20 18:59:32 by mabril           ###   ########.fr       */
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
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_1))
		mlx_loop_hook(fractal->mlx, loop_zoom, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_2))
		fractal->zoom = 1;
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

void	loop_zoom(void *param)
{
	t_data	*fractal;

	fractal = (t_data *)param;
	if (fractal->zoom_in == true)
		fractal->zoom /= fractal->factor_zoom;
	if (fractal->zoom < 0.01)
		fractal->zoom_in = false;
	if (fractal->zoom_in == false)
		fractal->zoom *= fractal->factor_zoom;
	if (fractal->zoom > 1.8)
		fractal->zoom_in = true;
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

void	int_pos(void *param)
{
	int32_t	x;
	int32_t	y;
	t_data	*fractal;

	fractal = param;
	mlx_get_mouse_pos(fractal->mlx, &x, &y);
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->juli_x = scale(x, 2, -2, WIDTH) * fractal->zoom
			+ fractal->move_x;
		fractal->juli_y = scale(y, 2, -2, HEIGHT) * fractal->zoom
			+ fractal->move_y;
		fractal_render(fractal);
	}
}
