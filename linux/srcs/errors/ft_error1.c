/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:36:44 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/26 08:31:41 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_error_extension(char *file)
{
	ft_printf("Error! Invalid file extension [%s].\n", file);
	return (RETURN_ERROR);
}

int	ft_error_char(char c, int row)
{
	ft_printf("Error! Invalid char [%c] in row %i .cub file by"
	" function ft_check_input_exit_on_error\n", c, row);
	return (RETURN_ERROR);	
}

int	ft_error_border(char c, int row, int column)
{
	ft_printf("Error! Map border open at char [%c] in row %i column %i .cub file by"
	" function ft_check_input_exit_on_error\n", c, row, column);
	return (RETURN_ERROR);	
}

int	ft_error_player(char c, int row, int column)
{
	ft_printf("Error! More than one player on Map char [%c] in row %i column %i .cub file by"
	" function ft_check_input_exit_on_error\n", c, row, column);
	return (RETURN_ERROR);	
}

int	ft_error_no_player(void)
{
	ft_printf("Error! No player on Map .cub file by"
	" function ft_check_input_exit_on_error\n");
	return (RETURN_ERROR);	
}
