/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:48:13 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 18:33:22 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_alloc_map(t_map *screen, char **string_array);

void	ft_allocate_mem_map(t_map *screen, char **string_array)
{
	screen->map = (char **) malloc(sizeof(char *) * screen->rows);
	if (!screen->map)
		ft_error_map(screen, string_array);
	ft_alloc_map(screen, string_array);
}

static void	ft_alloc_map(t_map *screen, char **string_array)
{
	int	i_row;

	i_row = 0;
	while (i_row < screen->rows)
	{
		screen->map[i_row] = (char *) ft_calloc_char(sizeof(char)
				* screen->columns, ' ');
		if (!screen->map[i_row])
			ft_error_map_row(screen, string_array, i_row);
		i_row++;
	}
}

void	ft_free_map(t_map *screen)
{
	int	i_row;

	i_row = 0;
	while (i_row < screen->rows)
	{
		free(screen->map[i_row]);
		i_row++;
	}
	free(screen->map);
	free(screen);
}
