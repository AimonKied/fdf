/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:46:22 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 23:28:57 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_min_max(t_map *map)
{
	if (find_min_max(map) == -1)
	{
		if (map->min_max)
			free(map->min_max);
		return (ft_printf("Find min_max failed\n"), -1);
	}
	return (0);
}

int	transform(t_map *map)
{
	if (get_min_max(map) == -1)
		return (-1);
	offset(map);
	rotate(map);
	if (get_min_max(map) == -1)
		return (-1);
	get_scale_factor(map);
	execute_scale(map);
	if (get_min_max(map) == -1)
		return (-1);
	if (get_move(map) == -1)
		return (free(map->min_max), ft_printf("Get move failed"), -1);
	execute_move(map);
	free(map->move);
	return (0);
}
