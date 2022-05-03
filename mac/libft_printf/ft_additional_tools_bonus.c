/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_tools_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:12:55 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 17:15:06 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	*ft_malloc_and_zero_mem(size_t size)
{
	size_t	i;
	void	*output;

	i = 0;
	output = malloc(sizeof(char) * (size));
	if (!output)
		return (NULL);
	while (i < size)
	{
		((char *) output)[i] = '\0';
		i++;
	}
	return (output);
}

char	*ft_create_zero_x(char c, char *input)
{
	char	*output;

	output = (char *) malloc(sizeof(char) * 3);
	if (!output)
		return (NULL);
	output[0] = '0';
	output[1] = c;
	output[2] = '\0';
	free(input);
	return (output);
}

char	*ft_add_char(char c, size_t count)
{
	char	*output;
	size_t	i;

	i = 0;
	output = (char *) malloc(sizeof(char) * count + 1);
	if (!output)
		return (NULL);
	while (i < count)
	{
		output[i] = c;
		i++;
	}
	output[i] = '\0';
	return (output);
}
