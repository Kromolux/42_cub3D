/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:47:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 10:27:50 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_init_struct_t_map(t_map *var);

t_map	*ft_read_input_map(char *file)
{
	t_map	*output;
	int		fd;
	char	*read_file_result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(ft_error_file("ft_read_input_map", file));
	read_file_result = ft_read_file(fd);
	if (!read_file_result)
		exit(ft_error_file_result("ft_read_file", file, fd));
	close(fd);
	output = (t_map *) ft_calloc(sizeof(t_map));
	ft_init_struct_t_map(output);
	if (!output)
	{
		free(read_file_result);
		exit(ft_error_malloc("ft_read_input_map", "output", sizeof(t_map)));
	}
	ft_create_map_array(read_file_result, output);
	return (output);
}

static void	ft_init_struct_t_map(t_map *var)
{
	var->resolution.width = WIDTH;
	var->resolution.height = HEIGHT;
}
