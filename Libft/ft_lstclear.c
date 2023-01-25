/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 06:06:34 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 05:04:14 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Deletes and frees the given node and every
successor of that node, using the function del
and free(3). Finally, the pointer to the list must be set to NULL. */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = tmp2;
	}
	*lst = NULL;
}
