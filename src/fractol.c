#include "../inc/fractol.h"



void fractals(t_complex *z, t_complex *c, t_data *fractal)
{
	if(!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->juli_x;
		c->y = fractal->juli_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void pixel_frac(int x, int y, t_data *fractal) 
{
    t_complex z;
    t_complex c;
    // int color;
    int i = 0;

    
	// c.x = 0;
    // c.y = 0;
	
	z.x = scale(x, 2, -2, WIDTH, 0) * fractal->zoom_scrol + fractal->move_x  ;
	z.y = scale(y, 2, -2, HEIGHT, 0)* fractal->zoom_scrol + fractal->move_y;
	

	fractals(&z, &c, fractal);
	while (i < fractal->iterations)
	{   
		z = sum_complex(squar_complex(z), c);
		
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			// color = scale(i -5, BLUE, BLACK, 80, 0);
			fractal->currentColor = scale(i , BLUE, BLACK, fractal->iterations, 0);
			mlx_put_pixel(fractal->img, x, y, getNextPsychedelicColor(fractal));
			return ;
		}
		i++;
	} 
		
    // color = (scale(i, -10860545, RED, 60, 0);

    // mlx_put_pixel(fractal->img, x, y, color);

    // mlx_put_pixel(fractal->img, x, y, -10860545-fractal->iterations );
	mlx_put_pixel(fractal->img, x, y, WHITE);

}