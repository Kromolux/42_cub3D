/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:57:19 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 17:13:42 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	ft_convert_to_hex(char *output, char c);

char	*ft_read_hex(va_list *args, char c)
{
	char			*tmp_string;
	unsigned int	tmp_ui;
	char			*ptr;
	int				i;

	tmp_string = (char *) malloc(sizeof(char) * 9);
	if (!tmp_string)
		return (NULL);
	tmp_ui = (unsigned int) va_arg(*args, unsigned int);
	ptr = (char *) &tmp_ui;
	ft_create_hex_string(tmp_string, ptr, 4, 0);
	if (c == 'X')
	{
		i = 0;
		while (tmp_string[i])
		{
			if (tmp_string[i] >= 'a' && tmp_string[i] <= 'f')
				tmp_string[i] -= 32;
			i++;
		}
	}
	return (tmp_string);
}

void	ft_create_hex_string(char *output, char *input, int n,
			int leading_zeros)
{
	int		i;

	i = 0;
	n--;
	if (leading_zeros == 0)
	{
		while (input[n] == (char) 0 && n > 0)
			n--;
		ft_convert_to_hex(output, input[n]);
		if (output[0] == '0')
		{
			output[0] = output[1];
			i++;
			n--;
		}
	}
	while (n >= 0)
	{
		ft_convert_to_hex(&output[i], input[n]);
		i += 2;
		n--;
	}
	output[i] = '\0';
}

static void	ft_convert_to_hex(char *output, char c)
{
	char	*hex_mask;

	hex_mask = "0123456789abcdef";
	output[0] = hex_mask[(c >> 4) & 15];
	output[1] = hex_mask[c & 15];
}
