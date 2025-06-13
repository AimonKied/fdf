/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:12:49 by swied             #+#    #+#             */
/*   Updated: 2025/06/13 18:47:05 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_mms_20191025_beta/mlx.h"
# include "libft/libft.h"

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


typedef struct s_img
{
	void	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_connection;
	void	*mlx_window;
	void	*image;
	t_img	img;
}	t_data;

typedef struct s_move
{
	double	move_x;
	double	move_y;
}	t_move;

typedef struct s_min_max
{
	double 	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	full_x;
	double	full_y;
}	t_min_max;

typedef struct s_2d_coord
{
	int	x;
	int	y;
}	t_2d_coord;

typedef struct s_3d_coord
{
	double x;
	double y;
	double z;
}	t_3d_coord;

typedef struct s_axis
{
	double	x;
	double	y;
}	t_axis;

typedef struct s_map
{
	t_move		*move;
	t_min_max	*min_max;
	t_3d_coord 	*arr_of_3d_crds;
	t_2d_coord 	*max_2d_crds;
	t_axis		*axis;
	char		**array;
	double		*new_array;
	double		scale_factor;
}	t_map;



// void	draw_line(void *mlx_ptr, void *win_ptr,t_map axis[2],int color);
// void 	draw_circle(void *mlx_ptr,void *win_ptr,int x,int y,int color);
// int		get_map(char *infile, t_map *map, char *content);
// int		check_input(char *filename);
// int		check_ending(char *filename);
// void	get_dimensions(char *infile, double *width, double *height);
// char	*fill_content(char *filename);
// int		check_content(char *content);
// int		check_same_width(char *content, t_map *map);
// int		count_words(char *line, char sep);
// int		count_words_in_row(char *line, char sep);
// char	*yeet(char *array, char c, t_map *map);
// void	get_2d(t_map map, t_data data);
// void	get_z(t_map *map);
// double	ft_atod(const char *str);

//main.c
int		get_map(char *infile, t_map *map, char *content);
int		check_input(char *filename);
//parsing.c
char	*fill_content(char *filename);
int		get_dimensions(t_map *map, char **array);
int		count_words(char *line, char sep);
void	get_width_and_height(char *infile, int *x, int *y);
//utils.c
char	*yeet(char *array, char c, t_map *map);
double	ft_atod(const char *str);
//check.c
int		check_content(char *content);
int		check_ending(char *filename);
int		check_same_width(char *content, t_map *map);
int		count_words_in_row(char *line, char sep);
void	offset(t_map *map);
void	offset_back(t_map *map);
//rotate.c
void	transform_to_2d(t_map map);
void	rotate(t_map *map);
void	rotate_z(t_map *map);
void	rotate_x(t_map *map);
void	rotate_y(t_map *map);
//find_xy.c
int		find_min_max(t_map *map);
void	f_min_x(t_map *map);
void	f_max_x(t_map *map);
void	f_min_y(t_map *map);
void	f_max_y(t_map *map);
//scale.c
void	get_scale_factor(t_map *map);
void	execute_scale(t_map *map);
//move.c
int		get_move(t_map *map);
void	execute_move(t_map *map);
//draw.c
void	lines(t_data *data, t_map *map);
void	draw_line(void *mlx_ptr, void *win_ptr,t_map map,int color);
//init_minilibx.c
int		init_minilibx(t_data *data);
#endif
