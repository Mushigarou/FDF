/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:38:11 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/31 04:07:44 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



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
		// if (!s)
		// 	return (close(fd), -1);
		// if ((cnt_width(s, ' ')) != data->width)
		// 	return (perror("Error occured (map width is not the same).	init.c"), free(s), close(fd), -1);
	}
	close(fd);
	return 0;
}

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
			return (perror("Malloc Failed."), -1);
		i++;
	}
	return (0);
}

// don't free file_name
int	init(t_data *data, char **av)
{
	ft_bzero(data, sizeof(t_data));
	data->file_name = av[1];
	if (get_map_dimensions(data) < 0)
		exit(-1);
	if (allocate_map(data) < 0)
		exit (-1);
	printf("\nhey\n");
	// if (get_map(data, data->file_name) != 0)
	// 	free_matrix(data->map_matrix);exit(-1);
	get_map(data, data->file_name);
	return 0;
}
