/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overview.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:39:02 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/29 14:04:29 by rkaufman         ###   ########.fr       */
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

static void	ft_draw_map_rectangles(t_engine *engine, int i_row, int i_column)
{
	t_line	line;

	line.start.x = i_column * (engine->screen->tile_size);
	line.start.y = i_row * (engine->screen->tile_size);
	line.end.x = (1 + i_column) * (engine->screen->tile_size) - 1;
	line.end.y = (1 + i_row) * (engine->screen->tile_size) - 1;
	if (engine->screen->map[i_row][i_column] == '1')
		ft_set_line_color(&line, 0x00aaaaaa);
	else if (ft_is_empty_space(engine->screen->map[i_row][i_column]) == RETURN_TRUE)
		ft_set_line_color(&line, 0x00555555);
	else
		ft_set_line_color(&line, 0x00000000);
	ft_draw_rectangle_full(engine, line);
	line.start.color = 0x00FFFFFF;
	line.end.color = 0x00FFFFFF;
	ft_draw_rectangle(engine, line);
}
