/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key0_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:45:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:53:04 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_calc_xy(t_player *player, double sx, double sy, char c);

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

void	ft_key_player_movement(int keycode, t_engine *engine)
{
	t_player	*player;
	float		sx;
	float		sy;

	player = &engine->screen->player;
	sx = cos(ft_deg_to_rad(player->angle - 90)) * MOV_MULTI;
	sy = sin(ft_deg_to_rad(player->angle - 90)) * MOV_MULTI;
	if (keycode == XK_a && player->free_a == 0)
		ft_calc_xy(player, sx, sy, '+');
	else if (keycode == XK_d && player->free_d == 0)
		ft_calc_xy(player, sx, sy, '-');
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

static void	ft_calc_xy(t_player *player, double sx, double sy, char c)
{
	if (c == '+')
	{
		player->x += sx;
		player->y += sy;
	}
	else if (c == '-')
	{
		player->x -= sx;
		player->y -= sy;
	}
}

void	ft_key_player_rotation(int keycode, t_engine *engine)
{
	t_player	*player;

	player = &engine->screen->player;
	if (keycode == XK_Left)
		player->angle -= ROT_STEP;
	else if (keycode == XK_Right)
		player->angle += ROT_STEP;
	player->angle = ft_fix_angle(player->angle);
	player->dx = cos(ft_deg_to_rad(player->angle)) * MOV_MULTI;
	player->dy = sin(ft_deg_to_rad(player->angle)) * MOV_MULTI;
}
