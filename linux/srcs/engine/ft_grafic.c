/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grafic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:46:02 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/27 17:00:01 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

//static void	ft_draw_endlines(t_engine *engine);

int	ft_render_frame(t_engine *engine)
{
	//ft_apply_rotation(engine);
	//ft_key_player_move(engine);
	//ft_key_player_rotate(engine);
	ft_draw_map(engine);
	ft_draw_player(engine);
	ft_draw_3d_ray(engine);
	//ft_draw_camera(engine);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->img->img, 0, 0);
	if (engine->img == &engine->img0)
		engine->img = &engine->img1;
	else
		engine->img = &engine->img0;
	ft_clear_image(engine);
	ft_display_info(engine);
	return (0);
}

void	ft_draw_camera(t_engine *engine)
{
	t_line	line;

	float	cv_x, cv_y;

	line.start.color = 0x00000000;
	line.end.color = 0x00000000;
	cv_x = cos((engine->screen->player.angle - 90) * M_PI / 180.0) * 100;
	cv_y = sin((engine->screen->player.angle - 90) * M_PI / 180.0) * 100;
	// if (player->angle < 0)
	// 	player->angle += 360.0;
	// else if (player->angle > 360.0)
	// 	player->angle -= 360.0;
	line.start.x = engine->screen->player.x + cv_x;
	line.start.y = engine->screen->player.y + cv_y;
	line.end.x = engine->screen->player.x - cv_x;
	line.end.y = engine->screen->player.y -cv_y;
	ft_draw_line(engine, line);
}

void	ft_clear_image(t_engine *engine)
{
	int	x;
	int	y;

	y = 0;
	while (y < engine->screen->resolution.height)
	{
		x = 0;
		while (x < engine->screen->resolution.width)
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
			//ft_put_pixel(engine->img, i_column * 10 + engine->screen->offset.x, i_row * 10 + engine->screen->offset.y, color);
			//ft_get_point(engine, i_row, i_column, &line.start);
			//ft_get_point(engine, i_row, i_column + 1, &line.end);
			//ft_draw_line(engine, line);
			//ft_get_point(engine, i_row + 1, i_column, &line.end);
			//ft_draw_line(engine, line);
			i_column++;
		}
		i_row++;
	}
	/*
	line.start.color = 0x00FFFFFF;
	line.end.color = 0x00FFFFFF;
	i_row = 0;
	i_column = 0;
	line.start.x = 0;
	line.end.x = (engine->screen->columns) * engine->screen->tile_size;
	while (i_row < engine->screen->rows)
	{

		line.start.y = i_row * (engine->screen->tile_size);
		line.end.y = line.start.y;
		ft_draw_line(engine, line);
		i_row++;
	}
	line.start.y = 0;
	line.end.y = (engine->screen->rows) * engine->screen->tile_size;
	while (i_column < engine->screen->columns)
	{

		line.start.x = i_column * (engine->screen->tile_size);
		line.end.x = line.start.x;
		ft_draw_line(engine, line);
		i_column++;
	}
	*/
	//ft_draw_endlines(engine);
}
/*
static void	ft_draw_endlines(t_engine *engine)
{
	t_line	line;
	int		i_row;
	int		i_column;

	i_column = 0 ;
	while (i_column < engine->screen->columns - 1)
	{
		ft_get_point(engine, engine->screen->rows - 1, i_column, &line.start);
		ft_get_point(engine, engine->screen->rows - 1, i_column + 1, &line.end);
		ft_draw_line(engine, line);
		i_column++;
	}
	i_row = 0;
	while (i_row < engine->screen->rows - 1)
	{
		ft_get_point(engine, i_row, engine->screen->columns - 1, &line.start);
		ft_get_point(engine, i_row + 1, engine->screen->columns - 1, &line.end);
		ft_draw_line(engine, line);
		i_row++;
	}
}
*/