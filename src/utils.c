/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:38:24 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/31 04:01:38 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define LOW_HEX "0123456789abcdef"
#define UPP_HEX "0123456789ABCDEF"

/* Incrementing (wc) when (s - 1) is a seperator, and (*s) isn't a seperator */
int	cnt_width(char *s, char c)
{
	unsigned int	w_count;
	int				state;
	int	i;

	i = 0;
	state = OUT;
	w_count = 0;
	if (!s)
		return -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			state = OUT;
		else if (ft_isdigit(s[i]) && s[i] != c && !state)
		{
			state = IN;
			w_count++;
		}
		i++;
	}
	return (w_count);
}

void	free_split(char **s)
{
	int	i;

	if (!s && !(*s))
		return ;
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void free_matrix(t_tile **s)
{
	int i;

	if (!s && !(*s))
		return;
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

int is_hexa(char c)
{
	int i;

	i = -1;
	while (++i < 16)
	{
		if (LOW_HEX[i] == c || UPP_HEX[i] == c)
			return (i);
	}
	return (-1);
}

int ft_strtol(char *str) // str + 2, to skip "0x"
{
	int res;
	int indice;

	res = 0;
	if (!str)
		return (0);
	while (*str)
	{
		indice = is_hexa(*str);
		if (indice == -1)
			return (perror("One of the values is not a hexa number"), -1);
		res = (res * 16) + indice;
		str++;
	}
	return (res);
}

