/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 06:46:08 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/01 08:52:54 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

int	ft_string_to_hex(char *input)
{
	int	i;
	int	output;
	int	byte;

	i = 0;
	output = 0x0;
	while (input[i] && input[i] != 'x')
		i++;
	i++;
	while (input[i])
	{
		if (input[i] >= '0' && input[i] <= '9')
			byte = input[i] - '0';
		else if (input[i] >= 'a' && input[i] <= 'f')
			byte = input[i] - 87;
		else if (input[i] >= 'A' && input[i] <= 'F')
			byte = input[i] - 55;
		else
			byte = 0;
		output = (output << 4) | byte;
		i++;
	}
	return (output);
}
