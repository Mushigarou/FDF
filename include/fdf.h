/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 05:59:28 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/06 00:18:30 by mfouadi          ###   ########.fr       */
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
#include "../Libft/libft.h"

#define IN 1
#define OUT 0
#define WIN_WIDTH 1980
#define WIN_HEIGHT 1080

typedef	struct s_tile
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		invalid;
}	t_tile;

typedef	struct s_data
{
	t_tile	**map_matrix;
	char	*file_name;
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}	t_data;

typedef	struct s_line
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
}	t_line;

int		init(t_data *data, char **av);
int		get_map(t_data *data, char *map_name);
void	free_split(char **s);
void	free_matrix(t_tile **s);
int		cnt_width(char *s, char c);
int		ft_strtol(char *str);
void draw_line(double x, double y, double x1, double y1, t_data *data);

#endif // fdf.h
