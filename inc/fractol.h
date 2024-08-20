/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:36:05 by mabril            #+#    #+#             */
/*   Updated: 2024/08/20 11:41:17 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define MAGENTA 0xFF00FFFF
# define CYAN 0x00FFFFFF
# define ORANGE 0xFFA500FF
# define PURPLE 0x660066FF
# define GRAY 0x808080FF
# define LIGHT_GRAY 0xD3D3D3FF
# define DARK_GRAY 0xA9A9A9FF

typedef struct s_complex
{
	float			x;
	float			y;

}					t_complex;

typedef struct s_data
{
	// mlx//
	char			*name;
	mlx_t			*mlx;
	mlx_t			*win;

	// image//
	mlx_image_t		*img;
	double			zoom;

	void			*color;
	int				juli_x;
	double			juli_y;
	double			x;
	double			y;
	int				iterations;

	double			move_x;
	double			move_y;
	int32_t			centre_x;
	int32_t			centre_y;

	unsigned int	currentcolor;

	int				algo_type;
	bool			zoom_in;
	double			factor_zoom;

}					t_data;

int				ft_parsing(int ac, char **av, t_data *fractal);

void			msg_error(void);
double			ft_atodbl(int i, double sig, double n, char *str);

void			data_init(void *param);
void			fractol_init(t_data *fractal);

void			fractal_render(t_data *fractal);
void			pixel_frac(int32_t x, int32_t y, t_data *fractal);

double			scale(int32_t x, double new_max, double new_min,
					double old_max);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		squar_complex(t_complex z, void *param);

void			ft_hooks(void *param);

void			key_hook(void *param);
void			scrol_hook(double xdelta, double ydelta, void *param);
void			close_frac(void *param);
void			loop_zoom(void *param);
t_complex		conjugate(t_complex z);
void			int_pos(void *param);

#endif