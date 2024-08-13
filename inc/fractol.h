#ifndef FRACTOL_H
# define FRACTOL_H

#include <math.h>
#include <stdio.h>
#include <limits.h>
#include "../lib/libft/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"



#define WIDTH 800
#define HEIGHT 800


// #define WHITE 250
// #define BLACK 1
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
	int				iterations;
	double			range_frac;
	double 			dim_x_min;
	double			dim_x_max;
	double			dim_y_min;
	double			dim_y_max;
	//test//
	char			*str;
	int				algo_type;
	bool 			zoomin_in;
	int				zoom_x;
	int 			zoom_y;

} t_data;

	int ft_parsing(int ac, char **av, t_data *fractal);

	void msg_error(void);
	double ft_atodbl (int i, double sig, double n, char *str);
	char *ft_strtolowel(char *str);
	

	void fractol_init(t_data *fractal);

	void fractal_render(t_data *fractal);
	void pixel_frac(int x, int y, t_data *fractal);

	double scale(double x, double new_max, double new_min, double old_max, double old_nim);
	t_complex sum_complex(t_complex z1, t_complex z2);
	t_complex squar_complex(t_complex z);



#endif