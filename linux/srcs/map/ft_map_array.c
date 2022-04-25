/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:47:16 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 12:11:26 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_assign_struct_values(t_map *screen, char *input);
static void	ft_assign_map_values(t_map *screen, char **string_array);

void	ft_create_map_array(char *input, t_map *screen)
{
	char	**string_array;
	//int		size;

	ft_assign_struct_values(screen, input);
	//ft_replace_in_string(input, '\n', ' ');
	string_array = ft_split(input, '\n');
	//if (!string_array)
	//	ft_error_split(screen, input);
	//free(input);
	//size = 0;
	//while (string_array[size])
	//	size++;
	//if (size != screen->rows * screen->columns)
	//	ft_error_input(screen, string_array);
	//ft_check_input_exit_on_error(screen, string_array);
	ft_allocate_mem_map(screen, string_array);
	ft_assign_map_values(screen, string_array);
}

static void	ft_assign_struct_values(t_map *screen, char *input)
{
	screen->rows = ft_count_of_in_str(input, '\n');
	screen->columns = ft_count_of_columns(input, '\n');
	ft_printf("created map for cub3D with rows=%i columns=%i\n", screen->rows, screen->columns);
}

static void	ft_assign_map_values(t_map *screen, char **string_array)
{
	int	i;
	int	i_row;
	int	i_column;

	i = 0;
	i_row = 0;
	while (i_row < screen->rows)
	{
		i_column = 0;
		while (i_column < screen->columns && string_array[i_row][i_column])
		{
			screen->map[i_row][i_column] = string_array[i_row][i_column];
			i_column++;
			i++;
		}
		i_row++;
	}
	ft_free_char_array(string_array);
}
