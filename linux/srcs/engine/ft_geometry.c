/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:46:09 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:46:14 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_draw_rectangle(t_engine *engine, t_line rectangle)
{
	t_line	line;

	line.start.color = rectangle.start.color;
	line.end.color = rectangle.end.color;
	line.start.x = rectangle.start.x;
	line.start.y = rectangle.start.y;
	line.end.x = rectangle.end.x;
	line.end.y = rectangle.start.y;
	ft_draw_line(engine, line);
	line.start.x = rectangle.end.x;
	line.start.y = rectangle.start.y;
	line.end.x = rectangle.end.x;
	line.end.y = rectangle.end.y;
	ft_draw_line(engine, line);
	line.start.x = rectangle.start.x;
	line.start.y = rectangle.end.y;
	line.end.x = rectangle.end.x;
	line.end.y = rectangle.end.y;
	ft_draw_line(engine, line);
	line.start.x = rectangle.start.x;
	line.start.y = rectangle.start.y;
	line.end.x = rectangle.start.x;
	line.end.y = rectangle.end.y;
	ft_draw_line(engine, line);
}

void	ft_draw_rectangle_full(t_engine *engine, t_line rectangle)
{
	t_line	line;

	line.start.color = rectangle.start.color;
	line.end.color = rectangle.end.color;
	line.start.x = rectangle.start.x;
	line.end.x = rectangle.end.x;
	while (rectangle.start.y <= rectangle.end.y)
	{
		line.start.y = rectangle.start.y;
		line.end.y = rectangle.start.y;
		ft_draw_line(engine, line);
		rectangle.start.y++;
	}
}
