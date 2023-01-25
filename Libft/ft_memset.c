/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:14:52 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 08:48:58 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//fill a byte string with a byte value
// Seg fault when NULL

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	size_t			tmp;
	unsigned char	cast_c;

	cast_c = (unsigned char)(c);
	tmp = len;
	i = 0;
	while (len > 0)
	{
		*(unsigned char *)(b) = cast_c;
		b++;
		len--;
	}
	return (((unsigned char *)b) - tmp);
}
