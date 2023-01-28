/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:48 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/28 03:43:13 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fill_z_matrix(const char *map_name, t_data **data, int fd)
{
	char	*line;
	int 	j;
	int		i;
	int		x;
	char	**tmp1;
	char	**tmp2;
	
	i = 0;
	x = 0;
// ** Openning the map file
	if ((fd = open(map_name, O_RDONLY)) < 0)
	{
		perror("Cannot open the file descriptor");
		free_all((*data)->z_matrix, data);
		exit(-1);
	}

// ** filling the matrix
// ** same thing here, GNL should be re-written 
	while ((line = get_next_line(fd)))
	{
		j = 0;
		i = 0;
		tmp1 = ft_split(line, ' ');
		if (iscomma(line))
		{
			tmp2 = ft_split(line, ',');
			while (tmp2[i])
			{
				if (strncmp((const char *)tmp2[i], "0x", 2))
				{
					(*data)->color[i] = tmp2[i];
				}
				else
				{
					(*data)->z_matrix[x][j] = atoi((const char *)tmp2[i]);
				}
				i++;
			}
			free(tmp2);
			
		}
		else
		{
			while (tmp1[i])
			{
				(*data)->z_matrix[x][j] = atoi((const char *)tmp1[i]);
				i++;
				j++;
			}	
	
		}
		free(tmp1);
		x++;
	}
	return;
}

void	get_width(const char *map_name, t_data **data)
{
	char	*line;
	int 	fd;

// ** Openning the map file
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Cannot open the file descriptor");
		free_all((*data)->z_matrix, data);
		exit(-1);
	}

// ** getting the width of the line
	line = get_next_line(fd);
	(*data)->width = cnt_width(line, ' ');
	close(fd);
	return ;
}

void    get_height(const char *map_name, t_data **data)
{
	char	*line;
	int 	fd;

// ** Openning the map file
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Cannot open the file descriptor");
		free_all((*data)->z_matrix, data);
		exit(-1);
	}

// ** I should pass the **data, so i can free and exit in GNL [ TO BE IMPLEMENTED ]
	while ((line = get_next_line(fd)))
	{
		(*data)->height++;
		free(line);
	}
	close (fd);
	return ;
}

void    get_map(const char *map_name, t_data **data)
{
	int i;

	i = 0;

// ** Getting x and y and storing them, respectively, in data->width and data->height
	get_width(map_name, data);
	get_height(map_name, data);

// ** allocating for the z_matrix**
	(*data)->z_matrix = (int **)malloc((*data)->height);
	if (!((*data)->z_matrix))
	{
		perror("Allocation for the matrix failed");
		free_all(NULL, data);
		exit(-2);
	}
// ** allocating for the z_matrix*
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
	fill_z_matrix(map_name, data, 0);
	return ;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;
	int		j;

	if (argc == 0)
		return (perror("Put the fucking map, IDIOT!!!\n"), -1);
	i = 0;
	get_map((const char *)argv[1], &data);
	while (data->z_matrix[i])
	{
		j = 0;
		while (data->z_matrix[i][j])
		{
			printf("%d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

// int main()
// {
// 	int **line;
// 	int	i =0;
// 	int j = 0;
	
// 	line = (int **)malloc(5000 * sizeof(int));
// 	line[i] = (int *)malloc(100 * sizeof(int));
// 	// line[4] = (int *)2500;
// 	line[0][0] = 2500;
// 	line[0][1] = 2500;
// 	line[0][2] = 2500;
// 	line[0][3] = 252200;
// 	while (line[0][j])
// 	{
// 		printf("%d\n", line[i][j]);
// 		j++;
// 	}
// }