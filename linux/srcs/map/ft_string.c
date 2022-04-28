/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:49:54 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/28 18:59:02 by rkaufman         ###   ########.fr       */
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
	int	i_row;
	int	i_column;
	int	map_start;

	i_row = 0;
	while (input[i_row])
	{
		i_column = 0;
		while (input[i_row][i_column] == ' ')
			i_column++;
		if (ft_strncmp(&input[i_row][i_column], "F ", 2) == 0 && screen->floor_color == -1)
			screen->floor_color = ft_get_rgb_color(&input[i_row][i_column + 2]);
		else if (ft_strncmp(&input[i_row][i_column], "C ", 2) == 0 && screen->ceiling_color == -1)
			screen->ceiling_color = ft_get_rgb_color(&input[i_row][i_column + 2]);
		else if (ft_strncmp(&input[i_row][i_column], "NO ", 3) == 0 && screen->texture_no == NULL)
			screen->texture_no = ft_string_dup_skip_white(&input[i_row][i_column + 3]);
		else if (ft_strncmp(&input[i_row][i_column], "SO ", 3) == 0 && screen->texture_so == NULL)
			screen->texture_so = ft_string_dup_skip_white(&input[i_row][i_column + 3]);
		else if (ft_strncmp(&input[i_row][i_column], "WE ", 3) == 0 && screen->texture_we == NULL)
			screen->texture_we = ft_string_dup_skip_white(&input[i_row][i_column + 3]);
		else if (ft_strncmp(&input[i_row][i_column], "EA ", 3) == 0 && screen->texture_ea == NULL)
			screen->texture_ea = ft_string_dup_skip_white(&input[i_row][i_column + 3]);
		else
			exit(ft_error_map_file(input[i_row], i_row));
		i_row++;
		if (ft_check_map_identifier(screen) == RETURN_SUCCESS)
			break ;
	}
	while (ft_strlen(input[i_row]) == 0)
		i_row++;
	map_start = i_row;
	screen->map_start = map_start;
	while (input[i_row])
		i_row++;
	
	screen->rows = i_row - map_start;
	screen->columns = ft_get_map_columns(&input[map_start]);

	i_row = 0;
	while (i_row < screen->rows)
	{
		if (ft_valid_char(input[i_row + map_start], i_row + map_start) == RETURN_ERROR)
		{
			free(screen);
			ft_free_char_array(input);
			exit(RETURN_ERROR);
		}
		i_row++;
	}
	i_row = 0; //free mem at error!
	while (i_row < screen->rows)
	{
		if (ft_empty_space(input[i_row + map_start][0]) == RETURN_ERROR)
			exit(ft_error_border(input[i_row + map_start][0], i_row, 0));
		else if (ft_empty_space(input[i_row + map_start][screen->columns - 1]) == RETURN_ERROR)
			exit(ft_error_border(input[i_row + map_start][screen->columns], i_row, screen->columns));
		i_row++;
	}
	i_column = 0;
	while (i_column < screen->columns)
	{
		if (ft_empty_space(input[map_start][i_column]) == RETURN_ERROR)
			exit(ft_error_border(input[map_start][i_column], map_start, i_column));
		else if (ft_empty_space(input[screen->rows - 1 + map_start][i_column]) == RETURN_ERROR)
			exit(ft_error_border(input[screen->rows + map_start][i_column], screen->rows, i_column));
		i_column++;
	}
	i_row = + 1;
	while (i_row < screen->rows - 1)
	{
		i_column = 1;
		while (i_column < screen->columns - 1)
		{
			if (ft_empty_space(input[i_row + map_start][i_column]) == RETURN_ERROR)
				if (ft_check_around(input, i_row + map_start, i_column) == RETURN_ERROR)
					exit(ft_error_border(input[i_row + map_start][i_column], i_row + 1, i_column + 1));
			i_column++;
		}
		i_row++;
	}
	int	player;
	player = 0;
	i_row = 0;
	while (i_row < screen->rows)
	{
		i_column = 0;
		while (i_column < screen->columns)
		{
			if (ft_is_player(input[i_row + map_start][i_column]) == RETURN_TRUE)
			{
				player++;
				if (player > 1)
					exit(ft_error_player(input[i_row + map_start][i_column], i_row + 1 + map_start, i_column + 1));
				screen->player.x = i_column * screen->tile_size + ((screen->tile_size - 1) / 2.0);
				screen->player.y = i_row * screen->tile_size + ((screen->tile_size - 1) / 2.0);
				if (input[i_row + map_start][i_column] == 'N')
					screen->player.angle = 270.0;
				else if (input[i_row + map_start][i_column] == 'E')
					screen->player.angle = 0.0;
				else if (input[i_row + map_start][i_column] == 'S')
					screen->player.angle = 90.0;
				else if (input[i_row + map_start][i_column] == 'W')
					screen->player.angle = 180.0;
				screen->player.dx = cos(screen->player.angle * M_PI / 180) * 5;
				screen->player.dy = sin(screen->player.angle * M_PI / 180) * 5;
			}
			i_column++;
		}
		i_row++;
	}
	if (player == 0)
		exit(ft_error_no_player());
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

int	ft_empty_space(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (RETURN_ERROR);
	return (RETURN_SUCCESS);
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
		if (argv[i] != '1' && argv[i] != '0' && argv[i] != 'N' && argv[i] != 'S' && argv[i] != 'W' && argv[i] != 'E' && argv[i] != ' ')
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
