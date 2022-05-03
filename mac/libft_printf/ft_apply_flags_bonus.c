/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:24:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/01 08:51:46 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static char	*ft_apply_right_aligned(char *prefix, char *s, t_flags *flags);
static char	*ft_apply_left_aligned(char *prefix, char *s, t_flags *flags);
static char	*ft_create_prefix(char *prefix, char *s, t_flags *flags,
				size_t len);

char	*ft_apply_flags(char *s, t_flags *flags)
{
	char	*prefix;
	char	c;

	c = flags->conversion;
	prefix = (char *) ft_malloc_and_zero_mem(sizeof(char) * 2);
	if (!prefix)
		return (NULL);
	if (flags->leading_zeros_x == 1 && (c == 'x' || c == 'X' ) && s[0] != '0')
		prefix = ft_create_zero_x(c, prefix);
	else if (flags->leading_plus == 1 && (c == 'd' || c == 'i') && s[0] != '-')
		prefix[0] = '+';
	else if (flags->leading_whitespace == 1 && (c == 'd' || c == 'i')
		&& s[0] != '-')
		prefix[0] = ' ';
	if (flags->precision >= 0)
		s = ft_apply_precision(s, flags);
	if (flags->right_aligned > 0)
		prefix = ft_apply_right_aligned(prefix, s, flags);
	if (flags->left_aligned > 0)
		s = ft_apply_left_aligned(prefix, s, flags);
	if (c != 'c' || (c == 'c' && flags->right_aligned > 0))
		s = ft_realloc(prefix, s, 0, 1);
	free(prefix);
	return (s);
}

static char	*ft_apply_right_aligned(char *prefix, char *s, t_flags *flags)
{
	int	len;

	len = (int) ft_strlen(s);
	if (flags->conversion == 'c' && len == 0)
		len = 1;
	len += (int) ft_strlen(prefix);
	if (ft_char_in_str("cspdiuxX", flags->conversion)
		&& len < flags->right_aligned)
		prefix = ft_create_prefix(prefix, s, flags, len);
	return (prefix);
}

static char	*ft_create_prefix(char *prefix, char *s, t_flags *flags, size_t len)
{
	char	*tmp1;
	char	c;

	if (flags->leading_zeros == 1 && flags->precision < 0)
		c = '0';
	else
		c = ' ';
	if (prefix[1] == 'x' || prefix[1] == 'X')
	{
		tmp1 = ft_add_char(c, flags->right_aligned - len);
		prefix = ft_realloc(prefix, tmp1, 1, 1);
	}
	else
	{
		tmp1 = ft_add_char(c, flags->right_aligned - len);
		prefix = ft_realloc(tmp1, prefix, 1, 1);
		if (ft_char_in_str("di", flags->conversion) && flags->leading_zeros == 1
			&& flags->precision < 0 && (s[0] == '-' || s[0] == '+'))
		{
			prefix[0] = s[0];
			s[0] = '0';
		}
	}
	return (prefix);
}

static char	*ft_apply_left_aligned(char *prefix, char *s, t_flags *flags)
{
	int		len;
	char	*tmp1;
	char	*tmp2;

	len = (int) ft_strlen(s);
	if (flags->conversion == 'c' && len == 0)
		len = 1;
	len += (int) ft_strlen(prefix);
	if (ft_char_in_str("cspdiuxX", flags->conversion)
		&& len <= flags->left_aligned)
	{
		tmp1 = ft_add_char(' ', flags->left_aligned - len);
		if (flags->conversion == 'c' && s[0] == '\0')
		{
			tmp2 = (char *) ft_calloc(flags->left_aligned + 1);
			ft_copy(&tmp2[1], tmp1, 0);
		}
		else
			tmp2 = ft_realloc(s, tmp1, 0, 0);
		free(tmp1);
		free(s);
		s = tmp2;
	}
	return (s);
}
