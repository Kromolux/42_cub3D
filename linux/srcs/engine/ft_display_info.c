/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:46:46 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:45:43 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_display_info1(t_engine *engine, int x, int color);
static void	ft_display_info2(t_engine *engine, int x, int color);
static char	*ft_double_to_string(double xy);

void	ft_display_info(t_engine *engine)
{
	int		x;
	int		color;
	char	*str;

	x = 1200;
	color = 0x00FFFF00;
	mlx_string_put(engine->mlx, engine->window, x, 20, color,
		"screen resolution:");
	str = ft_sprintf("%ix%i", WIDTH, HEIGHT);
	mlx_string_put(engine->mlx, engine->window, x + 140, 20, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 40, color,
		"open file:");
	mlx_string_put(engine->mlx, engine->window, x + 140, 40, color,
		engine->file);
	mlx_string_put(engine->mlx, engine->window, x, 60, color, "rows:");
	str = ft_int_to_string(engine->screen->rows);
	mlx_string_put(engine->mlx, engine->window, x + 140, 60, color, str);
	free(str);
	ft_display_info1(engine, x, color);
	ft_display_info2(engine, x, color);
}

static void	ft_display_info1(t_engine *engine, int x, int color)
{
	char	*str;

	mlx_string_put(engine->mlx, engine->window, x, 80, color, "columns:");
	str = ft_int_to_string(engine->screen->columns);
	mlx_string_put(engine->mlx, engine->window, x + 140, 80, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 100, color,
		"total points:");
	str = ft_int_to_string(engine->screen->rows * engine->screen->columns);
	mlx_string_put(engine->mlx, engine->window, x + 140, 100, color, str);
	free(str);
}

static void	ft_display_info2(t_engine *engine, int x, int color)
{
	char	*str;

	mlx_string_put(engine->mlx, engine->window, x, 320, color,
		"player.x: ");
	str = ft_double_to_string(engine->screen->player.x);
	mlx_string_put(engine->mlx, engine->window, x + 100, 320, color, str);
	free(str);
	str = ft_sprintf("%i", (int) engine->screen->player.x
			/ (engine->screen->tile_size));
	mlx_string_put(engine->mlx, engine->window, x + 200, 320, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 340, color,
		"player.y: ");
	str = ft_double_to_string(engine->screen->player.y);
	mlx_string_put(engine->mlx, engine->window, x + 100, 340, color, str);
	free(str);
	str = ft_sprintf("%i", (int) engine->screen->player.y
			/ (engine->screen->tile_size));
	mlx_string_put(engine->mlx, engine->window, x + 200, 340, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 360, color,
		"player.angle: ");
	str = ft_double_to_string(engine->screen->player.angle);
	mlx_string_put(engine->mlx, engine->window, x + 200, 360, color, str);
	free(str);
}

static char	*ft_double_to_string(double xy)
{
	char	*str;
	int		tmp;

	tmp = (int) xy;
	str = ft_sprintf("%i", tmp);
	str = ft_realloc(str, ".", 1, 0);
	str = ft_realloc(str, ft_sprintf("%i",
				(int)(((double) xy - tmp) * 100000)), 1, 1);
	return (str);
}
