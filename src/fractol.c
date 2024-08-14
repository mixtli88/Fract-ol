#include "../inc/fractol.h"

// #include "../lib/MLX42/include/MLX42/MLX42_Int.h"
void pixel_frac(int x, int y, t_data *fractal) 
{
    t_complex z;
    t_complex c;
    int color;
    int i = 0;

    z.x = 0;
    z.y = 0;
	
	c.x = scale(x, fractal->dim_x_max,fractal->dim_x_min , WIDTH, 0) * fractal->zoom_scrol;
	c.y = scale(y, fractal->dim_y_max, fractal->dim_y_min, HEIGHT, 0)* fractal->zoom_scrol;
	
	while (i < 40)
	{   
		z = sum_complex(squar_complex(z), c);
		
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = scale(i -5, BLUE, BLACK, 40, 0);
			mlx_put_pixel(fractal->img, x, y, color);
			return ;
		}
		i++;
	} 
		
    // color = scale(i, -10860545, RED, 60, 0);
    // mlx_put_pixel(fractal->img, x, y, color);

    mlx_put_pixel(fractal->img, x, y, -10860545 );

}