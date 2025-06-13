/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:33 by swied             #+#    #+#             */
/*   Updated: 2025/06/13 19:57:37 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate(t_map *map)
{
	int	i = 0;

	rotate_x(map);	
	printf("\nAfter Rotate_x:\n");
	i = 0;
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		printf("Point: %d = x: %f y: %f, z: %f\n", i, map->arr_of_3d_crds[i].x, map->arr_of_3d_crds[i].y, map->arr_of_3d_crds[i].z);
		i++;
	}
	
	rotate_z(map);
	printf("\nAfter Rotate_z:\n");
	i = 0;
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		printf("Point: %d = x: %f y: %f, z: %f\n", i, map->arr_of_3d_crds[i].x, map->arr_of_3d_crds[i].y, map->arr_of_3d_crds[i].z);
		i++;
	}
}

void	rotate_x(t_map *map)
{
	t_3d_coord 	b;
	double		radian;	
	int			i;

	i = 0;
	// 35.264
	radian = 45 * (M_PI / 180);
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		b.x = map->arr_of_3d_crds[i].x;
		b.y = (cos(radian) * map->arr_of_3d_crds[i].y) + (-sin(radian) * map->arr_of_3d_crds[i].z);
		b.z = (sin(radian) * map->arr_of_3d_crds[i].y) + (cos(radian) * map->arr_of_3d_crds[i].z);
		map->arr_of_3d_crds[i].x = b.x;
		map->arr_of_3d_crds[i].y = b.y;
		map->arr_of_3d_crds[i].z = b.z;
		i++;
	}
}

void	rotate_y(t_map *map)
{
	t_3d_coord	c;
	double		radian;
	int			i;

	i = 0;
	radian = 35.264 * (M_PI / 180);
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		c.x = (cos(radian) * map->arr_of_3d_crds[i].x) + (sin(radian) * map->arr_of_3d_crds[i].z);
		c.y = map->arr_of_3d_crds->y;
		c.z = (-sin(radian) * map->arr_of_3d_crds[i].x) + (cos(radian) * map->arr_of_3d_crds[i].z);
		map->arr_of_3d_crds[i].x = c.x;
		map->arr_of_3d_crds[i].y = c.y;
		map->arr_of_3d_crds[i].z = c.z;
		i++;
	}
}

void	rotate_z(t_map *map)
{
	t_3d_coord	c;
	double		radian;
	int			i;

	i = 0;
	radian = 35.264 * (M_PI / 180);
	while (i < (map->max_2d_crds->x * map->max_2d_crds->y))
	{
		c.x = (cos(radian) * map->arr_of_3d_crds[i].x) + (-sin(radian) * map->arr_of_3d_crds[i].y); 
		c.y = (sin(radian) * map->arr_of_3d_crds[i].x) + (cos(radian) * map->arr_of_3d_crds[i].y);
		c.z = map->arr_of_3d_crds[i].z;
		map->arr_of_3d_crds[i].x = c.x;
		map->arr_of_3d_crds[i].y = c.y;
		map->arr_of_3d_crds[i].z = c.z;
		i++;
	}
}

// void	transform_to_2d(t_map map)
// {
// 	double		radian;
// 	int	i;

// 	radian = 30 * (M_PI / 180);	
// 	i = 0;
// 	map.axis = malloc(sizeof(map.axis));
// 	map.axis[0].x = (map.arr_of_3d_crds[i].x - map.arr_of_3d_crds[i].y) * cos(radian);
// 	map.axis[0].y = (map.arr_of_3d_crds[i].x - map.arr_of_3d_crds[i].y) * sin(radian) - map.arr_of_3d_crds[i].z;
// 	printf("2D-Data:\nx: %f | y: %f", map.axis[0].x, map.axis[0].y);

	// axis[0].x = (map.x - map.y) * cos(radian);
	// axis[0].y = (map.x + map.y) * sin(radian) - map.new_array[i];
	// axis[1].x = 0 * cos(radian);
	// axis[1].y = 0 * sin(radian) - map.new_array[i];
	// draw_line(data.mlx_connection, data.mlx_window, map.axis, 0x00ff0000);
	// axis[0].y = (map.x - map.y) * cos(radian);
	// axis[0].y = (map.x + map.y) * sin(radian) - map.new_array[i];
	// axis[1].x = 1 * cos(radian);
	// axis[1].y = 1 * sin(radian) - map.new_array[i];
	// draw_line(data.mlx_connection, data.mlx_window, axis, 0x00ff00000);
	// return ;
// }
