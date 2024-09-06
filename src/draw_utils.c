/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:15:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/14 05:09:13 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
**	data->addr is start address if the image data
**	data->ln : line length is the number of bytes in a
**		single row of pixels in the image
**		ln = WINDOW_WIDTH * (Bits per pixels / 8)
**	`y * data->line_length` calculates the offset in bytes
**		of the row of the image containing the pixel.
**	`x * (data->bits_per_pixel / 8)` calculates the offset 
**		in bytes of the pixel within the row.
**	The total of both offsets + start address of the image
**		gives the total offset in bytes of the pixel from data->addr, 
**		which is the memory address of the pixel;
**	Color is casted to `unsigned int *` to indicates to the compiler
**		to treat `dst` memory address as an `unsigned int`
*/
// **	Calculates the memory addres
void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ln + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

// ** Initiates the point from where to start drawing
void	center_map(t_pt *pt, float *x1, float *y1, t_data *data)
{
	pt->x += (SCREEN_WIDTH / 2) + data->shift_x;
	pt->y += (SCREEN_HEIGHT / 2) + data->shift_y;
	*x1 += (SCREEN_WIDTH / 2) + data->shift_x;
	*y1 += (SCREEN_HEIGHT / 2) + data->shift_y;
}

/*
**	Checks if points A and B are within the 
**		range of the window width and height
*/
int	valid(t_pt pt, float x1, float y1, t_data *data)
{
	if ((x1 < SCREEN_WIDTH && x1 > 0) && (y1 < SCREEN_HEIGHT && y1 > 0)
		&& (pt.x < SCREEN_WIDTH && pt.x > 0) && (pt.y < SCREEN_HEIGHT && pt.y > 0))
		return (1);
	return (0);
}
