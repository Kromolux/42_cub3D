/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:24:56 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 11:45:33 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_error_map_file(char **s, int row, t_map *map)
{
	ft_printf("Error\nInvalid identifier [%s] in map %i .cub file by"
		" function ft_check_input_exit_on_error\n", s[row], row);
	ft_free_map(map);
	ft_free_char_array(s);
	return (RETURN_ERROR);
}
