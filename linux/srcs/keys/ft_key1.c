/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:45:18 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 09:45:20 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_key_zoom(int keycode, t_engine *engine)
{
	if (keycode == XK_PLUS || keycode == XK_plus)
	{
		if (engine->screen->zoom >= 20)
			engine->screen->zoom += 5;
		else
			engine->screen->zoom += 1;
	}
	else if (keycode == XK_MINUS || keycode == XK_minus)
	{
		if (engine->screen->zoom >= 25)
			engine->screen->zoom -= 5;
		else if (engine->screen->zoom > 1)
			engine->screen->zoom -= 1;
	}
	else if (keycode == XK_f)
		engine->screen->zoom_z += 1;
	else if (keycode == XK_v)
		engine->screen->zoom_z -= 1;
}
