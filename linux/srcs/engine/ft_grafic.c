/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grafic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:46:02 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/28 18:58:33 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_render_frame(t_engine *engine)
{
	ft_draw_map(engine);
	ft_draw_player(engine);
	ft_draw_3d_ray(engine);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->img->img, 0, 0);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->no_tex.img, 0, 0);
	if (engine->img == &engine->img0)
		engine->img = &engine->img1;
	else
		engine->img = &engine->img0;
	ft_clear_image(engine);
	ft_display_info(engine);
	return (0);
}

void	ft_clear_image(t_engine *engine)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put_pixel(engine->img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	ft_draw_map(t_engine *engine)
{
	t_line	line;
	int		i_row;
	int		i_column;

	i_row = 0;
	i_column = 0;
	while (i_row < engine->screen->rows)
	{
		i_column = 0;
		while (i_column < engine->screen->columns)
		{
			line.start.x = i_column * (engine->screen->tile_size);
			line.start.y = i_row * (engine->screen->tile_size);
			line.end.x = (1 + i_column) * (engine->screen->tile_size) - 1;
			line.end.y = (1 + i_row) * (engine->screen->tile_size) - 1;
			if (engine->screen->map[i_row][i_column] == '1')
			{
				line.start.color = 0x00aaaaaa;
				line.end.color = 0x00aaaaaa;
			}
			else if (engine->screen->map[i_row][i_column] == '0' || engine->screen->map[i_row][i_column] == 'N'
				|| engine->screen->map[i_row][i_column] == 'S' || engine->screen->map[i_row][i_column] == 'W'
				|| engine->screen->map[i_row][i_column] == 'E')
			{
				line.start.color = 0x00555555;
				line.end.color = 0x00555555;
			}
			else
			{
				line.start.color = 0x00000000;
				line.end.color = 0x00000000;
			}
			ft_draw_rectangle_full(engine, line);
			line.start.color = 0x00FFFFFF;
			line.end.color = 0x00FFFFFF;
			ft_draw_rectangle(engine, line);
			i_column++;
		}
		i_row++;
	}
}
