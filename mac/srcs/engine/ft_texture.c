/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:22:09 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 11:25:08 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_select_texture(t_engine *engine, t_3d_data *data)
{
	if (data->ray.vert.dist <= data->ray.hori.dist)
	{
		ft_set_line_color(&data->line, 0x00AAAAAA);
		data->cam.tx = data->ray.y;
		if (data->ray.angle > 90.0 && data->ray.angle < 270.0)
			data->cam.texture = &engine->ea_tex;
		else
			data->cam.texture = &engine->we_tex;
	}
	else if (data->ray.hori.dist < data->ray.vert.dist)
	{
		ft_set_line_color(&data->line, 0x00777777);
		data->cam.tx = data->ray.x;
		if (data->ray.angle > 180.0)
			data->cam.texture = &engine->so_tex;
		else
			data->cam.texture = &engine->no_tex;
	}
}

void	ft_draw_texture(t_engine *engine, t_3d_data *data)
{
	int		color;
	int		i_line;
	int		texture_x;

	texture_x = (int)(data->cam.tx * 2.0) % 64;
	i_line = 0;
	while (i_line <= data->cam.line_h)
	{
		color = ft_get_pixel(data->cam.texture, texture_x,
				(int)(data->cam.ty + data->cam.line_step * i_line));
		ft_put_pixel(engine->img, data->line.start.x + data->i,
			data->line.start.y + i_line, color);
		ft_put_pixel(engine->img, data->line.start.x + 1 + data->i,
			data->line.start.y + i_line, color);
		i_line++;
	}
}
