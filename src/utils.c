#include "../inc/fractol.h"


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

