/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:59:07 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 23:20:54 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	count_words_in_row(char *line, char sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*line && *line != '\n')
	{
		if (*line != sep && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*line == sep || *line == '\n')
			in_word = 0;
		line++;
	}
	return (count);
}

int	check_same_width(char *content, t_map *map)
{
	int	y;
	int	i;
	int	current_num;
	int	new_num;

	y = 0;
	i = 0;
	current_num = count_words_in_row(content, ' ');
	while (y < map->max_2d_crds->y)
	{
		while (content[i] != '\n' && content[i] != '\0')
			i++;
		if (content[i] == '\n')
			i++;
		else if (content[i] == '\0')
			return (0);
		new_num = count_words_in_row(content + i, ' ');
		if (new_num != current_num)
			return (-1);
		y++;
	}
	return (0);
}

int	check_ending(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (-1);
	if (filename[len - 4] != '.'
		|| filename[len - 3] != 'f'
		|| filename[len - 2] != 'd'
		|| filename[len - 1] != 'f')
		return (-1);
	return (0);
}

int	check_input(char *filename, t_data *data)
{
	if (check_ending(filename) == -1)
	{
		mlx_destroy_image(data->mlx_connection, data->image);
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		return (perror("Only .fdf allowed"), -1);
	}
	return (0);
}

int	check_content(char *content, t_map *map)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] != ' ' && ft_isdigit(content[i])
			== 0 && content[i] != '\n' && content[i] != '-')
		{
			ft_printf("Wrong value: %c\n", content[i]);
			return (-1);
		}
		i++;
	}
	if (check_same_width(content, map) == -1)
		return (ft_printf("Not same width\n"), -1);
	return (0);
}
