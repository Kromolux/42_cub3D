/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:57:18 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 17:13:29 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static int	ft_printf_handling(const char *s, int *i, va_list *args);

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count_of_chars;

	i = 0;
	count_of_chars = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			count_of_chars += ft_printf_handling(s, &i, &args);
		else
			count_of_chars += ft_write_char((char) s[i]);
		i++;
	}
	va_end(args);
	return (count_of_chars);
}

static int	ft_printf_handling(const char *s, int *i, va_list *args)
{
	t_flags	*flags;
	char	*tmp_string;

	(*i)++;
	flags = ft_read_flags(s, i);
	tmp_string = ft_read_conversation(&s[*i], args);
	if (tmp_string)
	{
		tmp_string = ft_apply_flags(tmp_string, flags);
		return (ft_write_string(tmp_string, flags));
	}
	return (0);
}
