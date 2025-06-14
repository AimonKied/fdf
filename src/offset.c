/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:33:12 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 19:57:10 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	offset(t_map *map)
{
	double	mid_x;
	double	mid_y;
	int		x;
	int		y;
	int		i;

	i = 0;
	mid_x = (map->min_max->max_x + map->min_max->min_x) / 2;
	mid_y = (map->min_max->max_y + map->min_max->min_y) / 2;
	y = 0;
	while (y < map->max_2d_crds->y)
	{
		x = 0;
		while (x < map->max_2d_crds->x)
		{
			map->arr_of_3d_crds[i].x -= mid_x;
			map->arr_of_3d_crds[i].y -= mid_y;
			x++;
			i++;
		}
		y++;
	}
}
