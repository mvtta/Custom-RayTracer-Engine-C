/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:53:41 by mavaldeta         #+#    #+#             */
/*   Updated: 2021/02/12 19:35:04 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none
** SYN: Creates a new list element
** DESC:Allocates (with malloc(3)) and returns a new element.
** The variable ’content’ is initialized with the
** value of the parameter ’content’.
** The variable ’next’ is initialized to NULL.
** (｡◕‿◕｡)
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}
