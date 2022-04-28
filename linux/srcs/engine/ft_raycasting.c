/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:01:29 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/28 17:54:15 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_draw_3d_ray(t_engine *engine)
{
	int r, mx,my,dof, i;
	double rx,ry,ra,xo,yo, atan;
	double hx, hy, dist_h;
	double vx, vy, dist_v;
	int		color;
	int		i_line;
	//int		dx, dy;
	double	dist_t;
	double ntan;
	t_player *player;
	t_line	line;
	
	(void) r;
	player = &engine->screen->player;
	ra = engine->screen->player.angle - 30.0;
	i = 0;

	line.start.x = 0;
	line.start.y = 500;
	line.end.x = 601;
	line.end.y = 660;
	line.start.color = engine->screen->ceiling_color;
	line.end.color = engine->screen->ceiling_color;
	ft_draw_rectangle_full(engine, line);
	line.start.x = 0;
	line.start.y = 661;
	line.end.x = 601;
	line.end.y = 820;
	line.start.color = engine->screen->floor_color;
	line.end.color = engine->screen->floor_color;
	ft_draw_rectangle_full(engine, line);

	while (i < 301)
	{
		ra = ft_fix_angle(ra);
	hx = player->x;
	hy = player->y;
	dist_h = 100000;
	vx = player->x;
	vy = player->y;
	dist_v = 100000;
	dist_t = 100000;
//horizontal check
	dof = 0;
	atan = -1 / tan(ft_deg_to_rad(ra));
	if (ra > 180.0)
	{
		ry = (((int) player->y / (engine->screen->tile_size) ) * (engine->screen->tile_size)) - 0.0001;
		rx = (player->y - ry) * atan + player->x;
		yo = - (engine->screen->tile_size);
		xo = (engine->screen->tile_size) * atan;
	}
	else if (ra < 180.0)
	{
		ry = (((int) player->y / (engine->screen->tile_size)) * (engine->screen->tile_size)) + engine->screen->tile_size;
		rx = (player->y - ry) * atan + player->x;
		yo = engine->screen->tile_size;
		xo = - (engine->screen->tile_size) * atan;
	}
	if (ra == 0.0 || ra == 180.0 || ra == 360.0)
	{
		rx = player->x;
		ry = player->y;
		dof = DISTANCE + 1;
	}
	while (dof < DISTANCE)
	{
		mx = (int) rx / (engine->screen->tile_size);
		my = (int) ry / (engine->screen->tile_size);
		if (my >= 0 && my < engine->screen->rows && mx >= 0 && mx < engine->screen->columns && engine->screen->map[my][mx] == '1')
		{
			dof = DISTANCE + 1;
			hx = rx;
			hy = ry;
			// dx = (int) hx - player->x;
			// dy = (int) hy - player->y;
			// dx = abs(dx);
			// dy = abs(dy);
			// dist_h = ft_dist_new(dx, dy, player->angle);
			dist_h = ft_dist(player, rx, ry);
			//printf("%i dist_h = %lf rx=%lf ry=%lf ra=%lf ra in rad=%lf atan=%lf\n", i, dist_h, rx, ry, ra, ft_deg_to_rad(ra), atan);
			//dist_h = dist_h * cos(ra);
			//printf("hit wall at [%i][%i]\n", my, mx);
		}
		else
		{
			rx += xo;
			ry += yo;
			dof++;
		}
	}
	if (dof == DISTANCE)
	{
		hx = rx;
		hy = ry;
		// dx = (int) hx - player->x;
		// dy = (int) hy - player->y;
		// dx = abs(dx);
		// dy = abs(dy);
		// dist_h = ft_dist_new(dx, dy, player->angle);
		dist_h = ft_dist(player, rx, ry);
	}


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
	ntan = -tan(ft_deg_to_rad(ra));
	if (ra > 90.0 && ra < 270.0)
	{
		rx = (((int) player->x / (engine->screen->tile_size) ) * (engine->screen->tile_size)) - 0.0001;
		ry = (player->x - rx) * ntan + player->y;
		xo = - (engine->screen->tile_size);
		yo = (engine->screen->tile_size) * ntan;
	}
	else if (ra < 90.0 || ra > 270.0)
	{
		rx = (((int) player->x / (engine->screen->tile_size)) * (engine->screen->tile_size)) + engine->screen->tile_size;
		ry = (player->x - rx) * ntan + player->y;
		xo = engine->screen->tile_size;
		yo = - (engine->screen->tile_size) * ntan;
	}
	if (ra == 90.0 || ra == 270.0)
	{
		rx = player->x;
		ry = player->y;
		dof = DISTANCE + 1;
	}
	while (dof < DISTANCE)
	{
		mx = (int) rx / (engine->screen->tile_size);
		my = (int) ry / (engine->screen->tile_size);
		if (my >= 0 && my < engine->screen->rows && mx >= 0 && mx < engine->screen->columns && engine->screen->map[my][mx] == '1')
		{
			dof = DISTANCE + 1;
			vx = rx;
			vy = ry;
			// dx = (int) vx - player->x;
			// dy = (int) vy - player->y;
			// dx = abs(dx);
			// dy = abs(dy);
			// dist_v = ft_dist_new(dx, dy, player->angle);
			//dist_v = ft_dist_new(abs((int) vx - player->x), abs((int) vy - player->y), player->angle);
			dist_v = ft_dist(player, rx, ry);
			//printf("%i dist_v = %lf rx=%lf ry=%lf ra=%lf ra in rad=%lf ntan=%lf\n", i, dist_v, rx, ry, ra, ft_deg_to_rad(ra), ntan);
			//printf("hit wall at [%i][%i]\n", my, mx);
		}
		else
		{
			rx += xo;
			ry += yo;
			dof++;
		}
	}
	if (dof == DISTANCE)
	{
		vx = rx;
		vy = ry;
		// dx = (int) vx - player->x;
		// dy = (int) vy - player->y;
		// dx = abs(dx);
		// dy = abs(dy);
		// dist_v = ft_dist_new(dx, dy, player->angle);
		//dist_v = ft_dist_new(abs((int) vx - player->x), abs((int) vy - player->y), player->angle);
		dist_v = ft_dist(player, rx, ry);
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
		line.start.color = 0x000000FF;
		line.end.color = 0x000000FF;
	if (dist_h < dist_v)
	{
		rx = hx;
		ry = hy;
		dist_t = dist_h;
		line.start.color = 0x0000FF00;
		line.end.color = 0x0000FF00;
	}
	if (dist_v < dist_h)
	{
		rx = vx;
		ry = vy;
		dist_t = dist_v;
		line.start.color = 0x00FF0000;
		line.end.color = 0x00FF0000;
	}
	(void) dist_t;

		line.start.x = engine->screen->player.x;
		line.start.y = engine->screen->player.y;
		line.end.x = rx;
		line.end.y = ry;
		ft_draw_line(engine, line);


	double ca = player->angle - ra;
	double line_h;
	ca = ft_fix_angle(ca);

	dist_t = dist_t * cos(ft_deg_to_rad(ca));
	//printf("%i dist_t = %lf rx=%lf ry=%lf ca=%lf ca in rad=%lf\n", i, dist_t, rx, ry, ca, ft_deg_to_rad(ca));
	line_h = (engine->screen->tile_size * 320.0) / dist_t;
	double line_step = engine->no_tex.height / line_h;
	double line_off = 0;
	if (line_h > 320)
	{
		line_off = ((line_h - 320.0) / 2.0);
		line_h = 320;
		//printf("line_off = %lf\n", line_off);
	}

	//if (dist_t >= 240)
	//	line_h = 0;
	double line_o = 660 - line_h / 2.0;
	double tx;
	t_data	*texture;
	line.start.x = 0 + i;
	line.start.y = line_o;
	line.end.x = 0 + i;
	line.end.y = line_o + line_h;
	//texture = NULL;
	if (dist_v < dist_h)
	{
		line.start.color = 0x00AAAAAA;
		line.end.color = 0x00AAAAAA;
		tx = ry;
		//texture = &engine->we_tex;
		texture = &engine->ea_tex;
	}
	else if (dist_h < dist_v)
	{
		line.start.color = 0x00777777;
		line.end.color = 0x00777777;
		tx = rx;
		texture = &engine->no_tex;
	}
	else
	{
		line.start.color = 0x00000000;
		line.end.color = 0x00000000;
		tx = rx;
		texture = &engine->no_tex;
	}
	//ft_draw_rectangle_full(engine, line);
	i_line = 0;
	double ty = line_off * line_step;
	while (i_line <= line_h)
	{
		color = ft_get_pixel(texture, (int) (tx * 2.0) % 64, (int) (ty + line_step * i_line));
		ft_put_pixel(engine->img, line.start.x + i, line.start.y + i_line, color);
		ft_put_pixel(engine->img, line.start.x + 1 + i, line.start.y + i_line, color);
		i_line++;
	}

	//ft_draw_line(engine, line);
	i++;
	ra += 0.2;
	}
}
