/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:48:47 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/26 15:56:40 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

unsigned int	ft_abs(int number)
{
	if (number < 0)
		return ((unsigned int)(number * -1));
	else
		return (number);
}

void	ft_apply_rotation(t_engine *engine)
{
	(void) engine;
}

float	ft_dist(t_player *player, float rx, float ry)
{
	return (sqrt((player->x - rx) * (player->x - rx) + (player->y - ry) * (player->y - ry)));
}
