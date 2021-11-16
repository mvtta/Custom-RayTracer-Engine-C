/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:08:05 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/12 19:54:14 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none
** PARAM: #1. The address of a pointer to the first link of a list.
** #2. The address of a pointer to the element to be added to the list.
** DESC: Adds the element ’new’ at the end of the list. Also called push.
** (｡◕‿◕｡)
*/

#include "libft.h"

void			ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list			*node;

	node = *lst;
	if (!node)
		*lst = new;
	else
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
}
