/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:39 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/06 00:52:28 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*   representation of a 3D landscape by linking various points (x, y, z)
*   
*/

/* How to use MinLibx 
	# Add  -framework OpenGL -framework AppKit to the compilation since MinLibx uses them
	
	# Initialization :
		1 : Include header <mlx_ptr.h>	
		2 : call mlx_init() function. This will establish a connection to the correct graphical
			system. it returns a void *.
		3 : call mlx_new_window() function to create a window. it returns a void *.
		4 : call mlx_loop() function to initiate the window rendering
	
	# Writing pixels to a image :
		# call mlx_pixel_put() function.
		# 0xTTRRGGBB // Colors are represented as int
			# T : Transparency
			# R : Red
			# G : Green
			# B : Blue
			
		| 0 | R | G | B |   color integer
        +---+---+---+---+
		
*/

// Segfault when there is a comma without a color
// Sigfault when there is color without z
// Sigfault when there is only a comma (OR ANY OTHER CHARACTER)
// sigfault NULL* is the first char \\ echo '\0' >> test_maps/10-70.fdf
#include "fdf.h"
// int	main(int ac, char **av)
// {
// 	int	i = 0;
// 	int	j = 0;
// 	t_data	data;

// 	if (ac != 2)
// 		return (perror("An argument is missing <executable> <map_name> "), -1);
// 	init(&data, av);
// 	// while (i < data.height)
// 	// {
// 	// 	j = 0;
// 	// 	while (j < data.width)
// 	// 	{
// 	// 		printf("%5d,%5d", data.map_matrix[i][j].z, data.map_matrix[i][j].color);
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// 	printf("\n");
// 	// }
	
// 	return(0);
// }

// int main()
// {
// 	double  x = 152 ^ 95;

// 	printf("x = %f || x = %d\n", x, (int)x);
// 	printf("i = %lu  ||  d = %lu ", sizeof(double), sizeof(int));
// }

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (-1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	// Initialize variables of the list init_struct(**data)
	// get_map();
	data->mlx_ptr = mlx_init();
	// give argv[1] to the title parameter
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, argv[1]);
	draw_line(55.0, 55.0, 100.0, 300.0, data);
	draw_line(100.0, 300.0, 500.0, 400.0, data);
	// draw_line(500.0, 400.0, 55.0, 55.0, data);
	// printf("wa rani wsselt hna");
	mlx_loop(data->mlx_ptr);
	return(0);
}
