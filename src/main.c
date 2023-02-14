/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:39 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/14 05:11:12 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// **	Exits program after clicking on red cross button
int	mouse(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

// **	Handles key events, then draws the image again
int	deal_key(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	if (key == UP_ARROW)
		data->shift_y -= 20;
	if (key == LEFT_ARROW)
		data->shift_x -= 20;
	if (key == DOWN_ARROW)
		data->shift_y += 20;
	if (key == RIGHT_ARROW)
		data->shift_x += 20;
	if (key == P)
		data->bool = 1;
	if (key == I)
		data->bool = 0;
	if (key == MINUS_KEY)
		data->zoom_out += 1;
	if (key == PLUS_KEY)
		data->zoom_in += 1;
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ln, &data->en);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

/*
**	To link MiniLibX on MACOSX use :
**		-lmlx -framework OpenGL -framework AppKit
**	To link MiniLibX on BSD/Linus and X-Window use : 
**		-lmlx -lXext -lX11 (you may need to use -L)
	***************************
**	Calling mlx_init() to initiate a connection 
**		with the graphical system
**	Calling mlx_new_win() to open a window
**	Calling mlx_new_image() to create a new image
**	Calling mlx_get_data_addr() to get the start 
**		address of the image data,
**		and setting values bpp, ln, and endian (en)
**	Calling mlx_put_image_to_window() to push the image to the window
**	Calling mlx_hook for generic hook system (all events)
**	Calling mlx_loop() to initiate the window rendering, 
**		and handling keyboard or mouse events
	***************************
**	Minilibx doesn't support event masks
**	2 is the event of keypress
**	17 is the event of DestroyNotify
**  endian : 0 = sever X is little endian, 1 = big endian
**  endian : useless on macos, client and graphical 
**		framework have the same endian
*/
int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (argc != 2)
		return (perror("<./bin/fdf> <map_name>\n"), -1);
	init(data, argv);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, data->file_name);
	data->img = mlx_new_image(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ln, &data->en);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, mouse, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
