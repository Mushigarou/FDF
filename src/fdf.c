/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:57:09 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/25 02:30:23 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

void	draw_line(void *mlx_ptr, void *win_ptr)
{
	struct	s_line	pt;
	int		p;
	float		midpt;
	float		old_x;
	float		old_y;
	// int			map_length = 600;

	pt.x1 = 370;
	pt.y1 = 390;
	pt.x2 = 1110;
	pt.y2 = 780;

	printf("x1= %f\n", pt.x1);
	printf("y1= %f\n", pt.y1);
	printf("x2= %f\n", pt.x2);
	printf("y2= %f\n", pt.y2);
	midpt = (pt.y2 - pt.y1) / (pt.x2 - pt.x1);
	printf("midpt = %f\n", midpt);
	if (midpt > 1)
	{
		p = 2 * (pt.x2 - pt.x1) - (pt.y2 - pt.y1);
		while (pt.x1 != pt.x2 || pt.y1 != pt.y2)
		{
			old_x = pt.x1;
			mlx_pixel_put(mlx_ptr, win_ptr, pt.x1, pt.y2, 0x0000FF00);
			if (p >= 0)
			{
				pt.x1++;
				pt.y1++;
			}
			else
				pt.y1++;
			p = p + (2 * (pt.x2 - pt.x1)) - ((2 * (pt.y2 - pt.y1) * (pt.x1 - old_x)));
		}
	}
	else if (midpt < 1)
	{
		p = 2 * (pt.y2 - pt.y1) - (pt.x2 - pt.x1);
		while (pt.x1 != pt.x2 || pt.y1 != pt.y2)
		{
			// printf("hey");
			old_y = pt.y1;
			mlx_pixel_put(mlx_ptr, win_ptr, pt.x1, pt.y1, 0x0000FF00);
			if (p >= 0)
			{
				pt.x1++;
				pt.y1++;
			}  
			else
				pt.x1++;
			p = (2 * (pt.y2 - pt.y1) - (pt.x2 - pt.x1)) - (2 * (pt.x2 - pt.x1) * (pt.y1 - old_y));
		}
	}
}
