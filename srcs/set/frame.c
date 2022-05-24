/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:35:32 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/05/24 22:51:10 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

/* 
this silly typdef is norminette fault, 
funtion had mre than 25 lines. 
the other silliness is mine.
*/

typedef struct s_buf
{
	char	*data;
	char	id1;
	char	id2;
	int		fd;

}	t_buf;

void	fill_frame(t_parse *raw, t_frame **rt, char *rtfile)
{
	t_buf	fill;

	fill.fd = open(rtfile, O_RDONLY);
	fill.data = get_next_line(fill.fd);
	while (fill.data != NULL)
	{
		fill.id1 = fill.data[0];
		fill.id2 = fill.data[1];
		if (fill.id1 == 'A')
			raw->ambient = save_raw(fill.data);
		if (fill.id1 == 'C')
			raw->camera = save_raw(fill.data);
		if (fill.id1 == 'L')
			raw->light = save_raw(fill.data);
		if (fill.id1 == 's' && fill.id2 == 'p')
			add_new_obj(*rt, fill.data);
		if (fill.id1 == 'p' && fill.id2 == 'l')
			add_new_obj(*rt, fill.data);
		if (fill.id1 == 'c' && fill.id2 == 'y')
			add_new_obj(*rt, fill.data);
		free(fill.data);
		fill.data = get_next_line(fill.fd);
	}
	close(fill.fd);
}

t_frame	*kill_frame(t_frame *rt)
{
	free(rt);
	rt = NULL;
	return (rt);
}
