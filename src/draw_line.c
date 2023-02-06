/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:57:09 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/06 01:03:15 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

// int	drawing_unit(int w_w, int w_h, int m_w, int m_h)
// {
// 	double	win_diagonal;
// 	double	map_diagonal;
// 	double	draw_unit;

// 	map_diagonal = m_w * m_w + m_h * m_h;
// 	map_diagonal = sqrt(map_diagonal);
// 	win_diagonal = w_w * w_w + w_h * w_h
// 	win_diagonal = sqrt(win_diagonal);
// 	draw_unit = (win_diagonal / 2) / map_diagonal;
// 	return ((int)draw_unit);
// }

void	start_point(int	*x, int	*y)
{
	
	return ;
}

void	draw_line(double x, double y, double x1, double y1, t_data *data)
{
	double	x_step;
	double	y_step;
	int	max;
	int	st;

	x_step = x1 - x;
	y_step = y1 - y;

	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	st  = -1;
	while (++st <= max)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, 255);
		x += x_step;
		y += y_step;
	}
	return ;
}
