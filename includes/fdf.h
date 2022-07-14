/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:27:55 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/14 12:56:40 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FD_ERROR "File descriptor error"
# define ARG_ERROR "Too many or too few Arguments"
# define LINE_ERROR "The lines are of uneven length"
# define INVALID_COLOR_CODE "Invalid color code"
# define MALLOC_ERROR_MESSAGE "Malloc Error\n"
# define WINDOW_WIDTH 1920
# define WINDOW_DEPETH 1080
# define ESP_KEY 53
# define T_OPVIEW 17
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ZOOM_IN 24
# define ZOOM_OUT 27
# define X_CLOCKWISE 7
# define Y_CLOCKWISE 16
# define Z_CLOCKWISE 6
# define X_CCLOCKWISE 0
# define Y_CCLOCKWISE 11
# define Z_CCLOCKWISE 8
# define INITIAL_POSITION 34
# define WAVE 13
# define SCAN 1
# define X 0
# define Y 1

//# include <libft.h> 
# include "../libft/libft.h"
//# include <get_next_line.h>
# include "../gnl/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_map_data
{
	void	*mlx;
	void	*window;
	size_t	width;
	size_t	depth;
	int		**height;
	int		**colour;
	double	x_iso;
	double	y_iso;
	double	x1_iso;
	double	y1_iso;
	int		discrim;
	double	dx;
	double	dy;
	int		map_center_x;
	int		map_center_y;
	int		view;
	int		up_down;
	int		right_left;
	int		x_direction;
	int		y_direction;
	double	x_rad;
	double	y_rad;
	double	z_rad;
	double	rotated_x;
	double	rotated_y;
	double	rotated_z;
	int		wave_height;
	int		wave;
	int		zoom;
	int		scan;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_map_data;

typedef struct s_list_split
{
	char				**split_line;
	struct s_list_split	*next;
}	t_list_split;

void	ft_exit(char *error_type);
int		atoi_hex(const char *str);
void	open_read(char *argv, t_map_data *m_d);
void	divide_height_colour(t_list_split *l_s, t_map_data *m_d);
void	split_to_height_colour(t_list_split *l_s, t_map_data *m_d);
void	draw_map(t_map_data *m_d);
void	bresenham_line(t_map_data *m_d, double x, double y, int colour);
void	bresenham_start_point(t_map_data *m_d, int colour);
void	rotation_move(t_map_data *m_d, size_t x, size_t y, int axis);
int		key_conversion(int keycode, t_map_data *m_d);
int		destroy_window(t_map_data *m_d);
void	init(t_map_data *m_d);
void	map_data_init(t_map_data *m_d);
void	rotation(t_map_data *m_d, size_t x, size_t y);
void	initial_position(t_map_data *m_d);
void	position_init(t_map_data *m_d);
void	wave(t_map_data *m_d);
void	scan(t_map_data *m_d);
#endif
