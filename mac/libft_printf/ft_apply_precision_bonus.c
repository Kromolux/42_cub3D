/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:58:53 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 13:44:20 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static char	*ft_create_precision(char *s, t_flags *flags, int s_len);
static void	ft_check_sign(char *prefix, char *s, t_flags *flags);

char	*ft_apply_precision(char *s, t_flags *flags)
{
	int		s_len;

	s_len = (int) ft_strlen(s);
	if (flags->conversion == 's')
	{
		if (LINUX && ft_strcmp(s, "(null)") == 0
			&& s_len > flags->precision)
			s[0] = '\0';
		else if (s_len >= flags->precision)
			s[flags->precision] = '\0';
	}
	else if (ft_char_in_str("diuxX", flags->conversion))
		s = ft_create_precision(s, flags, s_len);
	return (s);
}

static char	*ft_create_precision(char *s, t_flags *flags, int s_len)
{
	char	*tmp1;
	char	*prefix;
	int		offset;

	offset = 0;
	prefix = (char *) ft_malloc_and_zero_mem(2);
	if (flags->right_aligned <= flags->precision && (s[0] == '-'
			|| s[0] == '+'))
	{
		prefix[0] = s[0];
		offset = 1;
	}
	if ((s_len - offset) < flags->precision)
	{
		ft_check_sign(prefix, s, flags);
		tmp1 = ft_add_char('0', flags->precision - (s_len - offset));
		tmp1 = ft_realloc(prefix, tmp1, 0, 1);
		tmp1 = ft_realloc(tmp1, &s[offset], 1, 0);
		free(s);
		s = tmp1;
	}
	else if ((s_len - offset) == 1 && s[0] == '0' && flags->precision == 0)
		s[0] = '\0';
	free(prefix);
	return (s);
}

static void	ft_check_sign(char *prefix, char *s, t_flags *flags)
{
	if ((s[0] == '-' || s[0] == '+'))
	{
		if (flags->right_aligned > flags->precision)
			prefix[0] = s[0];
		s[0] = '0';
	}
}
