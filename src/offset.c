/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:33:12 by swied             #+#    #+#             */
/*   Updated: 2025/06/13 13:53:53 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	int_to_double(int int_num)
{
	int		count;
	double	double_num;

	count = 0;
	double_num = 0;
	if (int_num != 0)
		int_num--;
	while (count < int_num)
	{
		double_num += 1;
		count++;
	}
	return (double_num);
}

void	offset(t_map *map)
{
	double	max_x;
	double	max_y;
	double	mid_x;
	double	mid_y;
	int		x;
	int		y;
	int		i;

	i = 0;
	max_x = int_to_double(map->max_2d_crds->x);
	max_y =	int_to_double(map->max_2d_crds->y);
	mid_x = max_x / 2;
	mid_y = max_y / 2;
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
