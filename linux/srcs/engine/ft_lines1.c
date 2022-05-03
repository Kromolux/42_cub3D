/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:45:44 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:46:55 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_init_algo_ptr(t_line *line, t_algo *ptr);

void	ft_draw_line_algorythm(t_engine *engine, t_line line)
{
	t_algo	ptr;

	ft_init_algo_ptr(&line, &ptr);
	ft_put_pixel(engine->img, line.start.x, line.start.y, line.start.color);
	line.pos.color = line.start.color;
	while (*ptr.primary != *ptr.primary_end)
	{
		*ptr.primary += *ptr.primary_next;
		if (line.p_start < 0)
			line.p_start += line.p_less;
		else
		{
			line.p_start += line.p_greater;
			*ptr.secondary += *ptr.secondary_next;
		}
		if (line.start.color != line.end.color)
			line.pos.color = ft_get_color(&line);
		ft_put_pixel(engine->img, line.pos.x, line.pos.y, line.pos.color);
	}
}

static void	ft_init_algo_ptr(t_line *line, t_algo *ptr)
{
	ptr->primary = &line->pos.x;
	ptr->secondary = &line->pos.y;
	ptr->primary_next = &line->x_next;
	ptr->secondary_next = &line->y_next;
	ptr->primary_end = &line->end.x;
	if (ft_abs(line->dy) > ft_abs(line->dx))
	{
		ptr->primary = &line->pos.y;
		ptr->secondary = &line->pos.x;
		ptr->primary_next = &line->y_next;
		ptr->secondary_next = &line->x_next;
		ptr->primary_end = &line->end.y;
	}
}

void	ft_set_line_color(t_line *line, int color)
{
	line->start.color = color;
	line->end.color = color;
}
