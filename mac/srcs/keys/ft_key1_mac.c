/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:45:18 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 10:14:07 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_key_pressed(int keycode, t_engine *engine)
{
	if (keycode == XK_ESC)
		ft_engine_destroy(engine);
	else if (keycode == XK_A || keycode == XK_S
		|| keycode == XK_D || keycode == XK_W)
		ft_key_player_move_pressed(keycode, engine);
	else if (keycode == XK_LEFT || keycode == XK_RIGHT)
		ft_key_player_rotate_pressed(keycode, engine);
	return (0);
}

int	ft_key_released(int keycode, t_engine *engine)
{
	if (keycode == XK_A || keycode == XK_S
		|| keycode == XK_D || keycode == XK_W)
		ft_key_player_move_released(keycode, engine);
	else if (keycode == XK_LEFT || keycode == XK_RIGHT)
		ft_key_player_rotate_released(keycode, engine);
	return (0);
}

void	ft_key_player_move_pressed(int keycode, t_engine *engine)
{
	if (keycode == XK_A)
		engine->key.a = 1;
	else if (keycode == XK_D)
		engine->key.d = 1;
	else if (keycode == XK_W)
		engine->key.w = 1;
	else if (keycode == XK_S)
		engine->key.s = 1;
}

void	ft_key_player_move_released(int keycode, t_engine *engine)
{
	if (keycode == XK_A)
		engine->key.a = 0;
	else if (keycode == XK_D)
		engine->key.d = 0;
	else if (keycode == XK_W)
		engine->key.w = 0;
	else if (keycode == XK_S)
		engine->key.s = 0;
}

void	ft_key_player_move(t_engine *engine)
{
	t_player	*player;

	player = &engine->screen->player;
	if (engine->key.a == 1)
	{
		player->x -= player->dx;
		player->y += player->dy;
	}
	if (engine->key.d == 1)
	{
		player->x += player->dx;
		player->y -= player->dy;
	}
	if (engine->key.w == 1)
	{
		player->x += player->dx;
		player->y += player->dy;
	}
	if (engine->key.s == 1)
	{
		player->x -= player->dx;
		player->y -= player->dy;
	}
}
