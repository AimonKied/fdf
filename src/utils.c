/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:46:16 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 18:42:47 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*yeet(char *array, char c, t_map *map)
{
	char	*new_array;
	int		i;
	int		j;
	size_t	array_len;

	if (!array || !map)
		return (NULL);
	i = 0;
	j = 0;
	array_len = ft_strlen(array);
	new_array = malloc((array_len + 1) * sizeof(char));
	if (!new_array)
		return (NULL);
	while (array[i])
	{
		if (array[i] != c)
			new_array[j] = array[i];
		else
			new_array[j] = ' ';
		i++;
		j++;
	}
	new_array[j] = '\0';
	return (new_array);
}

double	ft_atod(const char *str)
{
	double	nb;
	int		i;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb * sign);
}
