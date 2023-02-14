/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:15:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/14 03:16:25 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	pt->y += (SCREEN_HEIGHT / 8) + data->shift_y;
	*x1 += (SCREEN_WIDTH / 2) + data->shift_x;
	*y1 += (SCREEN_HEIGHT / 8) + data->shift_y;
}

int	valid(t_pt pt, float x1, float y1)
{
	if ((x1 < 1500 && x1 > 0) && (y1 < 960 && y1 > 0)
		&& (pt.x < 1500 && pt.x > 0) && (pt.y < 960 && pt.y > 0))
		return (1);
	return (0);
}
