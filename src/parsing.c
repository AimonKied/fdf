/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:21:56 by swied             #+#    #+#             */
/*   Updated: 2025/06/13 18:36:55 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_map(char *infile, t_map *map, char *content)
{
	char	*yeeted;
	char	**new_content;

	map->max_2d_crds = malloc(sizeof(t_2d_coord));
	if (!map->max_2d_crds)
		return (-1);
	content = fill_content(infile);
	if (!content)
		return (ft_printf("fill_content failed"), -1);
	if (check_content(content) == -1)
		return (free(content), ft_printf("Wrong type in infile"), -1);
	if (check_same_width(content, map) == -1)
		return (ft_printf("Not same width\n"), -1);
	yeeted = yeet(content, '\n', map);
	if (!yeeted)
		return (free(content),ft_printf("yeet Failed"), -1);
	new_content = ft_split(yeeted, ' ');
	if (!new_content)
		return (free(content), free(yeeted), ft_printf("new_content failed\n"), -1);
	get_width_and_height(infile, &map->max_2d_crds->x, &map->max_2d_crds->y);
	if (get_dimensions(map, new_content) == -1)
		return (-1);
	return (0);
}

char	*fill_content(char *filename)
{
	char	*line;
	char	*content;
	int		fd;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (free(content), NULL);
	while ((line = get_next_line(fd)))
	{
		content = ft_strjoin(content, line);
		free(line);
	}
	close(fd);
	return (content);
}

int	get_dimensions(t_map *map, char **array)
{
	int		y;
	int		x;
	int		i;

	map->arr_of_3d_crds = malloc((map->max_2d_crds->x * map->max_2d_crds->y) * sizeof(t_3d_coord));
	if (!map->arr_of_3d_crds)
		return (perror("Alloc failed"), -1);
	y = 0;
	i = 0;
	while (y < map->max_2d_crds->y)
	{
		x = 0;
		while (x < map->max_2d_crds->x)
		{
			map->arr_of_3d_crds[i].x = (double)x;
			map->arr_of_3d_crds[i].y = (double)y;
			map->arr_of_3d_crds[i].z = ft_atod(array[i]);
			x++;
			i++;
		}
		y++;
	}
	return (0);
}

int	count_words(char *line, char sep)
{
	int	count = 0;
	int	in_word = 0;

	while (*line)
	{
		if (*line != sep && *line != '\n' && in_word == 0)
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

void	get_width_and_height(char *infile, int *x, int *y)
{
	int		fd;
	char	*line;

	*y = 0;
	*x = 0;
	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		perror("Open error");
		return;
	}
	while ((line = get_next_line(fd)))
	{
		if (*y == 0)
			*x = count_words(line, ' ');
		(*y)++;
		free(line);
	}
	if (close(fd) == -1)
		perror("Close error");
}
