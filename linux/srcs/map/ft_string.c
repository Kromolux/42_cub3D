/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:49:54 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/29 14:29:33 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static int	ft_check_number(char *s);
static int	ft_valid_char(char *argv, int row);

size_t	ft_count_of_columns(char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	max;

	i = 0;
	max = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (count > max)
				max = count;
			count = 0;
			i++;
			continue;
		}
		i++;
		count++;
	}
	return (max);
}

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
		if (ft_valid_char(input[i_r + screen->map_start], i_r + screen->map_start) == RETURN_ERROR)
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
		i_c = 0;
		while (input[i_r][i_c] == ' ')
			i_c++;
		if (ft_strncmp(&input[i_r][i_c], "F ", 2) == 0 && map->floor_color == -1)
			map->floor_color = ft_get_rgb_color(&input[i_r][i_c + 2]);
		else if (ft_strncmp(&input[i_r][i_c], "C ", 2) == 0 && map->ceiling_color == -1)
			map->ceiling_color = ft_get_rgb_color(&input[i_r][i_c + 2]);
		else if (ft_strncmp(&input[i_r][i_c], "NO ", 3) == 0 && !map->texture_no)
			map->texture_no = ft_string_dup_skip_white(&input[i_r][i_c + 3]);
		else if (ft_strncmp(&input[i_r][i_c], "SO ", 3) == 0 && !map->texture_so)
			map->texture_so = ft_string_dup_skip_white(&input[i_r][i_c + 3]);
		else if (ft_strncmp(&input[i_r][i_c], "WE ", 3) == 0 && !map->texture_we)
			map->texture_we = ft_string_dup_skip_white(&input[i_r][i_c + 3]);
		else if (ft_strncmp(&input[i_r][i_c], "EA ", 3) == 0 && !map->texture_ea)
			map->texture_ea = ft_string_dup_skip_white(&input[i_r][i_c + 3]);
		else
			exit(ft_error_map_file(input[i_r], i_r));
		i_r++;
		if (ft_check_all_map_identifier(map) == RETURN_SUCCESS)
			break ;
	}
	return (i_r);
}

int	ft_check_around(char **input, int row, int column)
{
	if (input[row - 1][column - 1] == ' ' || input[row - 1][column - 1] == '\0'
		|| input[row - 1][column] == ' ' || input[row - 1][column] == '\0'
		|| input[row - 1][column + 1] == ' ' || input[row - 1][column + 1] == '\0'
		|| input[row][column + 1] == ' ' || input[row][column + 1] == '\0'
		|| input[row + 1][column + 1] == ' ' || input[row + 1][column + 1] == '\0'
		|| input[row + 1][column] == ' ' || input[row + 1][column] == '\0'
		|| input[row + 1][column - 1] == ' ' || input[row + 1][column - 1] == '\0'
		|| input[row][column - 1] == ' ' || input[row][column - 1] == '\0')
		return (RETURN_ERROR);
	return (RETURN_SUCCESS);
}

int	ft_is_empty_space(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (RETURN_TRUE);
	return (RETURN_FALSE);
}

int	ft_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (RETURN_TRUE);
	return (RETURN_FALSE);
}

static int	ft_valid_char(char *argv, int row)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != '1' && ft_is_empty_space(argv[i]) != RETURN_TRUE
			&& argv[i] != ' ')
			return (ft_error_char(argv[i], row));
		i++;
	}
	return (RETURN_TRUE);
}

int	ft_valid_number(char *argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
		{
			if (argv[i] == ',' && ft_check_hex(&argv[i]))
				break ;
			else if (argv[i] != '+' && argv[i] != '-')
				return (0);
		}
		i++;
	}
	if (!ft_check_number(argv))
		return (0);
	return (1);
}

static int	ft_check_number(char *s)
{
	long	value;

	if (s[0] < '0' || s[0] > '9')
	{
		if ((s[0] != '+' && s[0] != '-') || s[1] < '0' || s[1] > '9')
			return (0);
	}
	value = ft_string_to_int(s);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	return (1);
}
