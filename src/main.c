/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:18:01 by swied             #+#    #+#             */
/*   Updated: 2025/06/13 19:56:39 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_no_event(void *data)
{
	void	*test;

	test = data;
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

int	main(int argc, char **argv)
{
	t_map	map;
	t_data	data;
	char	*content;

	map.min_max = NULL;
	map.move = NULL;
	map.max_2d_crds = NULL;
	map.arr_of_3d_crds = NULL;
	map.axis = NULL;
	content = NULL;

	if(init_minilibx(&data) == -1)
		return (1);
	if (argc != 2)
		return (perror("Bad Arguments"), 1);
	if (check_input(argv[1]) == -1)
		return (1);
	if (get_map(argv[1], &map, content) == -1)
		return (1);

	offset(&map);	

	rotate(&map);
	
	find_min_max(&map);

	get_scale_factor(&map);

	execute_scale(&map);

	find_min_max(&map);

	get_move(&map);

	execute_move(&map);
	
	lines(&data, &map);

	mlx_clear_window(data.mlx_connection, data.mlx_window);
	mlx_put_image_to_window(data.mlx_connection, data.mlx_window, data.image, 0, 0);

	mlx_loop_hook(data.mlx_connection, &handle_no_event, &data);
	mlx_key_hook(data.mlx_window, &handle_input, &data);

	mlx_loop(data.mlx_connection);

	free(map.move);
	free(map.min_max);
	free(map.max_2d_crds);
	free(map.arr_of_3d_crds);
	return (0);
}
