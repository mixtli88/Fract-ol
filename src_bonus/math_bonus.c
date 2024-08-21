/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:35:51 by mabril            #+#    #+#             */
/*   Updated: 2024/08/20 11:39:00 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	scale(int32_t x, double new_max, double new_min, double old_max)
{
	double	porcent;
	double	new_x;

	porcent = (x / old_max);
	new_x = ((new_max - new_min) * porcent) + new_min;
	return (new_x);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = (z1.x + z2.x);
	result.y = (z1.y + z2.y);
	return (result);
}

t_complex	squar_complex(t_complex z, void *param)
{
	t_data		*fractal;
	t_complex	result;

	fractal = param;
	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = (2 * z.x * z.y);
	if (!ft_strncmp(fractal->name, "ship", 4))
		if (result.y < 0)
			result.y *= -1;
	return (result);
}
