/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:42 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/12 20:26:08 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function that returns a line read from a file descriptor */
/* Read line: correct behavior
 * NULL: there is nothing else to read, or an error
 * occurred
*/

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100000
#endif // BUFFER_SIZE

/*removing the line that was returned for the static var*/

char	*free_line(char	*p)
{
	size_t	i;
	size_t	len;
	char	*rest;
	char	*tmp;

	if (!p)
		return (NULL);
	tmp = ft_strchr_gnl(p, '\n');
	if (!tmp)
		return (NULL);
	len = ft_strlen_gnl(++tmp);
	if (len == 0)
		return (free(p), p = NULL, NULL);
	rest = (char *)malloc(len + 1);
	if (!rest)
		return (free(p), p = NULL, NULL);
	i = 0;
	while (len-- > 0)
	{
		rest[i] = tmp[i];
		i++;
	}
	rest[i] = 0;
	free(p);
	return (p = NULL, rest);
}

/*retriving the line to be returned*/

char	*_line_(char *p)
{
	size_t	i;
	long	len;
	char	*line;

	line = ft_strchr_gnl(p, '\n');
	if (!line)
		return (p);
	len = line - p;
	line = (char *)malloc(len + 2);
	if (!line)
		return (free(p), p = NULL, NULL);
	i = 0;
	while (p[i] && len-- > 0)
	{
		line[i] = p[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = 0;
	return (line);
}

/*Read from fd untill encountring '\n' or EOF*/

char	*read_fd(char *p, int fd)
{
	char	*tmp;
	char	*temp;
	int		bytes;

	bytes = 1;
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (bytes && !ft_strchr_gnl(p, '\n'))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
			return (free(tmp), free(p), p = NULL, tmp = NULL, NULL);
		tmp[bytes] = 0;
		temp = p;
		p = ft_strjoin_gnl(p, tmp);
		free(temp);
		temp = NULL;
	}
	free(tmp);
	tmp = NULL;
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	p = read_fd(p, fd);
	if (!p)
		return (NULL);
	line = _line_(p);
	if (!line)
		return (NULL);
	p = free_line(p);
	return (line);
}
