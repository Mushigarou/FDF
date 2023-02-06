   /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:38:11 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/01 19:06:28 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ** Initiates drawing unit (how much distance would be between x and x1)
int	drawing_unit(int w_w, int w_h, int m_w, int m_h)
{
	double	win_diagonal;
	double	map_diagonal;
	double	draw_unit;

	map_diagonal = m_w * m_w + m_h * m_h;
	map_diagonal = sqrt(map_diagonal);
	win_diagonal = w_w * w_w + w_h * w_h;
	win_diagonal = sqrt(win_diagonal);
	draw_unit = (win_diagonal / 2) / map_diagonal;
	return ((int)draw_unit);
}

// ** Initiates the point from where to start drawing
// void	start_point(int *x, int *y)
// {
// 	return;
// }

// ** Gets width and height of the given map
int	get_map_dimensions(t_data *data)
{
	int		fd;
	char	*s;

	fd = open(data->file_name , O_RDONLY);
	if (fd < 0)
		return (perror("Failed to open the file.	init.c"), free_matrix(data->map_matrix), -1);
	s = get_next_line(fd);
	if (!s)
		return (perror("GNL_Failed.	init.c"), close(fd), -1);
	data->width = cnt_width(s, ' ');
	if (!data->width)
		return (free(s), free_matrix(data->map_matrix), close(fd), -1);
	while (s)
	{
		data->height++;
		free(s);
		s = get_next_line(fd);
		if (s && ((cnt_width(s, ' ')) != data->width))
			return (perror("Error occured (map width is not the same).	init.c"), free(s), free_matrix(data->map_matrix), close(fd), -1);
	}
	close(fd);
	return 0;
}

// ** Allocates for t_tile **
int	allocate_map(t_data *data)
{
	int	i;

	i = 0;
	data->map_matrix = malloc(sizeof(t_tile *) * (data->height + 1));
	if (!data->map_matrix)
		return (perror("Malloc Failed."), -1);
	data->map_matrix[data->height] = NULL;
	while (i < data->height)
	{
		data->map_matrix[i] = malloc(sizeof(t_tile) * (data->width));
		if (!data->map_matrix[i])
			return (perror("Malloc Failed."), free_matrix(data->map_matrix), -1);
		i++;
	}
	return (0);
}

/* 
** Initiates struct, map dimensions, allocations, z value, color, start point
** of drawing, drawing unit (scale)
*/
int	init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	if (get_map_dimensions(data) < 0)
		exit(-1);
	if (allocate_map(data) < 0)
		exit (-1);
	get_z(data, data->file_name);
	// int	drawing_unit(int w_w, int w_h, int m_w, int m_h)
	// void	start_point(int *x, int *y)
	return 0;
}
