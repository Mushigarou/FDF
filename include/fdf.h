/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 05:59:28 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/31 03:56:59 by mfouadi          ###   ########.fr       */
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
// #include "../Libft/get_next_line.h"
#include "../Libft/libft.h"

#define IN 1
#define OUT 0
#define win_width 1980
#define win_height 1080

typedef	struct s_tile
{
	int	x;
	int	y;
	int	z;
	int	color;
	int 	invalid;
}	t_tile;

typedef	struct s_data
{
	int		width;
	int		height;
	t_tile	**map_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*file_name;
}	t_data;

typedef	struct s_line
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
}	t_line;

int		init(t_data *data, char **av);
int get_map(t_data *data, char *map_name);
void draw_line(void *mlx_ptr, void *win_ptr);
void	free_split(char **s);
void free_matrix(t_tile **s);
int cnt_width(char *s, char c);
int ft_strtol(char *str);

#endif // fdf.h
