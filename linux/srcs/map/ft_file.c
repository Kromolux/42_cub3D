/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:47:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/28 19:01:35 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_init_struct_t_map(t_map *var);
static void	ft_exit_malloc_error(char *s);

t_map	*ft_read_input_map(char *file)
{
	t_map	*output;
	int		fd;
	char	*read_file_result;

	if (!ft_strcmp(&file[ft_strlen(file) - 4], ".cub"))
		exit(ft_error_extension(file));
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
		ft_exit_malloc_error(read_file_result);
	ft_create_map_array(read_file_result, output);
	return (output);
}

static void	ft_init_struct_t_map(t_map *map)
{
	map->tile_size = 32;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->texture_no = NULL;
	map->texture_so = NULL;
	map->texture_we = NULL;
	map->texture_ea = NULL;
}

static void	ft_exit_malloc_error(char *s)
{
	free(s);
	exit(ft_error_malloc("ft_read_input_map", "output", sizeof(t_map)));
}
