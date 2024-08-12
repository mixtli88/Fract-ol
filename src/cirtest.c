#include "../inc/fractol.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
void drawCircle(t_data *db, int centerX, int centerY, int radius) 
{
	int y = -radius;
	printf("%d", ft_pixel(255, 90, 71, 255));
	while (y <= radius) 
	{
		int x = -radius;
		while (x <= radius)
		{
			if (x*x + y*y <= radius*radius)
			{
				mlx_put_pixel(db->img, centerX + x, centerY + y, ft_pixel(255, 90, 71, 255));
			}
			x++;
		}
		y++;
	}
}

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
			db->algo_type = 1;
			return(0); 
		}
		else if((ft_strncmp(av[1], "mandel", 6) == 0) && (ft_strlen(av[1]) == 6))
		{
			ft_putstr_fd("LOOK MANDEL", 1);
			db->algo_type = 2;
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
	db->algo_type = 0;
	if(ft_parsing(ac, av, db) == 0)
	{
		printf("\n DESPUES %d\n", db->algo_type);
		db->mlx = mlx_init(1100, 1100, "MLX42",false);
		db->img = mlx_new_image(db->mlx, 1000, 1000);
		mlx_image_to_window(db->mlx, db->img, 0, 0);
		// mlx_put_pixel(db->img, 1, 1, -1);
		drawCircle(db, 550, 550, 100);
		mlx_loop(db->mlx);
		mlx_terminate(db->mlx);


	}  
	return (0);
}
