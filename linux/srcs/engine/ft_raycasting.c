/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:01:29 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/26 16:35:47 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_draw_3d_ray(t_engine *engine)
{
	int r, mx,my,dof, i;
	float rx,ry,ra,xo,yo, atan;
	float hx, hy, dist_h;
	float vx, vy, dist_v;
	float	dist_t;
	float ntan;
	t_player *player;

	(void) r;
	player = &engine->screen->player;
	ra = engine->screen->player.angle - 30.0;
	i = 0;
	while (i < 60)
	{
	if (ra < 0.0)
		ra += 360.0;
	if (ra > 360.0)
		ra -= 360.0;
	hx = player->x;
	hy = player->y;
	dist_h = 100000;
	vx = player->x;
	vy = player->y;
	dist_v = 100000;
	dist_t = 100000;
//horizontal check
	dof = 0;
	atan = -1 / tan(ra * M_PI / 180.0);
	if (ra > 180.0)
	{
		ry = (((int) player->y / (engine->screen->tile_size.y + 1) ) * (engine->screen->tile_size.y + 1)) - 0.0001;
		rx = (player->y - ry) * atan + player->x;
		yo = - (engine->screen->tile_size.y + 1);
		xo = (engine->screen->tile_size.x + 1) * atan;
	}
	else if (ra < 180.0)
	{
		ry = (((int) player->y / (engine->screen->tile_size.y + 1)) * (engine->screen->tile_size.y + 1)) + engine->screen->tile_size.y + 1;
		rx = (player->y - ry) * atan + player->x;
		yo = engine->screen->tile_size.y + 1;
		xo = - (engine->screen->tile_size.x + 1) * atan;
	}
	if (ra == 0.0 || ra == 180.0 || ra == 360.0)
	{
		rx = player->x;
		ry = player->y;
		dof = 6;
	}
	while (dof < 6)
	{
		mx = (int) rx / (engine->screen->tile_size.x + 1);
		my = (int) ry / (engine->screen->tile_size.y + 1);
		if (my >= 0 && my < engine->screen->rows && mx >= 0 && mx < engine->screen->columns && engine->screen->map[my][mx] == '1')
		{
			dof = 7;
			hx = rx;
			hy = ry;
			dist_h = ft_dist(player, rx, ry);
			//printf("hit wall at [%i][%i]\n", my, mx);
		}
		else
		{
			rx += xo;
			ry += yo;
			dof++;
		}
	}
	t_line	line;

	// if (dof == 9)
	// {
	// 	line.start.color = 0x0000FF00;
	// 	line.end.color = 0x0000FF00;
	// 	line.start.x = engine->screen->player.x;
	// 	line.start.y = engine->screen->player.y;
	// 	line.end.x = rx;
	// 	line.end.y = ry;
	// 	ft_draw_line(engine, line);
	// }

///vertical check
	dof = 0;
	ntan = -tan(ra * M_PI / 180.0);
	if (ra > 90.0 && ra < 270.0)
	{
		rx = (((int) player->x / (engine->screen->tile_size.x + 1) ) * (engine->screen->tile_size.x + 1)) - 0.0001;
		ry = (player->x - rx) * ntan + player->y;
		xo = - (engine->screen->tile_size.x + 1);
		yo = (engine->screen->tile_size.y + 1) * ntan;
	}
	else if (ra < 90.0 || ra > 270.0)
	{
		rx = (((int) player->x / (engine->screen->tile_size.x + 1)) * (engine->screen->tile_size.x + 1)) + engine->screen->tile_size.x + 1;
		ry = (player->x - rx) * ntan + player->y;
		xo = engine->screen->tile_size.x + 1;
		yo = - (engine->screen->tile_size.y + 1) * ntan;
	}
	if (ra == 90.0 || ra == 270.0)
	{
		rx = player->x;
		ry = player->y;
		dof = 6;
	}
	while (dof < 6)
	{
		mx = (int) rx / (engine->screen->tile_size.x + 1);
		my = (int) ry / (engine->screen->tile_size.y + 1);
		if (my >= 0 && my < engine->screen->rows && mx >= 0 && mx < engine->screen->columns && engine->screen->map[my][mx] == '1')
		{
			dof = 7;
			vx = rx;
			vy = ry;
			dist_v = ft_dist(player, rx, ry);
			//printf("hit wall at [%i][%i]\n", my, mx);
		}
		else
		{
			rx += xo;
			ry += yo;
			dof++;
		}
	}

	// if (dof == 9)
	// {
	// 	line.start.color = 0x00FF0000;
	// 	line.end.color = 0x00FF0000;
	// 	line.start.x = engine->screen->player.x;
	// 	line.start.y = engine->screen->player.y;
	// 	line.end.x = rx;
	// 	line.end.y = ry;
	// 	ft_draw_line(engine, line);
	// }

	if (dist_h < dist_v)
	{
		rx = hx;
		ry = hy;
		dist_t = dist_h;
	}
	if (dist_v < dist_h)
	{
		rx = vx;
		ry = vy;
		dist_t = dist_v;
	}
	(void) dist_t;
		line.start.color = 0x00FF0000;
		line.end.color = 0x00FF0000;
		line.start.x = engine->screen->player.x;
		line.start.y = engine->screen->player.y;
		line.end.x = rx;
		line.end.y = ry;
		ft_draw_line(engine, line);

	i++;
	ra++;
	}
}
