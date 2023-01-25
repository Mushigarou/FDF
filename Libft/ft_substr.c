/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 03:19:34 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 09:45:53 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counting the len of the new str

static	size_t	ft_count_lenstr(const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && len > 0)
	{
		i++;
		len--;
	}
	return (i);
}

/*Returns a substr from the given string, and allocates with malloc(3) 
based on : where to start? and where to end?*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!len || start > ft_strlen(s))
		return (ft_strdup(""));
	i = ft_count_lenstr(&s[start], len);
	ptr = (char *)malloc(i + NULL_CHAR);
	if (!ptr)
		return (ptr);
	s += start;
	i = 0;
	while (len-- > 0 && *s != '\0')
	{
		*ptr++ = *s++;
		i++;
	}
	*ptr = '\0';
	return (ptr - i);
}
