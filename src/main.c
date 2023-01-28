/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:39 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/28 03:14:26 by mfouadi          ###   ########.fr       */
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

#include "../include/fdf.h"

// Allocating for struct

// int	main(int argc, char **argv)
// {
// 	t_data	*data;

// 	if (argc != 2)
// 		return (-1);
// 	data = (t_data *)malloc(sizeof(t_data));
// 	if (!data)
// 		return (-1);
// 	// Initialize variables of the list init_struct(**data)
// 	// get_map();
// 	data->mlx_ptr = mlx_init();
// 	// give argv[1] to the title parameter
// 	data->win_ptr = mlx_new_window(data->mlx_ptr, win_width, win_height, argv[1]);		
// 	draw_line(data->mlx_ptr, data->win_ptr);
// 	mlx_loop(data->mlx_ptr);
// 	return(0);
// }
