/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:01:14 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 09:31:10 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Returns len of the string given

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}
