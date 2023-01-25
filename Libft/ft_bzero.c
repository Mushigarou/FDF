/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:41:20 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 04:44:29 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// write zeroes to a byte string
// bzero does nothing when n = 0. 
// it segfault when NULL represents its first parameter
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)s++ = 0;
}
