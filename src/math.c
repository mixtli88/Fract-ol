/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:35:51 by mabril            #+#    #+#             */
/*   Updated: 2024/08/19 20:02:50 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	scale(double x, double new_max, double new_min, double old_max,
		double old_nim)
{
	double	porcent;
	double	new_x;

	porcent = (x - old_nim) / (old_max - old_nim);
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

t_complex	squar_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = (2 * z.x * z.y);
	return (result);
}
