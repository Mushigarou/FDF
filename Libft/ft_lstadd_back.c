/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 04:06:20 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 05:03:17 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Adds the node new at the end of the list.
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
		return (*lst = new, (void)0);
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}
