/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:41:40 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:34:42 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_check_player_area(t_engine *engine);
static void	ft_check_map_moveable(t_map *screen, t_line *line, int *free_x);
static void	ft_calculate_xy(t_line *line, t_player player, char calc);

void	ft_draw_player(t_engine *engine)
{
	t_line	player_pos;
	t_map	*map;

	map = engine->screen;
	ft_set_line_color(&player_pos, 0x00FF00FF);
	player_pos.start.x = (int)(map->player.x * map->map_tile_size
			/ map->tile_size) + map->offset.x - 1;
	player_pos.start.y = (int)(map->player.y * map->map_tile_size
			/ map->tile_size) + map->offset.y - 1;
	player_pos.end.x = player_pos.start.x + 2;
	player_pos.end.y = player_pos.start.y + 2;
	ft_draw_rectangle_full(engine, player_pos);
	ft_check_player_area(engine);
}

static void	ft_check_player_area(t_engine *engine)
{
	double		sx;
	double		sy;
	t_player	*player;
	t_line		line;

	player = &engine->screen->player;
	line.start.x = player->x;
	line.start.y = player->y;
	ft_set_line_color(&line, 0x00FFFF00);
	ft_calculate_xy(&line, *player, '+');
	ft_check_map_moveable(engine->screen, &line, &player->free_w);
	ft_calculate_xy(&line, *player, '-');
	ft_check_map_moveable(engine->screen, &line, &player->free_s);
	sx = cos(ft_deg_to_rad(player->angle - 90)) * MOV_MULTI;
	sy = sin(ft_deg_to_rad(player->angle - 90)) * MOV_MULTI;
	line.end.x = player->x + sx * ROT_MULTI;
	line.end.y = player->y + sy * ROT_MULTI;
	ft_check_map_moveable(engine->screen, &line, &player->free_a);
	line.end.x = player->x - sx * ROT_MULTI;
	line.end.y = player->y - sy * ROT_MULTI;
	ft_check_map_moveable(engine->screen, &line, &player->free_d);
}

static void	ft_calculate_xy(t_line *line, t_player player, char calc)
{
	if (calc == '+')
	{
		line->end.x = player.x + player.dx * ROT_MULTI;
		line->end.y = player.y + player.dy * ROT_MULTI;
	}
	else if (calc == '-')
	{
		line->end.x = player.x - player.dx * ROT_MULTI;
		line->end.y = player.y - player.dy * ROT_MULTI;
	}
}

static void	ft_check_map_moveable(t_map *screen, t_line *line, int *free_x)
{
	int	mx;
	int	my;

	mx = (int) line->end.x / (screen->tile_size);
	my = (int) line->end.y / (screen->tile_size);
	if (screen->map[my][mx] != '1')
		*free_x = 0;
	else
		*free_x = 1;
}
