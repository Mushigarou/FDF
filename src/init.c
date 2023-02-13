/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:38:11 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/12 23:42:53 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ** Initiates the point from where to start drawing
void	center_map(t_pt *pt, float *x1, float *y1, t_data *data)
{
	pt->x += (SCREEN_WIDTH / 2) + data->shift_x;
	pt->y += (SCREEN_HEIGHT / 8) + data->shift_y;
	*x1 += (SCREEN_WIDTH / 2) + data->shift_x;
	*y1 += (SCREEN_HEIGHT / 8) + data->shift_y;
}

// ** Gets width and height of the given map
int	get_map_dimensions(t_data *data, int fd, char *s)
{
	fd = open(data->file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Failed to open the file		init.c"),
			free(data), -1);
	s = get_next_line(fd);
	if (!s)
		return (perror("GNL_Failed.	init.c"), close(fd), free(data), -1);
	data->width = cnt_width(s, ' ');
	if (!data->width)
		return (free(s), free(data), close(fd), -1);
	while (s)
	{
		data->height++;
		free(s);
		s = get_next_line(fd);
		if (s && ((cnt_width(s, ' ')) != data->width))
		{
			perror("Error occured (map width is not the same).init.c");
			return (free(data), close(fd), free(s), -1);
		}
	}
	close(fd);
	return (0);
}

// ** Allocates for t_tile **
int	allocate_map(t_data *data)
{
	int	i;

	i = 0;
	data->map_matrix = malloc(sizeof(t_tile *) * (data->height + 1));
	if (!data->map_matrix)
		return (perror("Malloc Failed."), free(data), -1);
	data->map_matrix[data->height] = NULL;
	while (i < data->height)
	{
		data->map_matrix[i] = malloc(sizeof(t_tile) * (data->width));
		if (!data->map_matrix[i])
			return (perror("Malloc Failed."),
				free_matrix(data->map_matrix), free(data), -1);
		i++;
	}
	return (0);
}

/* 
** Initiates struct, map dimensions, allocations, z value, color, start point
** of drawing, drawing unit (scale)
*/
int	init(t_data *data, char **av)
{
	ft_memset(data, 0, sizeof(t_data));
	data->file_name = av[1];
	if (get_map_dimensions(data, 0, NULL) < 0)
		exit(-1);
	if (allocate_map(data) < 0)
		exit (-1);
	get_z(data, data->file_name);
	return (0);
}
