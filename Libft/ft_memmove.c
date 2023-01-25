/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:47:20 by mfouadi           #+#    #+#             */
/*   Updated: 2023/01/21 02:28:35 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copy len bytes string, the two strings may overlap
//The two strings may overlap

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	tmp;

	tmp = len;
	if (dst > src)
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
