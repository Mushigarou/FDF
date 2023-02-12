/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:48 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/12 20:22:00 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fill_z(t_data *data, int i, int j, int fd);

/*
** Counts line width based on a seperator
** Incrementing (wc) when (s - 1) is a seperator, and (*s) isn't a seperator
*/
int	cnt_width(char *s, char c)
{
	unsigned int	w_count;
	int				state;
	int				i;

	i = 0;
	state = OUT;
	w_count = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			state = OUT;
		else if (ft_isdigit(s[i]) && s[i] != c && !state)
		{
			state = IN;
			w_count++;
		}
		i++;
	}
	return (w_count);
}

/*
** Getting color and z value for each tile of the map
**	Default color = white  && default z = 0
*/
t_tile	get_tile(char *s, int width)
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
		if (tile.z != 0 && width < 25)
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
int	get_z(t_data *data, char *map_name)
{
	int		j;
	int		i;
	int		fd;

	i = 0;
	j = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (free_matrix(data->map_matrix), free(data), -1);
	fill_z(data, i, j, fd);
	close(fd);
	return (0);
}

int	fill_z(t_data *data, int i, int j, int fd)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		split = ft_split(line, ' ');
		if (!split)
			return (perror("Split Failed"), free_matrix(data->map_matrix),
				free(data), -1);
		while (j < data->width)
		{
			data->map_matrix[i][j] = get_tile(split[j], data->width);
			if (data->map_matrix[i][j].invalid == 1)
				return (free_matrix(data->map_matrix), free_split(split),
					free(data), -1);
			j++;
		}
		i++;
		free(line);
		free_split(split);
		line = get_next_line(fd);
	}
	return (0);
}
