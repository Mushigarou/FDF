/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 05:03:02 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 05:05:30 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function f on the content of each node.

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst != NULL)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
	return ;
}
