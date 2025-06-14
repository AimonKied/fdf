/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:42:18 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 23:22:47 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h" 

void	free_new_content(char **new_content)
{
	int	i;

	i = 0;
	while (new_content[i])
	{
		free(new_content[i]);
		i++;
	}
	free(new_content);
}

void	free_garbage(t_map *map, int flag)
{
	if (flag == 2)
		free(map->min_max);
	free(map->max_2d_crds);
	free(map->arr_of_3d_crds);
}
