/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:20:22 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:48:40 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_ray_toleft(t_ray *ray, t_player *player, int tile_size);
static void	ft_ray_toright(t_ray *ray, t_player *player, int tile_size);

void	ft_cast_vertical_ray(t_engine *engine, t_ray *ray)
{
	t_player	*player;

	player = &engine->screen->player;
	ray->step_dist = 0;
	if (ray->angle > 90.0 && ray->angle < 270.0)
		ft_ray_toleft(ray, player, engine->screen->tile_size);
	else if (ray->angle < 90.0 || ray->angle > 270.0)
		ft_ray_toright(ray, player, engine->screen->tile_size);
	if (ray->angle == 90.0 || ray->angle == 270.0)
		ft_invalid_angle(ray, player);
	ray->vert = ft_ray_hit(ray, player, engine->screen);
}

static void	ft_ray_toleft(t_ray *ray, t_player *player, int tile_size)
{
	double	ntan;

	ntan = -tan(ft_deg_to_rad(ray->angle));
	ray->x = (((int) player->x / (tile_size)) * (tile_size)) - 0.0001;
	ray->y = (player->x - ray->x) * ntan + player->y;
	ray->step_x = - (tile_size);
	ray->step_y = (tile_size) * ntan;
}

static void	ft_ray_toright(t_ray *ray, t_player *player, int tile_size)
{
	double	ntan;

	ntan = -tan(ft_deg_to_rad(ray->angle));
	ray->x = (((int) player->x / (tile_size)) * (tile_size)) + tile_size;
	ray->y = (player->x - ray->x) * ntan + player->y;
	ray->step_x = tile_size;
	ray->step_y = - (tile_size) * ntan;
}
