/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:33 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 15:18:26 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate(t_map *map)
{
	rotate_z(map);
	rotate_x(map);
}

void	rotate_x(t_map *map)
{
	t_3d_coord	b;
	double		radian;	
	int			i;

	i = 0;
	radian = 54.736 * (M_PI / 180);
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		b.x = map->arr_of_3d_crds[i].x;
		b.y = (cos(radian) * map->arr_of_3d_crds[i].y)
			+ (-sin(radian) * map->arr_of_3d_crds[i].z);
		b.z = (sin(radian) * map->arr_of_3d_crds[i].y)
			+ (cos(radian) * map->arr_of_3d_crds[i].z);
		map->arr_of_3d_crds[i].x = b.x;
		map->arr_of_3d_crds[i].y = b.y;
		map->arr_of_3d_crds[i].z = b.z;
		i++;
	}
}

void	rotate_z(t_map *map)
{
	t_3d_coord	c;
	double		radian;
	int			i;

	i = 0;
	radian = -45 * (M_PI / 180);
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		c.x = (cos(radian) * map->arr_of_3d_crds[i].x)
			+ (-sin(radian) * map->arr_of_3d_crds[i].y);
		c.y = (sin(radian) * map->arr_of_3d_crds[i].x)
			+ (cos(radian) * map->arr_of_3d_crds[i].y);
		c.z = map->arr_of_3d_crds[i].z;
		map->arr_of_3d_crds[i].x = c.x;
		map->arr_of_3d_crds[i].y = c.y;
		map->arr_of_3d_crds[i].z = c.z;
		i++;
	}
}
