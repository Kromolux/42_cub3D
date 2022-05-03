/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:49:54 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 11:32:52 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_valid_number(char *argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
		{
			if (argv[i] == ',' && ft_check_hex(&argv[i]))
				break ;
			else if (argv[i] != '+' && argv[i] != '-')
				return (0);
		}
		i++;
	}
	if (!ft_check_number(argv))
		return (0);
	return (1);
}

int	ft_check_number(char *s)
{
	long	value;

	if (s[0] < '0' || s[0] > '9')
	{
		if ((s[0] != '+' && s[0] != '-') || s[1] < '0' || s[1] > '9')
			return (0);
	}
	value = ft_string_to_int(s);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	return (1);
}

int	ft_check_number_rgb(char *s)
{
	int	value;
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (RETURN_ERROR);
		i++;
	}
	value = ft_string_to_int(s);
	if (value > 255 || value < 0)
		return (RETURN_ERROR);
	return (value);
}
