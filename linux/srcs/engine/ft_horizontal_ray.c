/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:20:15 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/29 12:05:59 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_cast_horizontal_ray(t_engine *engine, t_ray *ray)
{
	t_player *player;
	double	atan;

	player = &engine->screen->player;
	ray->step_dist = 0;
	if (ray->angle > 180.0)
	{
		atan = -1 / tan(ft_deg_to_rad(ray->angle));
		ray->y = (((int) player->y / (engine->screen->tile_size) ) * (engine->screen->tile_size)) - 0.0001;
		ray->x = (player->y - ray->y) * atan + player->x;
		ray->step_y = - (engine->screen->tile_size);
		ray->step_x = (engine->screen->tile_size) * atan;
	}
	else if (ray->angle < 180.0)
	{
		atan = -1 / tan(ft_deg_to_rad(ray->angle));
		ray->y = (((int) player->y / (engine->screen->tile_size)) * (engine->screen->tile_size)) + engine->screen->tile_size;
		ray->x = (player->y - ray->y) * atan + player->x;
		ray->step_y = engine->screen->tile_size;
		ray->step_x = - (engine->screen->tile_size) * atan;
	}
	if (ray->angle == 0.0 || ray->angle == 180.0 || ray->angle == 360.0)
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
			ray->hori.x = ray->x;
			ray->hori.y = ray->y;
			ray->hori.dist = ft_dist(player, ray->x, ray->y);
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
		ray->hori.x = ray->x;
		ray->hori.y = ray->y;
		ray->hori.dist = ft_dist(player, ray->x, ray->y);
	}
}
