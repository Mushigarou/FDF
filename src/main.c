/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:39 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/06 05:32:27 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Segfault when there is a comma without a color
// Sigfault when there is color without z
// Sigfault when there is only a comma (OR ANY OTHER CHARACTER)
// sigfault NULL* is the first char \\ echo '\0' >> test_maps/10-70.fdf

// Needs to free *data elsewhere

// Make doesn't recognize changes in this file (command make) (Makefile)

#include "fdf.h"
/*
**	Calling mlx_init() to initiate a connection with the graphical system
**	Calling mlx_new_win() to open a window
**	
*/
int	main(int argc, char **argv)
{
	t_data	*data;

	data = (struct s_data)malloc(sizeof(t_data));
	if (argc != 2)
		return (-1);
	data->file_name = argv[1];
	data->mlx_ptr = mlx_init();
	data->mlx_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, data->file_name);
	// ...
	mlx_loop(data->mlx_ptr);
	return (0);
}
