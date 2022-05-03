/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 07:11:08 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 13:42:43 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

int	ft_check_hex(const char *input)
{
	int	i;

	if (ft_strcmp(",0x", input) != 0)
		return (0);
	i = 3;
	while (input[i])
	{
		if ((input[i] < '0' && input[i] > '9')
			&& (input[i] < 'a' && input[i] > 'f')
			&& (input[i] < 'A' && input[i] > 'F'))
			return (0);
		i++;
	}
	return (1);
}
