/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:47:16 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/29 14:16:54 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_assign_map_values(t_map *screen, char **string_array);

void	ft_create_map_array(char *input, t_map *screen)
{
	char	**string_array;

	string_array = ft_split(input, '\n');
	if (!string_array)
		ft_error_split(screen, input);
	free(input);
	ft_check_input_exit_on_error(screen, string_array);
	ft_allocate_mem_map(screen, string_array);
	ft_assign_map_values(screen, string_array);
	ft_check_map_exit_on_error(screen);
}

static void	ft_assign_map_values(t_map *screen, char **input)
{
	int	i_row;
	int	i_column;

	i_row = 0;
	while (i_row < screen->rows)
	{
		i_column = 0;
		while (i_column < screen->columns && input[screen->map_start + i_row][i_column])
		{
			screen->map[i_row][i_column] = input[screen->map_start + i_row][i_column];
			i_column++;
		}
		i_row++;
	}
	ft_free_char_array(input);
}

int	ft_check_all_map_identifier(t_map *screen)
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
