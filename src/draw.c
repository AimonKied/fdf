/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:32:10 by swied             #+#    #+#             */
/*   Updated: 2025/06/13 18:53:12 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void lines(t_data *data, t_map *map)
{
    int x;
    int y;

    // Allocate memory for both horizontal and vertical lines
    map->axis = malloc(2 * sizeof(t_2d_coord));
    if (!map->axis)
        return;
    // Draw horizontal lines
    y = 0;
    while (y < map->max_2d_crds->y)
    {
        x = 0;
        while (x < map->max_2d_crds->x - 1)
        {
            if (y * map->max_2d_crds->x + x + 1 >= map->max_2d_crds->x * map->max_2d_crds->y)
                break;

            map->axis[0].x = map->arr_of_3d_crds[y * map->max_2d_crds->x + x].x;
            map->axis[0].y = map->arr_of_3d_crds[y * map->max_2d_crds->x + x].y;
            map->axis[1].x = map->arr_of_3d_crds[y * map->max_2d_crds->x + x + 1].x;
            map->axis[1].y = map->arr_of_3d_crds[y * map->max_2d_crds->x + x + 1].y;
            
            draw_line(data->mlx_connection, data->mlx_window, *map, 0x00FF0000);
            x++;
        }
        y++;
    }

    // Draw vertical lines
    x = 0;
    while (x < map->max_2d_crds->x)
    {
        y = 0;
        while (y < map->max_2d_crds->y - 1)
        {
            if ((y + 1) * map->max_2d_crds->x + x >= map->max_2d_crds->x * map->max_2d_crds->y)
                break;

            map->axis[0].x = map->arr_of_3d_crds[y * map->max_2d_crds->x + x].x;
            map->axis[0].y = map->arr_of_3d_crds[y * map->max_2d_crds->x + x].y;
            map->axis[1].x = map->arr_of_3d_crds[(y + 1) * map->max_2d_crds->x + x].x;
            map->axis[1].y = map->arr_of_3d_crds[(y + 1) * map->max_2d_crds->x + x].y;
            
            draw_line(data->mlx_connection, data->mlx_window, *map, 0x00FF0000);
            y++;
        }
        x++;
    }

    // free(map->axis);
}

void draw_line(void *mlx_ptr, void *win_ptr, t_map map, int color)
{
    int dx = abs((int)map.axis[1].x - (int)map.axis[0].x);
    int dy = -abs((int)map.axis[1].y - (int)map.axis[0].y);
    int sx = map.axis[0].x < map.axis[1].x ? 1 : -1;
    int sy = map.axis[0].y < map.axis[1].y ? 1 : -1;
    int err = dx + dy;
    int e2;
    int	x = (int)map.axis[0].x;
    int y = (int)map.axis[0].y;

    while (1)
    {
        // Prüfe ob der Punkt innerhalb des Fensters liegt
        if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
            
        // Prüfe ob Endpunkt erreicht wurde
        if (x == (int)map.axis[1].x && y == (int)map.axis[1].y)
            break;
            
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y += sy;
        }
    }
}
