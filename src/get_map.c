/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:48 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/25 08:04:29 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_all(int **p, t_data **data)
{
	int	i;

	i = 0;
	if (p && *p)
	{
		while (p[i])
		{
			free(p[i]);
			i++;
		}
		free(p);
		*p = NULL;
	}
	if (data && *data)
	{
		free(*data);
		*data = NULL;
	}
	return ;
}

/* Incrementing (wc) when (s - 1) is a seperator, and (*s) isn't a seperator */

static int	count_width(const char *s, char c)
{
	unsigned int	w_count;
	int				state;

	state = OUT;
	w_count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			state = OUT;
		else if (*s != c && !state)
		{
			state = IN;
			w_count++;
		}
		s++;
	}
	return (w_count);
}

// void	fill_z_matrix(t_data **data)
// {
	
// }

void	get_width(int fd, t_data **data)
{
	char	*line;

	line = get_next_line(fd);
	(*data)->width = count_width((const char *)line, ' ');
	return ;
}

void    get_height(int fd, t_data **data)
{
	char	*line;

	// I should pass the **data, so i can free and exit in GNL [ TO BE IMPLEMENTED ]
	while ((line = get_next_line(fd)))
	{
		(*data)->height++;
		free(line);
	}
	return ;
}

void    get_map(const char *map_name, t_data **data)
{
	int fd;
	int i;

	i = 0;
// ** Openning the map file
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Cannot open the file descriptor");
		free(*data);
		exit(-1);
	}
// ** Getting x and y and storing them, respectively, in data->width and data->height
	get_width(fd, data);
	get_height(fd, data);
// ** allocating for the matrix
	(*data)->z_matrix = (int **)malloc((*data)->height);
	if (!((*data)->z_matrix))
	{
		perror("Allocation for the matrix failed");
		free_all(NULL, data);
		exit(-2);
	}
	while (i < (*data)->height)
	{
		(*data)->z_matrix[i] = (int *)malloc((*data)->width);
		if ((*data)->z_matrix == NULL)
		{
			perror("Allocation for the matrix failed");
			free_all((*data)->z_matrix, data); // need a function to free **
			exit(-3);
		}
		i++;
	}
// ** Filling the matrix with data. x, y and z
	// fill_z_matrix(&(*data)->z_matrix);
}
