/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:29:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/01 08:54:46 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static char	*ft_sprintf_handling(const char *s, int *i, va_list *args);

char	*ft_sprintf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		i_start;
	char	*output;

	i = 0;
	i_start = 0;
	va_start(args, s);
	output = (char *) ft_calloc(1);
	while (s[i])
	{
		if (s[i] == '%')
			output = ft_realloc(output, ft_sprintf_handling(s, &i, &args),
					1, 1);
		else
		{
			i_start = i;
			while (s[i] && s[i] != '%')
				i++;
			output = ft_realloc(output, ft_get_substring(s, i_start,
						i - i_start), 1, 1);
		}
	}
	va_end(args);
	return (output);
}

static char	*ft_sprintf_handling(const char *s, int *i, va_list *args)
{
	t_flags	*flags;
	char	*tmp_string;

	(*i)++;
	flags = ft_read_flags(s, i);
	tmp_string = ft_read_conversation(&s[*i], args);
	tmp_string = ft_apply_flags(tmp_string, flags);
	free(flags);
	(*i)++;
	return (tmp_string);
}
