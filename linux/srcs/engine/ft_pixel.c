/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:48:31 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:47:20 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = (char *) data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

int	ft_get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		dst = (char *) data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		return (*(unsigned int *) dst);
	}
	return (0);
}
