/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:46:33 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 18:07:02 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_get_color(t_line *line)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (line->dx > line->dy)
		percentage = ft_get_percentage(line->start.x, line->end.x, line->pos.x);
	else
		percentage = ft_get_percentage(line->start.y, line->end.y, line->pos.y);
	red = ft_get_rgb((line->start.color >> 16) & 0xff,
			(line->end.color >> 16) & 0xff, percentage);
	green = ft_get_rgb((line->start.color >> 8) & 0xff,
			(line->end.color >> 8) & 0xff, percentage);
	blue = ft_get_rgb((line->start.color) & 0xff,
			(line->end.color) & 0xff, percentage);
	return ((red << 16) | (green << 8) | blue);
}

double	ft_get_percentage(int start, int end, int pos)
{
	double	place;
	double	distance;

	place = (double) pos - start;
	distance = (double) end - start;
	if (distance == 0)
		return (1.0);
	else
		return (place / distance);
}

int	ft_get_rgb(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	ft_get_rgb_color(char *s)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	while (*s == ' ')
		s++;
	rgb = ft_split(s, ',');
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (RETURN_ERROR);
	red = ft_check_number_rgb(rgb[0]);
	green = ft_check_number_rgb(rgb[1]);
	blue = ft_check_number_rgb(rgb[2]);
	ft_free_char_array(rgb);
	if (red == RETURN_ERROR || green == RETURN_ERROR || blue == RETURN_ERROR)
		return (RETURN_ERROR);
	return ((red << 16) | (green << 8) | blue);
}
