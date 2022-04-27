/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:47:16 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/27 20:09:47 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_assign_map_values(t_map *screen, char **string_array);

void	ft_create_map_array(char *input, t_map *screen)
{
	char	**string_array;
	//int		size;

	//screen->rows = ft_count_of_in_str(input, '\n') + 1;
	//screen->columns = ft_count_of_columns(input, '\n');
	screen->floor_color = -1;
	screen->ceiling_color = -1;
	screen->texture_no = NULL;
	screen->texture_so = NULL;
	screen->texture_we = NULL;
	screen->texture_ea = NULL;
	//ft_replace_in_string(input, '\n', ' ');
	string_array = ft_split(input, '\n');
	if (!string_array)
		ft_error_split(screen, input);
	free(input);
	//size = 0;
	//while (string_array[size])
	//	size++;
	//if (size != screen->rows)
	//	ft_error_input(screen, string_array);
	ft_check_input_exit_on_error(screen, string_array);
	ft_allocate_mem_map(screen, string_array);
	ft_assign_map_values(screen, string_array);
}

static void	ft_assign_map_values(t_map *screen, char **string_array)
{
	int	i_row;
	int	i_column;

	i_row = 0;
	while (i_row < screen->rows)
	{
		i_column = 0;
		while (i_column < screen->columns && string_array[screen->map_start + i_row][i_column])
		{
			screen->map[i_row][i_column] = string_array[screen->map_start + i_row][i_column];
			i_column++;
		}
		i_row++;
	}
	ft_free_char_array(string_array);
}

int	ft_check_map_identifier(t_map *screen)
{
	if (screen->floor_color > -1
		&& screen->ceiling_color > -1
		&& screen->texture_no != NULL
		&& screen->texture_so != NULL
		&& screen->texture_we != NULL
		&& screen->texture_ea != NULL)
		return (RETURN_SUCCESS);
	return (RETURN_ERROR);
}

size_t	ft_get_map_columns(char **input)
{
	size_t	i;
	size_t	count;
	size_t	max;

	i = 0;
	max = 0;
	count = 0;
	while (input[i])
	{
		count = ft_strlen(input[i]);
		if (count > max)
			max = count;
		count = 0;
		i++;
	}
	return (max);
}