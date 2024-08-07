/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strtolowel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:50:31 by mabril            #+#    #+#             */
/*   Updated: 2024/07/08 19:50:51 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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