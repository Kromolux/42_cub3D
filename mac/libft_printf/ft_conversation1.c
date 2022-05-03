/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversation1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 09:25:12 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 17:12:41 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

char	*ft_read_char(va_list *args)
{
	char	*tmp_string;

	tmp_string = (char *) malloc(sizeof(char) * 2);
	if (!tmp_string)
		return (NULL);
	tmp_string[0] = (char)((int) va_arg(*args, int));
	tmp_string[1] = '\0';
	return (tmp_string);
}

char	*ft_read_string(va_list *args)
{
	char	*tmp_string;
	char	*ptr;
	size_t	args_len;

	ptr = (char *) va_arg(*args, char *);
	if (!ptr)
	{
		args_len = 7;
		ptr = "(null)";
	}
	else
		args_len = ft_strlen(ptr) + 1;
	tmp_string = (char *) malloc(args_len);
	if (!tmp_string)
		return (NULL);
	ft_copy(tmp_string, ptr, args_len);
	return (tmp_string);
}

char	*ft_read_pointer(va_list *args)
{
	char				*tmp_string;
	unsigned long long	memory_address;
	char				*ptr;

	tmp_string = (char *) malloc(sizeof(char) * 19);
	if (!tmp_string)
		return (NULL);
	memory_address = va_arg(*args, unsigned long long);
	if (!memory_address && LINUX)
	{
		ft_copy(tmp_string, "(nil)", 0);
	}
	else
	{
		ptr = (char *) &memory_address;
		tmp_string[0] = '0';
		tmp_string[1] = 'x';
		ft_create_hex_string(&tmp_string[2], ptr, 8, 0);
	}
	return (tmp_string);
}
