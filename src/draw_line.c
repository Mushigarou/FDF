/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:57:09 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/06 05:10:30 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

// ** Draws a line between point A and B
void	draw_line(double x, double y, double x1, double y1, t_data *data)
{
	double	x_step;
	double	y_step;
	int	max;
	int	i;

	x_step = x1 - x;
	y_step = y1 - y;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	i = -1;
	while (++i <= max)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, 255);
		x += x_step;
		y += y_step;
	}
	return ;
}
