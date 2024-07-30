// int main()
// argv[1] julia ou mandelbrot
// tout sauf ca message error parsing

// test parsing error ./fractol juliaa231987

#include "../../inc/fractol.h"

char *ft_strtolowel(char *str)
{
	int i= 0;
	while(str[i])
	{
		if(str[i]>= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	} 
	return(str);
}
int ft_parsing(int ac, char **av, t_data *db)
{
	if (ac == 2)
	{
		ft_strtolowel(av[1]);
		if ((ft_strncmp(av[1], "julia", 5) == 0) && (ft_strlen(av[1]) == 5))
		{
			ft_putstr_fd("LOOK JULIA", 1);
			return(0);
		}
		else if((ft_strncmp(av[1], "mandel", 6) == 0) && (ft_strlen(av[1]) == 6))
		{
			ft_putstr_fd("LOOK MANDEL", 1);
			return(0);
		}
	}
	else
	{
		ft_putstr_fd("numero de argumetos incorrectos", 1);
		return(1);
	}
	write(1, "error", 5);
	return(1);
}

int main(int ac, char **av)
{
	t_data *db;

	db = ft_calloc(sizeof(t_data), 1);
	ft_parsing(ac, av, db);
	return (0);
}

// int main (int ac, char **av)
// {
// 	if(ac < 2 || !ac[1])
// 	{
// 		ft_putstr_fd("error de argumentos", 1);
// 		return(-1);
// 	}

// }