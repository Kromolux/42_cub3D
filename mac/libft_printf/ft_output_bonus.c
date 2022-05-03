/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:02:46 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 17:13:18 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_write_string(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (flags->conversion == 'c')
	{
		if (i == 0)
			i = 1;
		if (i < flags->left_aligned)
			i = flags->left_aligned;
		if (i < flags->right_aligned)
			i = flags->right_aligned;
	}
	write(1, s, i);
	free(flags);
	free(s);
	return (i);
}
