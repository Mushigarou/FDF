/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:28:04 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 08:49:34 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Outputs the string 's' to the given file descriptor followed by a newline.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
}
