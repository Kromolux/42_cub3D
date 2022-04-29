/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:48:13 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/29 14:04:30 by rkaufman         ###   ########.fr       */
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
		free(screen->map[i_row]);
		i_row++;
	}
	free(screen->texture_no);
	free(screen->texture_so);
	free(screen->texture_we);
	free(screen->texture_ea);
	free(screen->map);
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
	int	i_row;
	int	i_column;

	i_row = 1; //free mem at error!
	while (i_row < map->rows - 1)
	{
		i_column = 1;
		while (i_column < map->columns - 1)
		{
			if (ft_is_empty_space(map->map[i_row][i_column]) == RETURN_TRUE)
				if (ft_check_around(map->map, i_row, i_column) == RETURN_ERROR)
					exit(ft_error_border(map->map[i_row][i_column], i_row + 1, i_column + 1));
			i_column++;
		}
		i_row++;
	}
}

void	ft_check_map_borders(t_map *map)
{
	int	i_row;
	int	i_column;

	i_row = 0;
	while (i_row < map->rows)
	{
		//printf("checking map[%i][%i]=%c\n", i_row + map->map_start, map->columns - 1, map->map[i_row][map->columns - 1]);
		if (ft_is_empty_space(map->map[i_row][0]) == RETURN_TRUE)
			exit(ft_error_border(map->map[i_row][0], i_row, 0));
		else if (ft_is_empty_space(map->map[i_row][map->columns - 1]) == RETURN_TRUE)
			exit(ft_error_border(map->map[i_row][map->columns], i_row, map->columns));
		i_row++;
	}
	i_column = 0;
	while (i_column < map->columns)
	{
		if (ft_is_empty_space(map->map[0][i_column]) == RETURN_TRUE)
			exit(ft_error_border(map->map[0][i_column], 0, i_column));
		else if (ft_is_empty_space(map->map[map->rows - 1 ][i_column]) == RETURN_TRUE)
			exit(ft_error_border(map->map[map->rows][i_column], map->rows, i_column));
		i_column++;
	}
}

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
	if (player == 0) //free map before exit!!!
		exit(ft_error_no_player());
}

void	ft_player_on_map(t_map *map, int i_row, int i_column, int *player)
{
	(*player)++;
	if (*player > 1) //free map before exit!!!
		exit(ft_error_player(map->map[i_row][i_column], i_row + 1, i_column + 1));
	map->player.x = i_column * map->tile_size + ((map->tile_size - 1) / 2.0);
	map->player.y = i_row * map->tile_size + ((map->tile_size - 1) / 2.0);
	if (map->map[i_row][i_column] == 'N')
		map->player.angle = 270.0;
	else if (map->map[i_row][i_column] == 'E')
		map->player.angle = 0.0;
	else if (map->map[i_row][i_column] == 'S')
		map->player.angle = 90.0;
	else if (map->map[i_row][i_column] == 'W')
		map->player.angle = 180.0;
	map->player.dx = cos(ft_deg_to_rad(map->player.angle)) * 5;
	map->player.dy = sin(ft_deg_to_rad(map->player.angle)) * 5;
}
