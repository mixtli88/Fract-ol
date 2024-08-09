#ifndef FRACTOL_H
# define FRACTOL_H

#include <math.h>
#include <stdio.h>
#include <limits.h>
#include "../lib/libft/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"


#define WIDTH 800
#define HEIGHT 800

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
	mlx_t			*win;
	
	//image//

	mlx_image_t		*img;
	double			*zoom;
	
	//
	void			*color;
	double			juli_x;
	double			juli_y;
	double				x;
	double				y;

	//test//
	char			*str;
	int				algo_type;


} t_data;

	int ft_parsing(int ac, char **av, t_data *fractal);
	double ft_atodbl (int i, double sig, double n, char *str);
	char *ft_strtolowel(char *str);
	void msg_error(void);
	void fractol_init(t_data *fractal);
#endif