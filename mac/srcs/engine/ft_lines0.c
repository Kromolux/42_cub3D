/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:45:56 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/01 21:15:33 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_draw_line(t_engine *engine, t_line line)
{
	if (!ft_at_least_one_point_on_screen(&line))
		return ;
	ft_line_preparations(&line);
	line.pos.x = line.start.x;
	line.pos.y = line.start.y;
	line.pos.color = line.start.color;
	line.main_x = 1;
	if (ft_abs(line.dy) > ft_abs(line.dx))
		line.main_x = 0;
	if (ft_abs(line.dx) == ft_abs(line.dy) || line.dx == 0 || line.dy == 0)
		ft_draw_line_edge_case(engine, line);
	else
		ft_draw_line_algorythm(engine, line);
}

int	ft_at_least_one_point_on_screen(t_line *line)
{
	if ((line->start.x >= 0 && line->start.x < WIDTH)
		|| (line->start.y >= 0 && line->start.y < HEIGHT)
		|| (line->end.x >= 0 && line->end.x < WIDTH)
		|| (line->end.y >= 0 && line->end.y < HEIGHT))
		return (1);
	return (0);
}

void	ft_line_preparations(t_line *line)
{
	int	*primary;
	int	*secondary;

	line->dx = line->end.x - line->start.x;
	line->x_next = 0;
	if (line->dx > 0)
		line->x_next = 1;
	else if (line->dx < 0)
		line->x_next = -1;
	line->dy = line->end.y - line->start.y;
	line->y_next = 0;
	if (line->dy > 0)
		line->y_next = 1;
	else if (line->dy < 0)
		line->y_next = -1;
	primary = &line->dx;
	secondary = &line->dy;
	if (ft_abs(line->dy) > ft_abs(line->dx))
	{
		primary = &line->dy;
		secondary = &line->dx;
	}
	line->p_start = (2 * ft_abs(*secondary)) - ft_abs(*primary);
	line->p_less = (2 * ft_abs(*secondary));
	line->p_greater = (2 * ft_abs(*secondary)) - (2 * ft_abs(*primary));
}

void	ft_draw_line_edge_case(t_engine *engine, t_line line)
{
	ft_put_pixel(engine->img, line.start.x, line.start.y, line.start.color);
	line.pos.color = line.start.color;
	while (line.pos.x != line.end.x || line.pos.y != line.end.y)
	{
		line.pos.x += line.x_next;
		line.pos.y += line.y_next;
		if (line.start.color != line.end.color)
			line.pos.color = ft_get_color(&line);
		ft_put_pixel(engine->img, line.pos.x, line.pos.y, line.pos.color);
	}
}
