/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:19:06 by user              #+#    #+#             */
/*   Updated: 2022/05/25 12:06:52 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

#define COLOR_UNIVERSE 0

/* declaring black */
const t_color	black = {0, 0, 0, 0};
const t_color	yellow = {0, 0, 255, 0};
/* declaring primaries */
const t_color red = {1, 0, 0, 0};
const t_color green = {0, 1, 0, 0};
const t_color blue = {0, 0, 1, 0};
const int rgb[3] = {1, 2, 3};

/* 
B = LONG \ 65536
G = (LONG - B * 65536) \ 256
R = LONG - B * 65536 - G * 256 
const r = (number & 0xff0000) >> 16;
 const g = (number & 0x00ff00) >> 8;
 const b = (number & 0x0000ff);*/


t_color c_color_components(unsigned int decimal_color)
{
	t_color new;
	new.r = (decimal_color & 0xff0000) >> 16;
	new.g = (decimal_color & 0x00ff00) >> 8;
	new.b = (decimal_color & 0x0000ff);
	new.r *= new.r;
	new.g *= new.g;
	new.b *= new.b;
/*     new.r = (int)sqrt(new.r);
	new.g = (int)sqrt(new.g);
	new.b = (int)sqrt(new.b); */

	return(new);
}

t_color c_mix_2colors(t_color one, t_color two)
{
	t_color mixed;

	mixed.r = c_range(one.r + two.r / 2, 0, 255);
	mixed.g = c_range(one.g + two.g / 2, 0, 255);
	mixed.b = c_range(one.b + two.b / 2, 0, 255);
	return(mixed);
}

t_color c_mix_3colors(t_color one, t_color two, t_color three)
{
	t_color mixed;

	mixed.r = c_range(one.r + two.r + three.r / 3, 0, 255);
	mixed.g = c_range(one.g + two.g + three.g / 3, 0, 255);
	mixed.b = c_range(one.b + two.b + three.b / 3, 0, 255);
	return(mixed);
}

t_color c_intensity(t_color one, float intensity)
{
	t_color mixed;

	mixed.r = c_range(one.r * intensity, 0, 255);
	mixed.g = c_range(one.g * intensity, 0, 255);
	mixed.b = c_range(one.b * intensity, 0, 255);
	return(mixed);
}

t_color c_mix_hue(t_color one, t_color two, t_color hue)
{
	t_color mixed;
	mixed = c_mix_2colors(one, two);
	mixed = c_mix_2colors(hue, mixed);
	return(mixed);
}

t_color c_new_color(int r, int g, int b)
{
	t_color new;
	new.r = r;
	new.g = g;
	new.b = b;
	new.hex = DEC(r, g, b);
	return(new);
}

int c_increase(int max)
{
	if (max > L)
		return (max - L);
	return (0);
}

float c_percentage(int color)
{
	return (color / 255);
}

t_color c_isolate_hue(t_color *check)
{
	float c[3];
	int index = 0;
	int highest = 0;
	int hue[3] = {0};
	t_color hued;

	c[0] = c_percentage(check->r);
	c[1] = c_percentage(check->g);
	c[2] = c_percentage(check->b);

	highest = c[0];
	while (c[index])
	{
		if (highest < c[index])
		{
			hue[index - 1] = 0;
			highest = c[index];
			hue[index] = 1;
		}
		index++;
	}
	hued = c_new_color(hue[0] * check->r, hue[1] * check->g, hue[2] * check->b);
	return (hued);
}

t_color c_mix(t_frame *rt, t_obj *curr, double spec, double diffuse)
{
	t_color mixed;
	t_color source;
	t_color frag;
	t_color ambient;
	t_color light;
	t_color frag_amb;
	t_color frag_diff;
	t_color frag_spec;
	
	//float mat_amb = curr->material->x;

	
	/* fresnell law here */
	float mat_amb = curr->material->x;
	float mat_diff = curr->material->y;
	float mat_spec = curr->material->z;

	ambient = c_intensity(*rt->scene->a->amb_color, rt->scene->a->ambient);
	source = c_intensity(*rt->scene->l->light_color, rt->scene->l->brightness);
	
	light = c_mix_2colors(ambient, source);

 
/* 	float light_metal_universe = 2;
	float light_digi_universe = 10;
	float light_u[2] = {light_metal_universe, light_digi_universe};

	frag_amb = c_intensity(*curr->obj_color, (mat_amb * light_u[COLOR_UNIVERSE]));
	frag_diff = c_intensity(*curr->obj_color, (mat_diff * light_u[COLOR_UNIVERSE]));
	frag_spec = c_intensity(*curr->obj_color, (mat_spec * light_u[COLOR_UNIVERSE]));
	frag = c_mix_3colors(frag_amb, frag_diff, frag_spec); */
/* 	float metal_universe = pow(diffuse + spec, 1/2.2);
	float digi_universe = pow(diffuse * spec, 1/2.2); */
/* 	float metal_universe = ((diffuse + spec));
	float digi_universe = ((diffuse * spec));
	float effect_u[2] = {metal_universe, digi_universe};

	mixed.g = c_range(light.g * (effect_u[COLOR_UNIVERSE]) + (frag.g + effect_u[COLOR_UNIVERSE]), 0, 255);
	mixed.r = c_range(light.r * (effect_u[COLOR_UNIVERSE]) + (frag.r + effect_u[COLOR_UNIVERSE]), 0, 255);
	mixed.b = c_range(light.b * (effect_u[COLOR_UNIVERSE]) + (frag.b + effect_u[COLOR_UNIVERSE]), 0, 255);  */


	/* soft shadows */
	frag_amb = c_intensity(*curr->obj_color, (mat_amb));
	frag_diff = c_intensity(*curr->obj_color,(mat_diff));
	frag_spec = c_intensity(*curr->obj_color, (mat_spec));
	frag = c_mix_3colors(frag_amb, frag_diff, frag_spec);
	mixed.r = c_range(light.r * (spec) + (frag.r + diffuse), 0, 255);
	mixed.g = c_range(light.g * (spec) + (frag.g + diffuse), 0, 255);
	mixed.b = c_range(light.b * (spec) + (frag.b + diffuse), 0, 255);
	return (mixed);
}

t_color c_grade(t_frame *rt, t_obj *curr, double spec, double difuse)
{
	t_color new;
	new = c_mix(rt, curr, spec, difuse);
	new.hex = DEC(new.r, new.g, new.b);
	return (new);
}