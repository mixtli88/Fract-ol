/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:35:48 by mabril            #+#    #+#             */
/*   Updated: 2024/08/20 11:42:17 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	fractals(t_complex *z, t_complex *c, t_data *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->juli_x;
		c->y = fractal->juli_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	pixel_frac(int32_t x, int32_t y, t_data *fractal)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	i = 0;
	z.x = scale(x, 2, -2, WIDTH) * fractal->zoom + fractal->move_x;
	z.y = scale(y, 2, -2, HEIGHT) * fractal->zoom + fractal->move_y;
	fractals(&z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = sum_complex(squar_complex(z, fractal), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			fractal->currentcolor = scale(i - 5, RED, BLACK,
					fractal->iterations);
			mlx_put_pixel(fractal->img, x, y, fractal->currentcolor);
			return ;
		}
		i++;
	}
	color = scale(i, BLACK, CYAN, fractal->iterations);
	mlx_put_pixel(fractal->img, x, y, color);
}
