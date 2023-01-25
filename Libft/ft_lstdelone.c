/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 05:24:39 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 05:19:49 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Takes as a parameter a node and frees the memory of
the node's content using the function del given
as a parameter and free the node. The memory of
next must not be freed. */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
