/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:41:44 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 04:47:51 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define DELETE 127
//If the character is in the range of 0 TO 127 the test is true, else false

int	ft_isascii(int c)
{
	return (c >= '\0' && c <= DELETE);
}
