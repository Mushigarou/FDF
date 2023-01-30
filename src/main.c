/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:39 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/30 02:29:11 by mfouadi          ###   ########.fr       */
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

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	data;
	if (ac != 2)
		return (perror("An argument is missing <executable> <map_name> "), 1);
	init(&data, av);	
	return(0);
}
