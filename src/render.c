#include "../inc/fractol.h"

void ft_zoom_in(t_data *fractal)
{
	double zoom_factor = 0.5;

	fractal->dim_x_max -= zoom_factor;
	fractal->dim_x_min += zoom_factor;
	fractal->dim_y_max -= zoom_factor;
	fractal->dim_y_min += zoom_factor;
}

void ft_zoom_out(t_data *fractal)
{
	double zoom_factor = 0.5;

	fractal->dim_x_max += zoom_factor;
	fractal->dim_x_min -= zoom_factor;
	fractal->dim_y_max += zoom_factor;
	fractal->dim_y_min -= zoom_factor;
}


// #include "../lib/MLX42/include/MLX42/MLX42_Int.h"
void fractal_render(t_data *fractal)
{
    int x;
    int y;
	// int frames;
	

	// frames = 0;
	// while (frames < 2)
	// {
		y = -1;
		while(++y < HEIGHT)
		{
			x = -1;
				while(++x < WIDTH)
				{
					pixel_frac(x, y, fractal);
				}
		}
		//cambiar valores
		//mlx_delete_image(fractal->mlx, fractal->img);
		// ft_zoom_in(fractal);
		//mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
		//supprimir la imagen
		//loop
	// 	frames++;
	// }
	// // while (fractal->dim_x_max > 0 && fractal->dim_x_min < 0 && fractal->dim_y_max >0 &&	fractal->dim_y_min < 0)
	// // {

				
	// 	y = -1;
	// 	while(++y < HEIGHT)
	// 	{
	// 		x = -1;
	// 			while(++x < WIDTH)
	// 			{
	// 				pixel_frac(x, y, fractal);
	// 			}
	// 	}
	// // 	fractal->dim_x_max -= 0.5;
	// // 	fractal->dim_x_min += 0.5;
	// // 	fractal->dim_y_max -= 0.5;
	// // 	fractal->dim_y_min += 0.5;
	// // }
	// printf("%f", fractal->dim_x_max);
		
}