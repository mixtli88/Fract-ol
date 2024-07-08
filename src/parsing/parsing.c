// int main()
// argv[1] julia ou mandelbrot
// tout sauf ca message error parsing

// test parsing error ./fractol juliaa231987

#include "../../inc/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strncmp(av[1], "julia", 5) == 0)
			write(1, "ok", 2);
	}
	else
	{
		ft_putstr_fd("numero de argumetos incorrectos", 1);
		return(1);
	}
	return(0);
}