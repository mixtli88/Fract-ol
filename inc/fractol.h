#ifndef FRACTOL_H
# define FRACTOL_H

#include <math.h>
#include <stdio.h>
#include <limits.h>
#include "../lib/libft/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"


#define WIDTH 512
#define HEIGHT 512

typedef struct s_complex
{
	float x;
	float y;

}	t_complex;

typedef struct  s_data
{
	//mlx//

	char			*name;
	mlx_t			*mlx;
	void			*win;
	
	//image//

	mlx_image_t		*img;
	double			*zoom;
	
	//
	void			*color;
	double			*juli_x;
	double			*juli_y;
	double				x;
	double				y;

	//test//
	char			*str;
	int				algo_type;


} t_data;

	int ft_parsing(int ac, char **av, t_data *db);
	char *ft_strtolowel(char *str);

#endif