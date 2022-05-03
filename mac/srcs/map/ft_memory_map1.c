/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_map1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:40:20 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 10:40:30 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_check_for_player_on_map(t_map *map)
{
	int	player;
	int	i_row;
	int	i_column;

	player = 0;
	i_row = 0;
	while (i_row < map->rows)
	{
		i_column = 0;
		while (i_column < map->columns)
		{
			if (ft_is_player(map->map[i_row][i_column]) == RETURN_TRUE)
				ft_player_on_map(map, i_row, i_column, &player);
			i_column++;
		}
		i_row++;
	}
	if (player == 0)
		exit(ft_error_no_player(map));
}

void	ft_player_on_map(t_map *map, int i_r, int i_c, int *player)
{
	(*player)++;
	if (*player > 1)
		exit(ft_error_player(map->map[i_r][i_c], i_r + 1, i_c + 1, map));
	map->player.x = i_c * map->tile_size + ((map->tile_size - 1) / 2.0);
	map->player.y = i_r * map->tile_size + ((map->tile_size - 1) / 2.0);
	if (map->map[i_r][i_c] == 'N')
		map->player.angle = 270.0;
	else if (map->map[i_r][i_c] == 'E')
		map->player.angle = 0.0;
	else if (map->map[i_r][i_c] == 'S')
		map->player.angle = 90.0;
	else if (map->map[i_r][i_c] == 'W')
		map->player.angle = 180.0;
	map->player.dx = cos(ft_deg_to_rad(map->player.angle)) * 5;
	map->player.dy = sin(ft_deg_to_rad(map->player.angle)) * 5;
}
