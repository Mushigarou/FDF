/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:38:24 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/30 02:23:02 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



/* Incrementing (wc) when (s - 1) is a seperator, and (*s) isn't a seperator */

int	cnt_width(char *s, char c)
{
	unsigned int	w_count;
	int				state;

	state = OUT;
	w_count = 0;
	if (!s)
		return -1;
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

void	free_split(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

int	map_is_empty(char	*s)
{
	char	**line;

	line = ft_split(s, ' ');
	if (!line)
		return (perror("Given map is empty"), 1);
	return (free_split(line), 0);
}

// int	atoh(char *s)
// {
// 	int	i;
	
// 	i = 0;
// 	if (!s)
// 		return (2);
// 	while (s[i] != '\0')
// 	{
		
// 	}
// }

// void	init_struct(t_data *data, char *p)
// {
	
// }
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
