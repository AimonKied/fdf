/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:32:04 by swied             #+#    #+#             */
/*   Updated: 2025/06/06 14:46:18 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_input(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		if (data->image)
			mlx_destroy_image(data->mlx_connection, data->image);
		if (data->mlx_window)
		{
			mlx_destroy_window(data->mlx_connection, data->mlx_window);
			free(data->mlx_window);
		}
		free(data->mlx_connection);
		exit(0);
	}
	return (0);
}

void	put_pixel_image(char *data, int x, int y, int color, int bpp, int size_length)
{
	int	pixel_index;
	
	pixel_index = y * size_length + x * (bpp / 8);
	*(unsigned int *)(data + pixel_index) = color;
	return ;
}

int	main(void)
{
	t_data	data;
	t_img	img;

	data.mlx_connection = mlx_init();
	if (data.mlx_connection == NULL)
		return (1);
	data.mlx_window = mlx_new_window(data.mlx_connection, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF swied");
	if (data.mlx_window == NULL)
		return (free(data.mlx_connection), 1);

	data.image = mlx_new_image(data.mlx_connection, WINDOW_WIDTH, WINDOW_HEIGHT);	
	img.address = mlx_get_data_addr(data.image, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	
	int	x = 0;
	int y = 0;
	while (x <=250)
	{
		y = 0;
		while (y <= 250)
		{
			put_pixel_image(data.image, 100, 50, 0x005500, img.bits_per_pixel, img.line_length);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data.mlx_connection, data.mlx_window, data.image, 0, 0);

	mlx_loop_hook(data.mlx_connection, &handle_no_event, &data);
	mlx_key_hook(data.mlx_window, &handle_input, &data);

	mlx_loop(data.mlx_connection);

	free(data.mlx_connection);
}
