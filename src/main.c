/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:37:39 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/12 20:18:16 by mfouadi          ###   ########.fr       */
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
int	mouse(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	deal_key(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if (key == 126)
		data->shift_y -= 20;
	if (key == 123)
		data->shift_x -= 20;
	if (key == 125)
		data->shift_y += 20;
	if (key == 124)
		data->shift_x += 20;
	if (key == 35)
		data->bool = 1;
	if (key == 34)
		data->bool = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_tile(data);
	return (0);
}

void	lk(void)
{
	system("leaks fdf");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (argc != 2)
		return (-1);
	init(data, argv);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, data->file_name);
	draw_tile(data);
	printf("%d\n", data->width);
	mlx_hook(data->win_ptr, 2, 1L << 0, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, mouse, data);
	lk();
	mlx_loop(data->mlx_ptr);
	return (0);
}
