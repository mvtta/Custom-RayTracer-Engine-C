#include <stdio.h>
#include "rtlib.h"
#include "get_next_line.h"

int	match(char *str, int c)
{
	int i = 0;
	while(ID[i]++ != '\0')
	{
		if(str[0] == ID[i])
			return(i);
		else
			return(printf("%s", "error"));
	}
	return(0);
}


int parse(char *file)
{
	int i;
	char **splitted; 
	t_ele *head;
	t_ele *tmp;

	splitted = ft_split(file, '\n');
	while (splitted[i])
	{
		if (!(match(splitted[0], ID[i])))
			return(printf("%s", "error"));
		tmp = malloc(sizeof(t_ele));
		tmp->data = ft_lstnew(splitted[i]);
		tmp->type = 
		head = ft_lstadd_back(&head, tmp);
	}
}

t_light *new_light(t_data_arr arr)
{
	t_light *light;

	light = malloc(sizeof(t_light));
	light->x = ft_atoi(arr.lightvec[0]);
	light->y = ft_atoi(arr.lightvec[1]);
	light->z = ft_atoi(arr.lightvec[2]);
	light->ratio = ft_atof(arr.light[2]); 
	light->r = ft_atoi(arr.lightcolor[0]);
	light->g = ft_atoi(arr.lightcolor[1]);
	light->b = ft_atoi(arr.lightcolor[2]);
	return (light);
}