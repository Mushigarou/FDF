/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 05:59:28 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/30 01:25:31 by mfouadi          ###   ########.fr       */
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
	int	z_matrix;
	int	x;
	int	y;
	int	color;
}	t_tile;

typedef	struct s_data
{
	int	width;
	int	height;
	t_tile **map;
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

int		get_map(t_data *data);
void	draw_line(void *mlx_ptr, void *win_ptr);
int		init(t_data *data, char **av);
int		cnt_width(char *s, char c);
int		iscomma(char *line);
int		init(t_data *data, char **av);

#endif // fdf.h
