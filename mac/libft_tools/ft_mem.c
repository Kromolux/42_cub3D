/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:18:15 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 11:08:51 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*ptr;
	unsigned char		value;
	size_t				i;

	if (n > 0)
	{
		i = 0;
		ptr = (unsigned char *) s;
		value = (unsigned char) c;
		while (i < n)
		{
			*ptr = value;
			ptr++;
			i++;
		}
	}
	return (s);
}

void	ft_free(void *ptr)
{
	if (ptr)
		free((void *) ptr);
	ptr = NULL;
}
