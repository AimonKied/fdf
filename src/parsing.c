/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:04:12 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 23:02:41 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	parsing(char *infile, t_map *map)
{
	char	*content;
	char	*yeeted;
	char	**new_content;

	content = fill_content(infile);
	if (!content)
		return (ft_printf("Fill content failed\n"), -1);
	map->max_2d_crds = malloc(sizeof(t_max_2d_crds));
	get_width_and_height(infile, map);
	if (check_content(content, map) == -1)
		return (free(content), -1);
	yeeted = yeet(content, '\n', map);
	if (!yeeted)
		return (free(content), ft_printf("Yeet failed\n"), -1);
	free(content);
	new_content = ft_split(yeeted, ' ');
	free(yeeted);
	if (!new_content)
		return (ft_printf("New Content failed\n"), -1);
	if (get_dimensions(map, new_content) == -1)
		return (free(new_content), ft_printf("get_dimensions failed\n"), -1);
	return (free_new_content(new_content), 0);
}

char	*fill_content(char *infile)
{
	char	*line;
	char	*content;
	char	*tmp;
	int		fd;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	fd = open(infile, O_RDONLY);
	if (fd == -1)
		return (free(content), NULL);
	line = get_next_line(fd);
	while (line)
	{
		tmp = content;
		content = ft_strjoin(content, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}

int	get_dimensions(t_map *map, char **array)
{
	int		y;
	int		x;
	int		i;

	map->arr_of_3d_crds = malloc((map->max_2d_crds->x * map->max_2d_crds->y)
			* sizeof(t_3d_coord));
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
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
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

void	get_width_and_height(char *infile, t_map *map)
{
	int		fd;
	char	*line;

	map->max_2d_crds->y = 0;
	map->max_2d_crds->x = 0;
	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		perror("Open error");
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		if (map->max_2d_crds->y == 0)
			map->max_2d_crds->x = count_words(line, ' ');
		map->max_2d_crds->y++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		perror("Close error");
}
