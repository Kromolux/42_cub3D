/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_substring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:44:09 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/01 08:54:04 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

char	*ft_get_substring(char const *s, size_t start, size_t len)
{
	char	*substring;

	if (!s)
		return (NULL);
	substring = (char *) malloc(len + 1);
	if (!substring)
		return (NULL);
	ft_copy(substring, (char *) &s[start], len + 1);
	return (substring);
}
