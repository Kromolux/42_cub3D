/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:48:47 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:47:08 by rkaufman         ###   ########.fr       */
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

double	ft_dist(t_player *player, double rx, double ry)
{
	return (sqrt((player->x - rx) * (player->x - rx)
			+ (player->y - ry) * (player->y - ry)));
}

double	ft_fix_angle(double a)
{
	if (a < 0.0)
		a += 360.0;
	if (a >= 360.0)
		a -= 360.0;
	return (a);
}

double	ft_deg_to_rad(double d)
{
	return (d * M_PI / 180.0);
}
