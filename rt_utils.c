/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:34:32 by user              #+#    #+#             */
/*   Updated: 2021/05/07 17:19:24 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

/* int			ft_atoi(const char *str)
{
	int res = 0;
	int i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
	str[i] == '\f' || str[i] == '\r')
		i++;
	int mynb;
	
	while(str[i] != '\0')
	{
			mynb = str[i] * 10 - 48;
			i++;	
	}
	return(mynb);
}
 */

static int		ft_strncmp(char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}


int ft_atoi(const char *str)
{
	int res;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
		   *str == '\f' || *str == '\r')
		str++;
	while (*str != '\0')
	{
		res = res * 10 + *str - '0';
		if (*str == '-')
			return (-ft_atoi(++str));
		if (*str == '+')
			return (ft_atoi(++str));
		str++;
	}
	return (res);
}

float ft_atof(char *str)
{
	float inter;
	float deci;
	inter = 0;
	deci = 0;
	while (*str != '.')
	{
		inter = inter * 10 + *str - '0';
		if (*str == '-')
			return (-ft_atoi(++str));
		str++;
	}
	str += 1;
	while (*str != '\0')
	{
		deci = deci * 10 + *str - '0';
		if (*str == '-')
			return (-ft_atoi(++str));
		str++;
	}
	deci *= 0.1;
	if(inter + deci < FLT_MIN)
		return(0);
	if(inter + deci > FLT_MAX)
		return(0);
	return(inter + deci);
}

void			ft_lstadd_back(t_ele **lst, t_ele *new)
{
	t_ele			*node;

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

t_ele	*ft_lstnew(void *content)
{
	t_ele *new;

	if (!(new = malloc(sizeof(t_ele))))
		return (0);
	new->data = content;
	new->next = NULL;
	return (new);
}