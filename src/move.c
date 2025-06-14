/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:30:49 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 23:22:56 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_move(t_map *map)
{
	map->move = malloc(sizeof(t_move));
	if (!map->move)
		return (perror("Move alloc failed"), 1);
	map->move->move_x = WINDOW_WIDTH * 0.5;
	map->move->move_y = WINDOW_HEIGHT * 0.5;
	return (0);
}

void	execute_move(t_map *map)
{
	int	i;

	i = 0;
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		map->arr_of_3d_crds[i].x += map->move->move_x;
		map->arr_of_3d_crds[i].y += map->move->move_y;
		i++;
	}
}
