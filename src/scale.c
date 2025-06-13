/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:00:39 by swied             #+#    #+#             */
/*   Updated: 2025/06/13 15:25:59 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_scale_factor(t_map *map)
{
	map->scale_factor = (WINDOW_HEIGHT * 0.5) / (map->min_max->full_y);
	printf("Scale factor: %f\n", map->scale_factor);
}

void	execute_scale(t_map *map)
{
	int	i;

	i = 0;
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		map->arr_of_3d_crds[i].x = map->arr_of_3d_crds[i].x * map->scale_factor;
		map->arr_of_3d_crds[i].y = map->arr_of_3d_crds[i].y * map->scale_factor;
		map->arr_of_3d_crds[i].z = map->arr_of_3d_crds[i].z * map->scale_factor;
		i++;
	}
}