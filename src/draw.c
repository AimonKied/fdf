/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:32:10 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 23:21:28 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	draw(t_data *data, t_map *map)
{
	int	max_index;

	map->bh = malloc(sizeof(t_bh));
	if (!map->bh)
		return (ft_printf("Allocate bh failed\n"), -1);
	max_index = (map->max_2d_crds->x * map->max_2d_crds->y);
	map->axis = malloc(2 * sizeof(t_axis));
	if (!map->axis)
		return (free(map->bh), ft_printf("Allocate axis failed\n"), -1);
	draw_vertical_lines(data, map, max_index);
	draw_horizontal_lines(data, map, max_index);
	free(map->bh);
	free(map->axis);
	return (0);
}

void	draw_horizontal_lines(t_data *data, t_map *map, int max_index)
{
	int	x;
	int	y;
	int	current_index;
	int	next_index;

	y = 0;
	while (y < map->max_2d_crds->y)
	{
		x = 0;
		while (x < map->max_2d_crds->x - 1)
		{
			current_index = y * map->max_2d_crds->x + x;
			next_index = current_index + 1;
			if (current_index > max_index || next_index > max_index)
				break ;
			map->axis[0].x = map->arr_of_3d_crds[current_index].x;
			map->axis[0].y = map->arr_of_3d_crds[current_index].y;
			map->axis[1].x = map->arr_of_3d_crds[next_index].x;
			map->axis[1].y = map->arr_of_3d_crds[next_index].y;
			draw_line(data, map);
			x++;
		}
		y++;
	}
}

void	draw_vertical_lines(t_data *data, t_map *map, int max_index)
{
	int	x;
	int	y;
	int	current_index;
	int	next_index;

	x = 0;
	while (x < map->max_2d_crds->x)
	{
		y = 0;
		while (y < map->max_2d_crds->y - 1)
		{
			current_index = y * map->max_2d_crds->x + x;
			next_index = current_index + map->max_2d_crds->x;
			if (current_index > max_index || next_index > max_index)
				break ;
			map->axis[0].x = map->arr_of_3d_crds[current_index].x;
			map->axis[0].y = map->arr_of_3d_crds[current_index].y;
			map->axis[1].x = map->arr_of_3d_crds[next_index].x;
			map->axis[1].y = map->arr_of_3d_crds[next_index].y;
			draw_line(data, map);
			y++;
		}
		x++;
	}
}

void	init_draw_line(t_map *map)
{
	map->bh->dx = abs(map->bh->x1 - map->bh->x);
	map->bh->dy = -abs(map->bh->y1 - map->bh->y);
	if (map->bh->x < map->bh->x1)
		map->bh->sx = 1;
	else
		map->bh->sx = -1;
	if (map->bh->y < map->bh->y1)
		map->bh->sy = 1;
	else
		map->bh->sy = -1;
	map->bh->err = map->bh->dx + map->bh->dy;
}

void	draw_line(t_data *data, t_map *map)
{
	map->bh->x = (int)map->axis[0].x;
	map->bh->y = (int)map->axis[0].y;
	map->bh->x1 = (int)map->axis[1].x;
	map->bh->y1 = (int)map->axis[1].y;
	init_draw_line(map);
	while (1)
	{
		if (map->bh->x >= 0 && map->bh->x < WINDOW_WIDTH
			&& map->bh->y >= 0 && map->bh->y < WINDOW_HEIGHT)
			mlx_pixel_put(data->mlx_connection, data->mlx_window,
				map->bh->x, map->bh->y, 0x00fff0);
		if (map->bh->x == map->bh->x1 && map->bh->y == map->bh->y1)
			break ;
		map->bh->e2 = 2 * map->bh->err;
		if (map->bh->e2 >= map->bh->dy)
		{
			map->bh->err += map->bh->dy;
			map->bh->x += map->bh->sx;
		}
		if (map->bh->e2 <= map->bh->dx)
		{
			map->bh->err += map->bh->dx;
			map->bh->y += map->bh->sy;
		}
	}
}
