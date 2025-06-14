/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:41:17 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 23:20:27 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_no_event(void *data)
{
	void	*test;

	test = data;
	data++;
	return (0);
}

int	handle_input(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		if (data->image)
			mlx_destroy_image(data->mlx_connection, data->image);
		if (data->mlx_window)
			mlx_destroy_window(data->mlx_connection, data->mlx_window);
		free(data->mlx_connection);
		exit(0);
	}
	return (0);
}

int	main(int argc, char**argv)
{
	t_data	data;
	t_map	map;

	if (argc == 2)
	{
		if (init_minilibx(&data) == -1)
			return (1);
		if (check_input(argv[1], &data) == -1)
			return (ft_mlx_exit(&data), 1);
		map.min_max = NULL;
		if (parsing(argv[1], &map) == -1)
			return (free_garbage(&map, 1), ft_mlx_exit(&data), 1);
		if (transform(&map) == -1)
			return (free_garbage(&map, 2), ft_mlx_exit(&data), 1);
		if (draw(&data, &map) == -1)
			return (free_garbage(&map, 2), ft_mlx_exit(&data), 1);
		mlx_put_image_to_window(data.mlx_connection, data.mlx_window,
			data.image, 0, 0);
		mlx_loop_hook(data.mlx_connection, &handle_no_event, &data);
		mlx_key_hook(data.mlx_window, &handle_input, &data);
		mlx_loop(data.mlx_connection);
		return (free_garbage(&map, 2), ft_mlx_exit(&data), 0);
	}
	else
		return (printf("./fdf <infile.fdf>\n"), 0);
}
