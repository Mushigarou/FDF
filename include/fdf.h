/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 05:59:28 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/08 05:53:45 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "libft.h"

// ** width and height of the window
#define SCREEN_WIDTH 1980
#define SCREEN_HEIGHT 1080

// ** Accessing each tile of the map
typedef	struct s_tile
{
	int		z;
	int		z1;
	int		color;
	int		invalid;
}	t_tile;

// ** Accessing different type of data in a single place
typedef	struct s_data
{
	t_tile	**map_matrix;
	char	*file_name;
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}	t_data;

// // ** Start point of drawing
// typedef	struct s_line
// {
// 	double	x;
// 	double	y;
// 	double	x1;
// 	double	y1;
// }	t_line;

// ** Initiates structure
int		init(t_data *data, char **av);
// ** Map dimensions
int		get_z(t_data *data, char *map_name);
// ** Frees allocated memory
void	free_split(char **s);
void	free_matrix(t_tile **s);
// ** Counts width of the given map
int		cnt_width(char *s, char c);
// ** Converts hexadecimal to decimal
int		ft_strtol(char *str);
// ** draws a line between two points
void	draw_line(float x, float y, float x1, float y1, t_data *data);
// ** Draws lines between the points of the map
void	draw_tile(t_data *data);
// ** Checks whether the map is empty or not
int		map_is_empty(char *s);

#endif // fdf.h
