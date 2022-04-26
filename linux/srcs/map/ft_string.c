/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:49:54 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/26 15:24:07 by rkaufman         ###   ########.fr       */
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

	i_row = 0;
	while (i_row < screen->rows)
	{
		if (ft_valid_char(input[i_row], i_row) == RETURN_ERROR)
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
		if (ft_empty_space(input[i_row][0]) == RETURN_ERROR)
			exit(ft_error_border(input[i_row][0], i_row, 0));
		else if (ft_empty_space(input[i_row][screen->columns - 1]) == RETURN_ERROR)
			exit(ft_error_border(input[i_row][screen->columns], i_row, screen->columns));
		i_row++;
	}
	i_column = 0;
	while (i_column < screen->columns)
	{
		if (ft_empty_space(input[0][i_column]) == RETURN_ERROR)
			exit(ft_error_border(input[0][i_column], 0, i_column));
		else if (ft_empty_space(input[screen->rows - 1][i_column]) == RETURN_ERROR)
			exit(ft_error_border(input[screen->rows][i_column], screen->rows, i_column));
		i_column++;
	}
	i_row = 1;
	while (i_row < screen->rows - 1)
	{
		i_column = 1;
		while (i_column < screen->columns - 1)
		{
			if (ft_empty_space(input[i_row][i_column]) == RETURN_ERROR)
				if (ft_check_around(input, i_row, i_column) == RETURN_ERROR)
					exit(ft_error_border(input[i_row][i_column], i_row + 1, i_column + 1));
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
			if (ft_is_player(input[i_row][i_column]) == RETURN_TRUE)
			{
				player++;
				if (player > 1)
					exit(ft_error_player(input[i_row][i_column], i_row + 1, i_column + 1));
				screen->player.x = i_column * screen->tile_size.x + i_column + (screen->tile_size.x / 2.0);
				screen->player.y = i_row * screen->tile_size.y + i_row + (screen->tile_size.y / 2.0);
				if (input[i_row][i_column] == 'N')
					screen->player.angle = 270.0;
				else if (input[i_row][i_column] == 'E')
					screen->player.angle = 0.0;
				else if (input[i_row][i_column] == 'S')
					screen->player.angle = 90.0;
				else if (input[i_row][i_column] == 'W')
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
