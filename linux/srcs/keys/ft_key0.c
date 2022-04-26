/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:45:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/26 15:23:24 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_key(int keycode, t_engine *engine)
{
	if (keycode == XK_Escape)
		ft_engine_destroy(engine);
	else if (keycode == XK_a || keycode == XK_s
		|| keycode == XK_d || keycode == XK_w)
		ft_key_player_movement(keycode, engine);
	else if (keycode == XK_Left || keycode == XK_Right)
		ft_key_player_rotation(keycode, engine);
	else if (keycode == XK_i || keycode == XK_p)
		ft_key_projection_change(keycode, engine);
	else if (keycode == XK_PLUS || keycode == XK_MINUS
		|| keycode == XK_f || keycode == XK_v
		|| keycode == XK_plus || keycode == XK_minus)
		ft_key_zoom(keycode, engine);
	else if (keycode == XK_Home)
		ft_key_center_view(keycode, engine);
	return (0);
}

void	ft_key_center_view(int keycode, t_engine *engine)
{
	if (keycode == XK_Home)
	{
		engine->screen->movement.x = 0;
		engine->screen->movement.y = 0;
		engine->screen->movement.z = 0;
	}
}

void	ft_key_projection_change(int keycode, t_engine *engine)
{
	if (keycode == XK_i)
	{
		(void) engine;
	}
	else if (keycode == XK_p)
	{
				(void) engine;
	}
}

void	ft_key_player_movement(int keycode, t_engine *engine)
{
	t_player	*player;

	player = &engine->screen->player;
	if (keycode == XK_a)
	{
		player->x -= player->dx;
		player->y += player->dy;
	}
	else if (keycode == XK_d)
	{
		player->x += player->dx;
		player->y -= player->dy;
	}
	else if (keycode == XK_w)
	{
		player->x += player->dx;
		player->y += player->dy;
	}
	else if (keycode == XK_s)
	{
		player->x -= player->dx;
		player->y -= player->dy;
	}
}

void	ft_key_player_rotation(int keycode, t_engine *engine)
{
	t_player	*player;

	player = &engine->screen->player;
	if (keycode == XK_Left)
		player->angle -= 3.0;
	else if (keycode == XK_Right)
		player->angle += 3.0;
	if (player->angle < 0)
		player->angle += 360.0;
	else if (player->angle > 360.0)
		player->angle -= 360.0;
	player->dx = cos(player->angle * M_PI / 180.0) * 5;
	player->dy = sin(player->angle * M_PI / 180.0) * 5;
}
