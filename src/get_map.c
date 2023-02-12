/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:48 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/12 02:07:52 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Getting color and z value for each tile of the map
**	Default color = white  && default z = 0
*/
t_tile get_tile(char *s)
{
	t_tile	tile;
	t_data	*data;
	char	**split;

	data = NULL;
	split = NULL;
	if (!s)
		return (tile.invalid = 1, tile);
	tile.color = 0x00FFFFFF;
	if (!(strchr((const char *)s, ',')))
	{
		
		tile.z = ft_atoi((const char *)s);
		if (tile.z != 0)
			tile.color = 0x00FFFF00;
	}
	else
	{
		split = ft_split(s, ',');
		if (ft_strncmp(split[1], "0x", 2) == 0)
			tile.color = ft_strtol((split[1] + 2));
		tile.z = ft_atoi((const char *)split[0]);
		free_split(split);
	}
	return (tile);
}

/*
** Openning the map file, then iterating on each line until the end of the map
** Each line is passed to get_tile()
*/
int get_z(t_data *data, char *map_name)
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
			data->map_matrix[i][j] = get_tile(split[j]);
			if (data->map_matrix[i][j].invalid == 1)
				return (free_matrix(data->map_matrix), free_split(split), free(data), -1);
			j++;
		}
		i++;
		free(line);
		free_split(split);
	}
	close(fd);
	return 0;
}
