/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:36:11 by mabril            #+#    #+#             */
/*   Updated: 2024/08/21 13:15:31 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int ac, char **av)
{
	t_data	*fractal;

	fractal = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!fractal)
		return (1);
	ft_parsing(ac, av, fractal);
	fractol_init(fractal);
	fractal_render(fractal);
	mlx_loop_hook(fractal->mlx, ft_hooks, fractal);
	mlx_loop(fractal->mlx);
	mlx_terminate(fractal->mlx);
	free(fractal);
	return (0);
}
