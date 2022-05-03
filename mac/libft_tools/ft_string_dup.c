/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:37:23 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/28 11:43:36 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

char	*ft_string_dup(const char *s)
{
	char	*output;

	output = (char *) malloc(ft_strlen(s) + 1);
	if (!output)
		return (NULL);
	ft_copy(output, (char *)s, 0);
	return (output);
}

char	*ft_string_dup_skip_white(const char *s)
{
	char	*output;

	while (*s == ' ' || *s == '.' || *s == '/')
		s++;
	output = (char *) malloc(ft_strlen(s) + 1);
	if (!output)
		return (NULL);
	ft_copy(output, (char *)s, 0);
	return (output);
}
