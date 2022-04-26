/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:51 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 18:33:24 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

void	*ft_calloc(size_t size)
{
	void	*output;
	char	*tmp;
	size_t	i;

	output = malloc(size);
	if (!output)
		return (NULL);
	i = 0;
	tmp = (char *) output;
	while (i < size)
	{
		*tmp = '\0';
		tmp++;
		i++;
	}
	return (output);
}

void	*ft_calloc_char(size_t size, char c)
{
	void	*output;
	char	*tmp;
	size_t	i;

	output = malloc(size);
	if (!output)
		return (NULL);
	i = 0;
	tmp = (char *) output;
	while (i < size)
	{
		*tmp = c;
		tmp++;
		i++;
	}
	return (output);
}
