/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:48:13 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:55:42 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_allocate_mem_map(t_map *screen, char **string_array)
{
	int	i_row;

	i_row = 0;
	screen->map = (char **) malloc(sizeof(char *) * screen->rows);
	if (!screen->map)
		ft_error_map(screen, string_array);
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
		ft_free(screen->map[i_row]);
		i_row++;
	}
	ft_free(screen->texture_no);
	ft_free(screen->texture_so);
	ft_free(screen->texture_we);
	ft_free(screen->texture_ea);
	ft_free(screen->map);
	free(screen);
}

void	ft_check_map_exit_on_error(t_map *map)
{
	ft_check_map_borders(map);
	ft_check_map_open(map);
	ft_check_for_player_on_map(map);
}

void	ft_check_map_open(t_map *map)
{
	int	i_r;
	int	i_c;

	i_r = 1;
	while (i_r < map->rows - 1)
	{
		i_c = 1;
		while (i_c < map->columns - 1)
		{
			if (ft_is_empty_space(map->map[i_r][i_c]) == RETURN_TRUE)
				if (ft_check_around(map->map, i_r, i_c) == RETURN_ERROR)
					exit(ft_error_border(map->map[i_r][i_c],
							i_r + 1, i_c + 1, map));
			i_c++;
		}
		i_r++;
	}
}

void	ft_check_map_borders(t_map *map)
{
	int	i_r;
	int	i_c;

	i_r = 0;
	while (i_r < map->rows)
	{
		if (ft_is_empty_space(map->map[i_r][0]) == RETURN_TRUE)
			exit(ft_error_border(map->map[i_r][0], i_r, 0, map));
		else if (ft_is_empty_space(map->map[i_r][map->columns - 1])
				== RETURN_TRUE)
			exit(ft_error_border(map->map[i_r][map->columns],
					i_r, map->columns, map));
		i_r++;
	}
	i_c = 0;
	while (i_c < map->columns)
	{
		if (ft_is_empty_space(map->map[0][i_c]) == RETURN_TRUE)
			exit(ft_error_border(map->map[0][i_c], 0, i_c, map));
		else if (ft_is_empty_space(map->map[map->rows - 1][i_c])
				== RETURN_TRUE)
			exit(ft_error_border(map->map[map->rows][i_c],
					map->rows, i_c, map));
		i_c++;
	}
}
