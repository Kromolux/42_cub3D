/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:49:54 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 11:47:33 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static int	ft_check_number(char *s);

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
			continue;
		}
		i++;
		count++;
	}
	return (max);
}

void	ft_check_input_exit_on_error(t_map *screen, char **input)
{
	size_t	i_row;

	i_row = 0;
	while (input[i_row])
	{
		if (!ft_valid_number(input[i_row]))
		{
			ft_printf("Error! Invalid number [%s] in .fdf file input[%i] by"
				" function ft_check_input_exit_on_error\n", input[i_row], i_row);
			free(screen);
			ft_free_char_array(input);
			exit(1);
		}
		i_row++;
	}
}

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

static int	ft_check_number(char *s)
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
