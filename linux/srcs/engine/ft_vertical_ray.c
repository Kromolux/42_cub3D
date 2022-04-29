/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:20:22 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/29 12:21:34 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_cast_vertical_ray(t_engine *engine, t_ray *ray)
{
	t_player *player;
	double	ntan;

	player = &engine->screen->player;
	ray->step_dist = 0;
	if (ray->angle > 90.0 && ray->angle < 270.0)
	{
		ntan = -tan(ft_deg_to_rad(ray->angle));
		ray->x = (((int) player->x / (engine->screen->tile_size) ) * (engine->screen->tile_size)) - 0.0001;
		ray->y = (player->x - ray->x) * ntan + player->y;
		ray->step_x = - (engine->screen->tile_size);
		ray->step_y = (engine->screen->tile_size) * ntan;
	}
	else if (ray->angle < 90.0 || ray->angle > 270.0)
	{
		ntan = -tan(ft_deg_to_rad(ray->angle));
		ray->x = (((int) player->x / (engine->screen->tile_size)) * (engine->screen->tile_size)) + engine->screen->tile_size;
		ray->y = (player->x - ray->x) * ntan + player->y;
		ray->step_x = engine->screen->tile_size;
		ray->step_y = - (engine->screen->tile_size) * ntan;
	}
	if (ray->angle == 90.0 || ray->angle == 270.0)
	{
		ray->x = player->x;
		ray->y = player->y;
		ray->step_dist = DISTANCE + 1;
	}
	while (ray->step_dist < DISTANCE)
	{
		ray->map_x = (int) ray->x / (engine->screen->tile_size);
		ray->map_y = (int) ray->y / (engine->screen->tile_size);
		if (ray->map_y >= 0 && ray->map_y < engine->screen->rows && ray->map_x >= 0 && ray->map_x < engine->screen->columns && engine->screen->map[ray->map_y][ray->map_x] == '1')
		{
			ray->step_dist = DISTANCE + 1;
			ray->vert.x = ray->x;
			ray->vert.y = ray->y;
			ray->vert.dist = ft_dist(player, ray->x, ray->y);
		}
		else
		{
			ray->x += ray->step_x;
			ray->y += ray->step_y;
			ray->step_dist++;
		}
	}
	if (ray->step_dist == DISTANCE)
	{
		ray->vert.x = ray->x;
		ray->vert.y = ray->y;
		ray->vert.dist = ft_dist(player, ray->x, ray->y);
	}
}
