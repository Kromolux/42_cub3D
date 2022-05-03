/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input_map1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:04:45 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 08:37:07 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

size_t	ft_count_of_columns(char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	max;

	i = 0;
	max = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (count > max)
				max = count;
			count = 0;
			i++;
			continue ;
		}
		i++;
		count++;
	}
	return (max);
}

int	ft_is_empty_space(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (RETURN_TRUE);
	return (RETURN_FALSE);
}

int	ft_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (RETURN_TRUE);
	return (RETURN_FALSE);
}

int	ft_valid_char(char *argv, int row)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != '1' && ft_is_empty_space(argv[i]) != RETURN_TRUE
			&& argv[i] != ' ')
			return (ft_error_char(argv[i], row));
		i++;
	}
	return (RETURN_TRUE);
}
