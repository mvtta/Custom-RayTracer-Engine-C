/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:19:38 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/12 19:52:41 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none
** PARAM: 1 The adress of a pointer to an element; 2 The adress of the function
** used to iterate on the list.
** DESC: Iterates the list ’lst’ and applies the function ’f’ to the content of
** each element.
** (｡◕‿◕｡)
*/

#include "libft.h"

void			ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
