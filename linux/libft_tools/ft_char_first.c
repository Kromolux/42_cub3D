/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:38:50 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 15:50:27 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

int	ft_char_first(const char *s, const char c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}
