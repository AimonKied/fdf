/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_xy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:17:40 by swied             #+#    #+#             */
/*   Updated: 2025/06/13 18:50:58 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	find_min_max(t_map *map)
{
	map->min_max = malloc(sizeof(t_min_max));
	if (!map->min_max)
		return (perror("Alloc failed"), -1);
	f_min_x(map);
	f_max_x(map);
	f_min_y(map);
	f_max_y(map);
	map->min_max->full_x = map->min_max->max_x - map->min_max->min_x;
	map->min_max->full_y = map->min_max->max_y - map->min_max->min_y;
	return (0);
}

void	f_min_x(t_map *map)
{
	int	i;

	i = 0;
	map->min_max->min_x = __DBL_MAX__;
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		if (map->arr_of_3d_crds[i].x < map->min_max->min_x)
			map->min_max->min_x = map->arr_of_3d_crds[i].x;	
		i++;
	}
}

void	f_max_x(t_map *map)
{
	int	i;

	i = 0;
	map->min_max->max_x = -__DBL_MAX__;
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		if (map->arr_of_3d_crds[i].x > map->min_max->max_x)
			map->min_max->max_x = map->arr_of_3d_crds[i].x;
		i++;
	}
}

void	f_min_y(t_map *map)
{
	int	i;

	i = 0;
	map->min_max->min_y = __DBL_MAX__;
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		if (map->arr_of_3d_crds[i].y < map->min_max->min_y)
			map->min_max->min_y = map->arr_of_3d_crds[i].y;	
		i++;
	}
}

void	f_max_y(t_map *map)
{
	int	i;

	i = 0;
	map->min_max->max_y = -__DBL_MAX__;
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		if (map->arr_of_3d_crds[i].y > map->min_max->max_y)
			map->min_max->max_y = map->arr_of_3d_crds[i].y;
		i++;
	}
}
