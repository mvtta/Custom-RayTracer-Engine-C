/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:58:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/24 17:13:53 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** (｡◕‿◕｡)main
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char)c != *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

char	*ft_no_leaks(char *str, char *temp)
{
	char *ptr1;

	ptr1 = temp;
	free(str);
	str = ft_strdup(temp);
	free(ptr1);
	return (str);
}

int		ft_delete(char **del)
{
	if (del == NULL)
		return (0);
	free(*del);
	*del = NULL;
	return (0);
}

int		ft_else(char **archive, int fd, int index)
{
	archive[fd] = ft_no_leaks(archive[fd], ft_strdup(archive[fd] + index));
	return (ft_delete(&archive[fd]));
}

int		get_next_line(int fd, char **line)
{
	static char *arch[4094];
	t_var		v;

	v.i = 0;
	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	(!arch[fd]) ? (arch[fd] = ft_strnew(0)) : arch[fd];
	while ((v.r = read(fd, v.buf, BUFFER_SIZE)))
	{
		v.buf[v.r] = '\0';
		arch[fd] = ft_no_leaks(arch[fd], ft_strjoin(arch[fd], v.buf));
		if (ft_strchr(arch[fd], '\n'))
			break ;
	}
	while (arch[fd][v.i] != '\n' && arch[fd][v.i] != '\0')
		v.i++;
	*line = ft_substr(arch[fd], 0, v.i);
	if (!ft_strlen(arch[fd]) && !v.i && !v.r)
		return (ft_delete(&arch[fd]));
	if (arch[fd][v.i] == '\n')
		arch[fd] = ft_no_leaks(arch[fd], ft_strdup(arch[fd] + v.i + 1));
	else
		return (ft_else(arch, fd, v.i));
	return (1);
}
