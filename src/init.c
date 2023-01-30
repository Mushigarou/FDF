/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:38:11 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/30 01:43:08 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int	get_map_dimensions(t_data *data)
{
	int		fd;
	char	*s;
	
	
	fd = open(data->file_name , O_RDONLY);
	if (fd < 0)
		return (perror("Failed to open the file.	init.c"),1);
	s = get_next_line(fd);
	if (!s)
		return (perror("GNL_Failed.	init.c"), close(fd), 1);
	data->width = cnt_width(s, ' ');
	if (!data->width)
		return (free(s),close(fd), 1);
	while (s)
	{
		data->height++;
		free(s);
		s = get_next_line(fd);
		if (!s)
			return (close(fd), 1);
		if ((cnt_width(s, ' ')) != data->width)
			return (perror("Error occured (map width).	init.c"), free(s), close(fd), 1);
	}
	close(fd);
	return 0;
}

void	allocate_map(t_data *data)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(t_tile *) * (data->height));
	while (i < data->height)
	{
		data->map[i] = malloc(sizeof(t_tile) * data->width);
		i++;
	}
}

// don't free file_name
int	init(t_data *data, char **av)
{
	ft_bzero(data, sizeof(t_data));
	data->file_name = av[1];
	get_map_dimensions(data);
	allocate_map(data);
	get_map(data);
	return 0;
}
