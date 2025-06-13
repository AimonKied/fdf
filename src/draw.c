/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:32:10 by swied             #+#    #+#             */
/*   Updated: 2025/06/13 19:28:33 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void lines(t_data *data, t_map *map)
{
    int x;
    int y;
    int max_index;

    // Sicherheitscheck für NULL-Pointer
    if (!map || !map->max_2d_crds || !map->arr_of_3d_crds)
        return;

   max_index = (map->max_2d_crds->x * map->max_2d_crds->y);

    // Allokiere Speicher für die Achsen
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
            int current_index = y * map->max_2d_crds->x + x;
            int next_index = current_index + 1;

            // Überprüfe Array-Grenzen
            if (current_index > max_index || next_index > max_index)
                break;

            map->axis[0].x = map->arr_of_3d_crds[current_index].x;
            map->axis[0].y = map->arr_of_3d_crds[current_index].y;
            map->axis[1].x = map->arr_of_3d_crds[next_index].x;
            map->axis[1].y = map->arr_of_3d_crds[next_index].y;
            
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
            int current_index = y * map->max_2d_crds->x + x;
            int next_index = current_index + map->max_2d_crds->x;

            // Überprüfe Array-Grenzen
            if (current_index > max_index || next_index > max_index)
                break;

            map->axis[0].x = map->arr_of_3d_crds[current_index].x;
            map->axis[0].y = map->arr_of_3d_crds[current_index].y;
            map->axis[1].x = map->arr_of_3d_crds[next_index].x;
            map->axis[1].y = map->arr_of_3d_crds[next_index].y;
            
            draw_line(data->mlx_connection, data->mlx_window, *map, 0x00FF0000);
            y++;
        }
        x++;
    }

    free(map->axis);
}

void draw_line(void *mlx_ptr, void *win_ptr, t_map map, int color)
{
    int dx = abs((int)map.axis[1].x - (int)map.axis[0].x);
    int dy = -abs((int)map.axis[1].y - (int)map.axis[0].y);
    int sx = map.axis[0].x < map.axis[1].x ? 1 : -1;
    int sy = map.axis[0].y < map.axis[1].y ? 1 : -1;
    int err = dx + dy;
    int e2;
    int x = (int)map.axis[0].x;  // Verwende int statt double
    int y = (int)map.axis[0].y;  // Verwende int statt double
    int x1 = (int)map.axis[1].x; // Endpunkt X
    int y1 = (int)map.axis[1].y; // Endpunkt Y

    while (1)
    {
        if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
            
        if (x == x1 && y == y1)  // Vergleiche Integer-Werte
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
