/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:38:24 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/28 03:44:20 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_all(int **p, t_data **data)
{
	int	i;

	i = 0;
	if (!p)
		return ;
	if (p && *p)
	{

		while (p[i])
		{
			free(p[i]);
			i++;
		}
		free(p);
		*p = NULL;
	}
	if (data && *data)
	{
		free(*data);
		*data = NULL;
	}
	return ;
}

/* Incrementing (wc) when (s - 1) is a seperator, and (*s) isn't a seperator */

int	cnt_width(char *s, char c)
{
	unsigned int	w_count;
	int				state;

	state = OUT;
	w_count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			state = OUT;
		else if (*s != c && !state)
		{
			state = IN;
			w_count++;
		}
		s++;
	}
	return (w_count);
}

int	iscomma(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			return(1);
		i++;
	}
	return(0);
}

// void	get_color(char *line, t_data data)
// {
// 	while (*line != '\0')
// 	{
// 		if (*line == ',')
// 		{
// 			while(*line != ' ')
// 			{
// 				data->color
// 			}
// 		}
// 		line++;
// 	}
// }

// int main()
// {
// 	int **data;

// 	data = (int **)malloc(sizeof(data));
	
// }