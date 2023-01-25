/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 05:59:28 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/25 01:33:22 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define width 1980
#define height 1080

typedef	struct s_data
{
	void	*addr;
	void	*img;
}	t_data;

typedef	struct s_line
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	
}	t_line;

void	draw_line(void *mlx_ptr, void *win_ptr);


#endif // fdf.h
