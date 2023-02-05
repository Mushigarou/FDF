/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:48 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/05 03:18:51 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tile get_tile(char *s, int i, int j)
{
	t_tile	tile;
	t_data	*data;
	char	**split;

	data = NULL;
	if (!s)
		return (tile.invalid = 1, tile);
	split = NULL;
	tile.color = 16777215;
	if (!(strchr((const char *)s, ',')))
	{
		tile.z = ft_atoi((const char *)s);
		tile.x = i;
		tile.y = j;
	}
	else
	{
		// should rewrite this, so when there is no color, black would be the default
		// and z = 0
		split = ft_split(s, ',');
		if (!split[1])
		{
			perror("No color is entered");
			free_matrix(data->map_matrix);
			free(s);
			exit(-1);
		}
		tile.z = ft_atoi((const char *)split[0]);
		tile.color = ft_strtol((split[1] + 2));
		tile.x = i;
		tile.y = j;
	}
	return (tile);
}

int get_map(t_data *data, char *map_name)
{
	char	*line;
	char	**split;
	int		j;
	int		i;
	int		fd;

	i = 0;
	j = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (free_matrix(data->map_matrix), -1);
	while ((line = get_next_line(fd)))
	{
		j = 0;
		split = ft_split(line, ' ');
		if(!split)
			return (perror("Split Failed"), free_matrix(data->map_matrix), -1);
		while (j < data->width)
		{
			data->map_matrix[i][j] = get_tile(split[j], i, j);
			// if (data->map_matrix[i][j].invalid == 1)
			// 	return (-1);
			j++;
		}
		i++;
		free(line);
		free_split(split);
	}
	close(fd);
	return 0;
}
