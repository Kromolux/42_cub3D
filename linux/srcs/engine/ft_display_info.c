/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:46:46 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/27 12:45:17 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_display_info1(t_engine *engine, int x, int color);
static void	ft_display_info2(t_engine *engine, int x, int color);

void	ft_display_info(t_engine *engine)
{
	int		x;
	int		color;
	char	*str;

	x = 1200;
	color = 0x00FFFF00;
	mlx_string_put(engine->mlx, engine->window, x, 20, color,
		"screen resolution:");
	str = ft_sprintf("%ix%i", engine->screen->resolution.width,
			engine->screen->resolution.height);
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
	mlx_string_put(engine->mlx, engine->window, x, 120, color, "color:");
	//if (engine->screen->colored == 1)
	//	mlx_string_put(engine->mlx, engine->window, x + 140, 120, color, "yes");
	//else
		mlx_string_put(engine->mlx, engine->window, x + 140, 120, color, "no");
	mlx_string_put(engine->mlx, engine->window, x, 160, color,
		"move projection:  arrow keys");
	mlx_string_put(engine->mlx, engine->window, x, 180, color,
		"zoom in/out:      +/-");
	str = ft_int_to_string(engine->screen->zoom);
	mlx_string_put(engine->mlx, engine->window, x + 200, 180, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 300, color,
		"center view:      pos1");
}

static void	ft_display_info2(t_engine *engine, int x, int color)
{
	char	*str;

	mlx_string_put(engine->mlx, engine->window, x, 200, color,
		"z inc/dec:        f/v");
	str = ft_int_to_string(engine->screen->zoom_z);
	mlx_string_put(engine->mlx, engine->window, x + 200, 200, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 220, color,
		"rotate x:         s/w");
	str = ft_int_to_string(engine->screen->angle.x);
	mlx_string_put(engine->mlx, engine->window, x + 200, 220, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 240, color,
		"rotate y:         a/d");
	str = ft_int_to_string(engine->screen->angle.y);
	mlx_string_put(engine->mlx, engine->window, x + 200, 240, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 260, color,
		"rotate z:         q/e");
	str = ft_int_to_string(engine->screen->angle.z);
	mlx_string_put(engine->mlx, engine->window, x + 200, 260, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 280, color,
		"change projection:  i = isometric p = parallel");
	
	mlx_string_put(engine->mlx, engine->window, x, 320, color,
		"player.x: ");
	str = malloc(20);
	sprintf(str, "%.8f", engine->screen->player.x);
	mlx_string_put(engine->mlx, engine->window, x + 100, 320, color, str);
	//free(str);
	sprintf(str, "%i",(int) engine->screen->player.x / (engine->screen->tile_size));
	mlx_string_put(engine->mlx, engine->window, x + 200, 320, color, str);

	mlx_string_put(engine->mlx, engine->window, x, 340, color,
		"player.y: ");
	sprintf(str, "%.8f",engine->screen->player.y);
	mlx_string_put(engine->mlx, engine->window, x + 100, 340, color, str);
	//free(str);
	sprintf(str, "%i", (int) engine->screen->player.y / (engine->screen->tile_size));
	mlx_string_put(engine->mlx, engine->window, x + 200, 340, color, str);

	mlx_string_put(engine->mlx, engine->window, x, 360, color,
		"player.angle: ");
	sprintf(str, "%f",engine->screen->player.angle);
	mlx_string_put(engine->mlx, engine->window, x + 200, 360, color, str);
	free(str);

}
