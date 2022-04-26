/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:41:40 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/26 09:49:43 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_draw_player(t_engine *engine)
{
	t_line	line;

	line.start.color = 0x00FFFF00;
	line.end.color = 0x00FFFF00;
	line.start.x = engine->screen->player.x - 1;
	line.start.y = engine->screen->player.y - 1;
	line.end.x = engine->screen->player.x + 1;
	line.end.y = engine->screen->player.y + 1;
	ft_draw_rectangle_full(engine, line);
	line.start.x = engine->screen->player.x;
	line.start.y = engine->screen->player.y;
	line.end.x = engine->screen->player.x + engine->screen->player.dx * 5;
	line.end.y = engine->screen->player.y + engine->screen->player.dy * 5;
	ft_draw_line(engine, line);
}
