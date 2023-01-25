/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:45 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/25 07:35:28 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***
 * if read() reads NULL it doesn't return what is left
 * 
 * 
 * 
*/

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s));
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr1;
	size_t	s1_len;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	ptr1 = (char *)malloc(s1_len + NULL_CHAR);
	if (ptr1 == (void *)0)
		return (ptr1);
	while (*s1 != '\0')
		*ptr1++ = *s1++;
	*ptr1 = '\0';
	return (ptr1 - s1_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	new_str = ft_strcat(s1, s2, new_str, len);
	return (new_str);
}

char	*ft_strcat(char *s1, char *s2, char *str, size_t len)
{
	int		i;
	int		j;

	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[len] = '\0';
	return (str);
}
