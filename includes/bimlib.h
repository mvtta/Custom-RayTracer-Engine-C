/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bimlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 10:26:06 by user              #+#    #+#             */
/*   Updated: 2022/03/09 21:14:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Basic Input Management library for C projects
** Version Test (5/3/2022)
** (｡◕‿◕｡)
*/

# ifndef BIMLIB_H
# define BIMLIB_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"

int filetype_is_valid(char *arg, char *file_type);

#endif
