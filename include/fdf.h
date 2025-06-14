/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:12:49 by swied             #+#    #+#             */
/*   Updated: 2025/06/14 23:25:44 by swied            ###   ########.fr       */
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

typedef struct s_bh
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;	
	int	x;
	int	y;
	int	x1;
	int	y1;
}	t_bh;

typedef struct s_move
{
	double	move_x;
	double	move_y;
}	t_move;

typedef struct s_min_max
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	full_x;
	double	full_y;
}	t_min_max;

typedef struct s_max_2d_crds
{
	int	x;
	int	y;
}	t_max_2d_crds;

typedef struct s_3d_coord
{
	double	x;
	double	y;
	double	z;
}	t_3d_coord;

typedef struct s_axis
{
	double	x;
	double	y;
}	t_axis;

typedef struct s_map
{
	t_move			*move;
	t_min_max		*min_max;
	t_3d_coord		*arr_of_3d_crds;
	t_max_2d_crds	*max_2d_crds;
	t_axis			*axis;
	t_bh			*bh;
	char			**array;
	double			*new_array;
	double			scale_factor;
}	t_map;

//main.c
int		handle_no_event(void *data);
int		handle_input(int keycode, t_data *data);
int		main(int argc, char**argv);
//parsing.c
int		parsing(char *infile, t_map *map);
char	*fill_content(char *filename);
int		get_dimensions(t_map *map, char **array);
int		count_words(char *line, char sep);
void	get_width_and_height(char *infile, t_map *map);
//utils.c
char	*yeet(char *array, char c, t_map *map);
double	ft_atod(const char *str);
//check.c
int		count_words_in_row(char *line, char sep);
int		check_same_width(char *content, t_map *map);
int		check_ending(char *filename);
int		check_input(char *filename, t_data *data);
int		check_content(char *content, t_map *map);
//offset.c
void	offset(t_map *map);
//rotate.c
void	rotate(t_map *map);
void	rotate_z(t_map *map);
void	rotate_x(t_map *map);
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
int		draw(t_data *data, t_map *map);
void	draw_horizontal_lines(t_data *data, t_map *map, int max_index);
void	draw_vertical_lines(t_data *data, t_map *map, int max_index);
void	init_draw_line(t_map *map);
void	draw_line(t_data *data, t_map *map);
//init_minilibx.c
int		init_minilibx(t_data *data);
void	ft_mlx_exit(t_data *data);
//free.c
void	free_new_content(char **new_content);
void	free_garbage(t_map *map, int flag);
//transform.c
int		transform(t_map *map);
int		get_min_max(t_map *map);

#endif
