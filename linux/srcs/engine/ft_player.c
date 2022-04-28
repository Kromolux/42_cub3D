/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:41:40 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/28 19:06:18 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_draw_player(t_engine *engine)
{
	t_line	line;
	int		mx;
	int		my;
	double	sx;
	double	sy;

	line.start.color = 0x00FFFF00;
	line.end.color = 0x00FFFF00;
	line.start.x = engine->screen->player.x - 1;
	line.start.y = engine->screen->player.y - 1;
	line.end.x = engine->screen->player.x + 1;
	line.end.y = engine->screen->player.y + 1;
	ft_draw_rectangle_full(engine, line);
	line.start.x = engine->screen->player.x;
	line.start.y = engine->screen->player.y;
	line.end.x = engine->screen->player.x + engine->screen->player.dx * 2;
	line.end.y = engine->screen->player.y + engine->screen->player.dy * 2;
	ft_draw_line(engine, line);
	mx = (int) line.end.x / (engine->screen->tile_size);
	my = (int) line.end.y / (engine->screen->tile_size);
	if (engine->screen->map[my][mx] != '1')
		engine->screen->player.free_w = 0;
	else
		engine->screen->player.free_w = 1;


	line.end.x = engine->screen->player.x - engine->screen->player.dx * 2;
	line.end.y = engine->screen->player.y - engine->screen->player.dy * 2;
	ft_draw_line(engine, line);
	mx = (int) line.end.x / (engine->screen->tile_size);
	my = (int) line.end.y / (engine->screen->tile_size);
	if (engine->screen->map[my][mx] != '1')
		engine->screen->player.free_s = 0;
	else
		engine->screen->player.free_s = 1;
	
	sx = cos(ft_deg_to_rad(engine->screen->player.angle - 90)) * 5;
	sy = sin(ft_deg_to_rad(engine->screen->player.angle - 90)) * 5;
	line.end.x = engine->screen->player.x + sx * 2;
	line.end.y = engine->screen->player.y + sy * 2;
	ft_draw_line(engine, line);
	mx = (int) line.end.x / (engine->screen->tile_size);
	my = (int) line.end.y / (engine->screen->tile_size);
	if (engine->screen->map[my][mx] != '1')
		engine->screen->player.free_a = 0;
	else
		engine->screen->player.free_a = 1;

	line.end.x = engine->screen->player.x - sx * 2;
	line.end.y = engine->screen->player.y - sy * 2;
	ft_draw_line(engine, line);
	mx = (int) line.end.x / (engine->screen->tile_size);
	my = (int) line.end.y / (engine->screen->tile_size);
	if (engine->screen->map[my][mx] != '1')
		engine->screen->player.free_d = 0;
	else
		engine->screen->player.free_d = 1;
}
