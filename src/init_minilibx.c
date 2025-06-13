/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:16:57 by swied             #+#    #+#             */
/*   Updated: 2025/06/13 18:19:15 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	init_minilibx(t_data *data)
{
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		return (perror("MLX init"), -1);
	data->mlx_window = mlx_new_window(data->mlx_connection, WINDOW_WIDTH, WINDOW_HEIGHT, "swied FDF");
	if (!data->mlx_window)
		return (free(data->mlx_connection), perror("MLX Window init"), -1);
	data->image = mlx_new_image(data->mlx_connection, WINDOW_WIDTH, WINDOW_HEIGHT);
	if(!data->image)
		return (mlx_destroy_window(data->mlx_connection, data->mlx_window), free(data->mlx_connection), perror("MLX Image init"), -1);
	data->img.address = mlx_get_data_addr(data->image, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	return (0);
}
