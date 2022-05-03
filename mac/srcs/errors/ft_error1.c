/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:36:44 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 15:02:04 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_error_extension(char *file)
{
	ft_printf("Error\nInvalid file extension [%s].\n", file);
	return (RETURN_ERROR);
}

int	ft_error_char(char c, int row)
{
	ft_printf("Error\nInvalid char [%c] in row %i .cub file by"
		" function ft_check_input_exit_on_error\n", c, row);
	return (RETURN_ERROR);
}

int	ft_error_border(char c, int row, int column, t_map *map)
{
	ft_printf("Error\nMap border open at char [%c] in row %i column %i .cub"
		" file by function ft_check_input_exit_on_error\n", c, row, column);
	ft_free_map(map);
	return (RETURN_ERROR);
}

int	ft_error_player(char c, int row, int column, t_map *map)
{
	ft_printf("Error\nMore than one player on Map char [%c] in row %i column"
		" %i .cub file by function ft_check_input_exit_on_error\n",
		c, row, column);
	ft_free_map(map);
	return (RETURN_ERROR);
}

int	ft_error_no_player(t_map *map)
{
	ft_printf("Error\nNo player on Map .cub file by"
		" function ft_check_input_exit_on_error\n");
	ft_free_map(map);
	return (RETURN_ERROR);
}
