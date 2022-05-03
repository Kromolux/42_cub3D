/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:45:32 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:53:23 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_error_input(t_map *screen, char **string_array)
{
	ft_printf("Error\nEmpty lines or different nr. of columns in rows in "
		"map file by function: ft_create_map_array.\n");
	ft_free_char_array(string_array);
	free(screen);
	exit(RETURN_ERROR);
}

void	ft_error_map(t_map *screen, char **string_array)
{
	ft_error_malloc("ft_create_map_array", "screen->map",
		sizeof(t_3d_point *) * screen->rows);
	ft_free_char_array(string_array);
	free(screen);
	exit(RETURN_ERROR);
}

void	ft_error_map_row(t_map *screen, char **string_array, int i_row)
{
	ft_error_malloc("ft_create_map_array", "screen->map[i_row]",
		sizeof(t_3d_point *) * screen->columns);
	ft_free_char_array(string_array);
	while (i_row > 0)
	{
		i_row--;
		free(screen->map[i_row]);
	}
	free(screen->map);
	free(screen);
	exit(RETURN_ERROR);
}
