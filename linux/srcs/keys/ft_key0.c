/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:45:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/28 18:54:38 by rkaufman         ###   ########.fr       */
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
	return (0);
}

int	ft_key_pressed(int keycode, t_engine *engine)
{
	//ft_printf("key pressed %i\n", keycode);
	if (keycode == XK_Escape)
		ft_engine_destroy(engine);
	else if (keycode == XK_a || keycode == XK_s
		|| keycode == XK_d || keycode == XK_w)
		ft_key_player_move_pressed(keycode, engine);
	else if (keycode == XK_Left || keycode == XK_Right)
		ft_key_player_rotate_pressed(keycode, engine);
	return (0);
}

int	ft_key_released(int keycode, t_engine *engine)
{
	//ft_printf("key released %i\n", keycode);
	if (keycode == XK_a || keycode == XK_s
		|| keycode == XK_d || keycode == XK_w)
		ft_key_player_move_released(keycode, engine);
	else if (keycode == XK_Left || keycode == XK_Right)
		ft_key_player_rotate_released(keycode, engine);
	return (0);
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

void	ft_key_player_move(t_engine *engine)
{
	t_player	*player;

	player = &engine->screen->player;
	//ft_printf("player moved called\n");
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

void	ft_key_player_move_pressed(int keycode, t_engine *engine)
{
	if (keycode == XK_a)
		engine->key.a = 1;
	else if (keycode == XK_d)
		engine->key.d = 1;
	else if (keycode == XK_w)
		engine->key.w = 1;
	else if (keycode == XK_s)
		engine->key.s = 1;
}

void	ft_key_player_move_released(int keycode, t_engine *engine)
{
	if (keycode == XK_a)
		engine->key.a = 0;
	else if (keycode == XK_d)
		engine->key.d = 0;
	else if (keycode == XK_w)
		engine->key.w = 0;
	else if (keycode == XK_s)
		engine->key.s = 0;
}

void	ft_key_player_movement(int keycode, t_engine *engine)
{
	t_player	*player;
	float		sx;
	float		sy;
	player = &engine->screen->player;
	sx = cos(ft_deg_to_rad(player->angle - 90)) * 5;
	sy = sin(ft_deg_to_rad(player->angle - 90)) * 5;
	if (keycode == XK_a && player->free_a == 0)
	{
		player->x += sx;
		player->y += sy;
	}
	else if (keycode == XK_d && player->free_d == 0)
	{
		player->x -= sx;
		player->y -= sy;
	}
	else if (keycode == XK_w && player->free_w == 0)
	{
		player->x += player->dx;
		player->y += player->dy;
	}
	else if (keycode == XK_s && player->free_s == 0)
	{
		player->x -= player->dx;
		player->y -= player->dy;
	}
}

void	ft_key_player_rotate(t_engine *engine)
{
	t_player	*player;

	player = &engine->screen->player;
	if (engine->key.left == 1)
		player->angle -= 1.0;
	else if (engine->key.right == 1)
		player->angle += 1.0;
	if (player->angle < 0)
		player->angle += 360.0;
	else if (player->angle > 360.0)
		player->angle -= 360.0;
	player->dx = cos(ft_deg_to_rad(player->angle)) * 1;
	player->dy = sin(ft_deg_to_rad(player->angle)) * 1;
}

void	ft_key_player_rotation(int keycode, t_engine *engine)
{
	t_player	*player;

	player = &engine->screen->player;
	if (keycode == XK_Left)
		player->angle -= 3.0;
	else if (keycode == XK_Right)
		player->angle += 3.0;
	player->angle = ft_fix_angle(player->angle);
	player->dx = cos(ft_deg_to_rad(player->angle)) * 5;
	player->dy = sin(ft_deg_to_rad(player->angle)) * 5;
}

void	ft_key_player_rotate_pressed(int keycode, t_engine *engine)
{
	if (keycode == XK_Left)
		engine->key.left = 1;
	else if (keycode == XK_Right)
		engine->key.right = 1;
}

void	ft_key_player_rotate_released(int keycode, t_engine *engine)
{
	if (keycode == XK_Left)
		engine->key.left = 0;
	else if (keycode == XK_Right)
		engine->key.right = 0;
}
