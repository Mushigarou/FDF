/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 02:33:45 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 09:37:11 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//If c is '\0', return s + len_src
//else, start from the end, and find c (converted to char) in s

/*Converted to char so, ("test", 't' + 256) pass.*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return (s += i, (char *)s);
	while (i > 0)
	{
		i--;
		if ((char)s[i] == (char)(c))
			return ((char *)(s + i));
	}
	return (NULL);
}
