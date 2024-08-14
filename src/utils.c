#include "../inc/fractol.h"
// #include "../lib/MLX42/include/MLX42/MLX42_Int.h"

void msg_error(void)
{
	ft_putstr_fd("Error: Invalid arguments\n", 2);
	ft_putstr_fd("Please use: ./fractol mandelbrot or\n", 2);
	ft_putstr_fd("Please use: ./fractol julia <x_num> <y_num>\n", 2);
	exit(EXIT_FAILURE);
}

double ft_atodbl (int i, double sig, double n, char *str)
{
	int	dc;

	dc = 0;
	if(str[++i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			sig = -1;
	}
	while (str[++i])
	{
		if(dc == 1)
			sig /= 10;
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 +(str[i] - 48);
		else if (str[i] == '.')
			dc = 1;
		else
			msg_error();
	}
	return(n  * sig);
}

unsigned int getNextPsychedelicColor(void* param) 
{
	t_data *fractal = param;
     

    // Descomponemos el color actual en sus componentes RGB
    unsigned char r = (fractal->currentColor >> 16) & 0xFF;
    unsigned char g = (fractal->currentColor >> 8) & 0xFF;
    unsigned char b = fractal->currentColor & 0xFF;

    // Actualizamos el componente actual del color basado en el estado
    if (fractal->state == 0) {
        r += 32;
        if (r > 255) {
            r = 0;
            fractal->state = 1;
        }
    } else if (fractal->state == 1) {
        g += 32;
        if (g > 255) {
            g = 0;
            fractal->state = 2;
        }
    } else { // state == 2
        b += 32;
        if (b > 255) {
            b = 0;
            fractal->state = 0; // Reiniciamos el estado después de completar el ciclo
        }
    }

    // Combinamos los componentes actualizados en un solo entero
    unsigned int newColor = (r << 16) | (g << 8) | b;
	// fractal_render(fractal);
    return newColor;
}
