/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:48:31 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 11:23:40 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	ft_get_point(t_engine *engine, int row, int column, t_3d_point *point)
{
	(void) engine;
		(void) row;
			(void) column;
				(void) point;
	/*
	point->x = engine->screen->offset.x + engine->screen->proj[row][column].x
		+ engine->screen->movement.x;
	point->y = engine->screen->offset.y + engine->screen->proj[row][column].y
		+ engine->screen->movement.y;
	point->color = engine->screen->proj[row][column].color;
	*/
}
