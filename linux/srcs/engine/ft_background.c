/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:25:55 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/29 14:36:35 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_draw_background(t_engine *engine)
{
	t_line	line;

	line.start.x = engine->offset.x;
	line.start.y = engine->offset.y;
	line.end.x = 1199;
	line.end.y = (int) engine->offset.y + engine->max_line_h / 2;
	ft_set_line_color(&line, engine->screen->ceiling_color);
	ft_draw_rectangle_full(engine, line);
	line.start.y = line.end.y + 1;
	line.end.x = 1199;
	line.end.y = engine->offset.y + engine->max_line_h;
	ft_set_line_color(&line, engine->screen->floor_color);
	ft_draw_rectangle_full(engine, line);
}