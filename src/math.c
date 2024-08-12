#include "../inc/fractol.h"

double scale(double x, double new_max, double new_min, double old_max, double old_nim)
{
    double porcent = (x - old_nim) / (old_max - old_nim);
    double new_x = ((new_max - new_min) * porcent) + new_min;
    return(new_x);
}

t_complex sum_complex(t_complex z1, t_complex z2)
{

    t_complex result;

    result.x = (z1.x + z2.x);
    result.y = (z1.y + z2.y);

    return (result); 
}

t_complex squar_complex(t_complex z)
{
    t_complex result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = (2 * z.x * z.y); 
    return(result); 
}