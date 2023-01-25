/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:39 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/25 01:37:59 by mfouadi          ###   ########.fr       */
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

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "WIREFRAME");		
	draw_line(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return(0);
}