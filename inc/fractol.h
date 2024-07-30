#ifndef FRACTOL_H
# define FRACTOL_H

#include <math.h>
#include "../lib/libft/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <limits.h>

#include "stdio.h"

#define WIDTH 512
#define HEIGHT 512

typedef struct  s_data
{
	mlx_t			*mlx;
	void			*win;
	mlx_image_t		*img;
	char *str;
	int algo_type;


} t_data;

	int ft_parsing(int ac, char **av, t_data *db);
	char *ft_strtolowel(char *str);

#endif