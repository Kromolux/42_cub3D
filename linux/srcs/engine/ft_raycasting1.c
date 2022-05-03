/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:19:49 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:48:14 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_prepare_ray(t_engine *engine, t_ray *ray)
{
	ray->angle = ft_fix_angle(ray->angle);
	ray->hori.x = engine->screen->player.x;
	ray->hori.y = engine->screen->player.y;
	ray->hori.dist = 100000;
	ray->vert.x = engine->screen->player.x;
	ray->vert.y = engine->screen->player.y;
	ray->vert.dist = 100000;
	ray->dist = 100000;
}

void	ft_draw_ray(t_engine *engine, t_3d_data *data)
{
	data->line.start.x = engine->screen->player.x;
	data->line.start.y = engine->screen->player.y;
	data->line.end.x = data->ray.x;
	data->line.end.y = data->ray.y;
	ft_draw_line(engine, data->line);
}

void	ft_prepare_cam(t_engine *engine, t_3d_data *data)
{
	data->cam.angle = engine->screen->player.angle - data->ray.angle;
	data->cam.angle = ft_fix_angle(data->cam.angle);
	data->ray.dist = data->ray.dist * cos(ft_deg_to_rad(data->cam.angle));
	data->cam.line_h = (engine->screen->tile_size * engine->max_line_h)
		/ data->ray.dist;
	data->cam.line_step = engine->no_tex.height / data->cam.line_h;
	data->cam.line_off = 0;
	if (data->cam.line_h > engine->max_line_h)
	{
		data->cam.line_off = ((data->cam.line_h - engine->max_line_h) / 2.0);
		data->cam.line_h = engine->max_line_h;
	}
	data->cam.line_o = (engine->offset.y + engine->max_line_h / 2.0)
		- data->cam.line_h / 2.0;
	data->line.start.x = engine->offset.x + data->i;
	data->line.start.y = data->cam.line_o;
	data->line.end.x = engine->offset.x + data->i;
	data->line.end.y = data->cam.line_o + data->cam.line_h;
	data->cam.ty = data->cam.line_off * data->cam.line_step;
}

void	ft_select_shortest_ray(t_3d_data *data)
{
	if (data->ray.hori.dist < data->ray.vert.dist)
	{
		data->ray.x = data->ray.hori.x;
		data->ray.y = data->ray.hori.y;
		data->ray.dist = data->ray.hori.dist;
		ft_set_line_color(&data->line, 0x0000FF00);
	}
	else if (data->ray.vert.dist < data->ray.hori.dist)
	{
		data->ray.x = data->ray.vert.x;
		data->ray.y = data->ray.vert.y;
		data->ray.dist = data->ray.vert.dist;
		ft_set_line_color(&data->line, 0x00FF0000);
	}
	else
		ft_set_line_color(&data->line, 0x000000FF);
}
