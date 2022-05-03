/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input_map0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:04:45 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 11:35:28 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static int	ft_check_map_identifier(t_map *map, char *input, int i);
static int	ft_skip_whitespaces(char *input);

void	ft_check_input_exit_on_error(t_map *screen, char **input)
{
	int	i_r;

	i_r = ft_check_identifiers_in_file(screen, input);
	while (ft_strlen(input[i_r]) == 0)
		i_r++;
	screen->map_start = i_r;
	while (input[i_r])
		i_r++;
	screen->rows = i_r - screen->map_start;
	screen->columns = ft_get_map_columns(&input[screen->map_start]);
	i_r = 0;
	while (i_r < screen->rows)
	{
		if (ft_valid_char(input[i_r + screen->map_start],
				i_r + screen->map_start) == RETURN_ERROR)
		{
			free(screen);
			ft_free_char_array(input);
			exit(RETURN_ERROR);
		}
		i_r++;
	}
}

int	ft_check_identifiers_in_file(t_map *map, char **input)
{
	int	i_r;
	int	i_c;

	i_r = 0;
	while (input[i_r])
	{
		i_c = ft_skip_whitespaces(input[i_r]);
		if (ft_check_map_identifier(map, input[i_r], i_c) == RETURN_ERROR)
			exit(ft_error_map_file(input[i_r], i_r, map));
		i_r++;
		if (ft_check_all_map_identifier(map) == RETURN_SUCCESS)
			break ;
	}
	return (i_r);
}

static int	ft_check_map_identifier(t_map *map, char *input, int i)
{
	if (ft_strncmp(&input[i], "F ", 2) == 0 && map->floor_color == -1)
	{
		map->floor_color = ft_get_rgb_color(&input[i + 2]);
		if (map->floor_color == RETURN_ERROR)
			return (RETURN_ERROR);
	}
	else if (ft_strncmp(&input[i], "C ", 2) == 0 && map->ceiling_color == -1)
	{
		map->ceiling_color = ft_get_rgb_color(&input[i + 2]);
		if (map->ceiling_color == RETURN_ERROR)
			return (RETURN_ERROR);
	}
	else if (ft_strncmp(&input[i], "NO ", 3) == 0 && !map->texture_no)
		map->texture_no = ft_string_dup_skip_white(&input[i + 3]);
	else if (ft_strncmp(&input[i], "SO ", 3) == 0 && !map->texture_so)
		map->texture_so = ft_string_dup_skip_white(&input[i + 3]);
	else if (ft_strncmp(&input[i], "WE ", 3) == 0 && !map->texture_we)
		map->texture_we = ft_string_dup_skip_white(&input[i + 3]);
	else if (ft_strncmp(&input[i], "EA ", 3) == 0 && !map->texture_ea)
		map->texture_ea = ft_string_dup_skip_white(&input[i + 3]);
	else
		return (RETURN_ERROR);
	return (RETURN_SUCCESS);
}

static int	ft_skip_whitespaces(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
		i++;
	return (i);
}
