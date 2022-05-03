/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overview.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:39:02 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:50:21 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_draw_map_rectangles(t_engine *engine, int i_row, int i_column);

void	ft_draw_map(t_engine *engine)
{
	int		i_row;
	int		i_column;

	i_row = 0;
	i_column = 0;
	while (i_row < engine->screen->rows)
	{
		i_column = 0;
		while (i_column < engine->screen->columns)
		{
			ft_draw_map_rectangles(engine, i_row, i_column);
			i_column++;
		}
		i_row++;
	}
}

static void	ft_draw_map_rectangles(t_engine *engine, int i_r, int i_c)
{
	t_line	line;
	t_map	*map;

	map = engine->screen;
	line.start.x = i_c * (map->map_tile_size) + map->offset.x;
	line.start.y = i_r * (map->map_tile_size) + map->offset.y;
	line.end.x = (1 + i_c) * (map->map_tile_size) - 1 + map->offset.x;
	line.end.y = (1 + i_r) * (map->map_tile_size) - 1 + map->offset.y;
	if (map->map[i_r][i_c] == '1')
		ft_set_line_color(&line, 0x00aaaaaa);
	else if (ft_is_empty_space(map->map[i_r][i_c]) == RETURN_TRUE)
		ft_set_line_color(&line, 0x00555555);
	else
		ft_set_line_color(&line, 0x00000000);
	ft_draw_rectangle_full(engine, line);
	line.start.color = 0x00FFFFFF;
	line.end.color = 0x00FFFFFF;
	ft_draw_rectangle(engine, line);
}
