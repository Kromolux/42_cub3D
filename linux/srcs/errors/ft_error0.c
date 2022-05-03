/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:45:27 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:49:10 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_error_arguments(void)
{
	ft_printf("Error\nProgram needs 2 arguments.\n./cub3D <file_to_open>.cub\n");
	return (RETURN_ERROR);
}

int	ft_error_malloc(char *function, char *variable, size_t size)
{
	ft_printf("Error\nNot enough memory for allocating space for [%s] [%i]"
		"bytes by function: %s\n", variable, size, function);
	return (RETURN_ERROR);
}

int	ft_error_file(char *function, char *file)
{
	ft_printf("Error\nCan not open file [%s] by function: %s.\n", file,
		function);
	return (RETURN_ERROR);
}

int	ft_error_file_result(char *function, char *file, int fd)
{
	ft_printf("Error\nEmpty file or read failed [%s] by function: %s\n",
		file, function);
	close(fd);
	return (RETURN_ERROR);
}

void	ft_error_split(t_map *screen, char *input)
{
	ft_error_malloc("ft_split", "string_array", 0);
	free(input);
	free(screen);
	exit(RETURN_ERROR);
}
