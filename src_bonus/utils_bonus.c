/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:35:41 by mabril            #+#    #+#             */
/*   Updated: 2024/08/22 20:05:48 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

void	msg_error(void)
{
	ft_putstr_fd("Error: Invalid arguments\n", 2);
	ft_putstr_fd("Please use: ./fractol mandelbrot or\n", 2);
	ft_putstr_fd("Please use: ./fractol julia |-2 < x < 2|--|-2 < y < 2|\n", 2);
	ft_putstr_fd("Please use: ./fractol ship \n", 2);
	exit(EXIT_FAILURE);
}

double	ft_atodbl(int i, double sig, double n, char *str)
{
	int	dc;

	dc = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = -1;
		++i;
	}
	while (str[++i])
	{
		if (dc == 1)
			sig /= 10;
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i] - 48);
		else if (str[i] == '.')
			dc = 1;
		else
			msg_error();
		++i;
	}
	return (n * sig);
}

void	loop_zoom_infinit(void *param)
{
	t_data	*fractal;

	fractal = (t_data *)param;
	if (fractal->zoom_inf_active == true)
	{
		if (fractal->zoom_in == true)
			fractal->zoom /= fractal->factor_zoom;
	}
	fractal_render(fractal);
}