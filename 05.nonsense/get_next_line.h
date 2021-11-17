/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:57:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/27 18:23:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (｡◕‿◕｡)
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define LINE 1
# define EOF_R 0
# define ERROR -1

/*
** variable struct
*/
typedef	struct		s_var
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	int		r;
	size_t	len;
	int		i;
}					t_var;
/*
** get_next_line_utils.c
*/
char				*ft_strchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
/*
** get_next_line.c
*/
char				*ft_no_leaks(char *str, char *temp);
int					get_next_line(int fd, char **line);
int					ft_delete (char **del);

#endif
