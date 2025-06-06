/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:12:49 by swied             #+#    #+#             */
/*   Updated: 2025/06/06 02:29:01 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_mms_20191025_beta/mlx.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ARROW_UP 126
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124

typedef struct s_data
{
	void	*mlx_connection;
	void	*mlx_window;
	void	*image;
}	t_data;

typedef struct s_img
{
	void	*address;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_img;


#endif
