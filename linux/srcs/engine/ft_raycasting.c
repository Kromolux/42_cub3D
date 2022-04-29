/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:01:29 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/29 15:50:07 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_select_shortest_ray(t_3d_data *data);
static void	ft_draw_ray(t_engine *engine, t_3d_data *data);
static void	ft_prepare_ray(t_engine *engine, t_ray *ray);
static void	ft_select_texture(t_engine *engine, t_3d_data *data);
static void	ft_draw_texture(t_engine *engine, t_3d_data *data);
static void	ft_prepare_cam(t_engine *engine, t_3d_data *data);

void	ft_draw_3d_ray(t_engine *engine)
{
	t_3d_data		data;
	
	data.ray.angle = engine->screen->player.angle - FOV / 2.0;
	data.i = 0;
	while (data.i < 600)
	{
		ft_prepare_ray(engine, &data.ray);
		ft_cast_horizontal_ray(engine, &data.ray);
		ft_cast_vertical_ray(engine, &data.ray);
		ft_select_shortest_ray(&data);
		ft_draw_ray(engine, &data);
		ft_prepare_cam(engine, &data);
		ft_select_texture(engine, &data);
		//ft_draw_rectangle_full(engine, line);
		ft_draw_texture(engine, &data);
		//ft_draw_line(engine, line);
		data.i++;
		data.ray.angle += 0.1;
	}
}

static void	ft_prepare_cam(t_engine *engine, t_3d_data *data)
{
	data->cam.angle = engine->screen->player.angle - data->ray.angle;
	data->cam.angle = ft_fix_angle(data->cam.angle);
	data->ray.dist = data->ray.dist * cos(ft_deg_to_rad(data->cam.angle));
	data->cam.line_h = (engine->screen->tile_size * engine->max_line_h) / data->ray.dist;
	data->cam.line_step = engine->no_tex.height / data->cam.line_h;
	data->cam.line_off = 0;
	if (data->cam.line_h > engine->max_line_h)
	{
		data->cam.line_off = ((data->cam.line_h - engine->max_line_h) / 2.0);
		data->cam.line_h = engine->max_line_h;
	}
	data->cam.line_o = 660 - data->cam.line_h / 2.0;
	data->line.start.x = engine->offset.x + data->i;
	data->line.start.y = data->cam.line_o;
	data->line.end.x = engine->offset.x + data->i;
	data->line.end.y = data->cam.line_o + data->cam.line_h;
	data->cam.ty = data->cam.line_off * data->cam.line_step;
}

static void	ft_draw_texture(t_engine *engine, t_3d_data *data)
{
	int		color;
	int		i_line;
	int		texture_x;

	texture_x = (int)(data->cam.tx * 2.0) % 64;
	i_line = 0;
	while (i_line <= data->cam.line_h)
	{
		color = ft_get_pixel(data->cam.texture, texture_x, (int)(data->cam.ty + data->cam.line_step * i_line));
		ft_put_pixel(engine->img, data->line.start.x + data->i, data->line.start.y + i_line, color);
		ft_put_pixel(engine->img, data->line.start.x + 1 + data->i, data->line.start.y + i_line, color);
		i_line++;
	}
}

static void	ft_select_texture(t_engine *engine, t_3d_data *data)
{
	if (data->ray.vert.dist < data->ray.hori.dist)
	{
		ft_set_line_color(&data->line, 0x00AAAAAA);
		data->cam.tx = data->ray.y;
		//texture = &engine->we_tex;
		data->cam.texture = &engine->ea_tex;
	}
	else if (data->ray.hori.dist < data->ray.vert.dist)
	{
		ft_set_line_color(&data->line, 0x00777777);
		data->cam.tx = data->ray.x;
		data->cam.texture = &engine->no_tex;
	}
	else
	{
		ft_set_line_color(&data->line, 0x00000000);
		data->cam.tx = data->ray.x;
		data->cam.texture = &engine->no_tex;
	}
}

static void	ft_prepare_ray(t_engine *engine, t_ray *ray)
{
	ray->angle = ft_fix_angle(ray->angle);
	ray->hori.x = engine->screen->player.x;
	ray->hori.y = engine->screen->player.y;
	ray->hori.dist = 100000;
	ray->vert.x = engine->screen->player.x;;
	ray->vert.y = engine->screen->player.y;
	ray->vert.dist = 100000;
	ray->dist = 100000;
}

static void	ft_select_shortest_ray(t_3d_data *data)
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

static void	ft_draw_ray(t_engine *engine, t_3d_data *data)
{
	data->line.start.x = engine->screen->player.x;
	data->line.start.y = engine->screen->player.y;
	data->line.end.x = data->ray.x;
	data->line.end.y = data->ray.y;
	ft_draw_line(engine, data->line);
}
