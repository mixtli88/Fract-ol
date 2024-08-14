#include "../inc/fractol.h"

// #include "../lib/MLX42/include/MLX42/MLX42_Int.h"
void pixel_frac(int x, int y, t_data *fractal) 
{
    t_complex z;
    t_complex c;
    // int color;
    int i = 0;

    z.x = 0;
    z.y = 0;
	
	c.x = scale(x, 2,-2 , WIDTH, 0) * fractal->zoom_scrol + fractal->move_x  ;
	c.y = scale(y, 2, -2, HEIGHT, 0)* fractal->zoom_scrol + fractal->move_y;
	
	while (i < 80)
	{   
		z = sum_complex(squar_complex(z), c);
		
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			// color = scale(i -5, BLUE, BLACK, 80, 0);
			fractal->currentColor = scale(i -5, BLUE, BLACK, 80, 0);
			mlx_put_pixel(fractal->img, x, y, getNextPsychedelicColor(fractal));
			return ;
		}
		i++;
	} 
		
    // color = (scale(i, -10860545, RED, 60, 0);
	// color = {0,0,255};
    // mlx_put_pixel(fractal->img, x, y, color);

    mlx_put_pixel(fractal->img, x, y, -10860545 );

}