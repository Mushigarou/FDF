/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:57:09 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/07 00:14:29 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
int drawing_unit(int w_w, int w_h, int m_w, int m_h);

// ** Draws all the tiles of the map
void	draw_tile(t_data *data)
{
	int	x;
	int	y;
	int s = drawing_unit(SCREEN_WIDTH, SCREEN_HEIGHT, data->width, data->height);
	printf("scale = %d\n", s);

	y = 0; // Later, can give x,y st.point to start draw the map centered
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			draw_line(x, y, x+1, y, data);
			draw_line(x, y, x, y+1, data);
			x++;
		}
		y++;
	}
}

// ** Draws a line between point A and B
void draw_line(double x, double y, double x1, double y1, t_data *data)
{ 
	double	x_step;
	double	y_step;
	int	max;
	int	scale;

scale = drawing_unit(SCREEN_WIDTH, SCREEN_HEIGHT, data->width, data->height);
printf("%d", scale);

/***** zoom ******/
	x *= scale;
	y *= scale;
	x1 *= scale;
	y1 *= scale;
	
	x_step = x1 - x;
	y_step = y1 - y;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;

/***** translates x and y *****/
	x += SCREEN_WIDTH / 4;
	y += SCREEN_HEIGHT / 5;
	x1 += SCREEN_WIDTH / 4;
	y1 += SCREEN_HEIGHT / 5;

	while ((int)x != (int)x1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, 0x00FFFFFF);
		x += x_step;
		y += y_step;
	}
	return ;
}

// ** Initiates drawing unit (how much distance would be between x and x1)
int drawing_unit(int s_w, int s_h, int m_w, int m_h)
{
	double screen_diagonal;
	double map_diagonal;
	double draw_unit;

	map_diagonal = m_w * m_w + m_h * m_h;
	map_diagonal = sqrt(map_diagonal);
	screen_diagonal = s_w * s_w + s_h * s_h;
	screen_diagonal = sqrt(screen_diagonal);
	draw_unit = (screen_diagonal / 2) / map_diagonal;
	return ((int)draw_unit);
}
