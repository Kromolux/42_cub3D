/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 07:06:51 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 17:13:40 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static int		ft_read_number(const char *s, int *i);
static int		ft_set_flag(int *flag, int value);
static void		ft_read_width(const char *s, int *i, t_flags *flags);
static t_flags	*ft_conversion_flag(const char *s, int *i, t_flags *flags);

t_flags	*ft_read_flags(const char *s, int *i)
{
	t_flags	*flags;

	flags = ft_initialize_flags();
	while (1)
	{
		if (s[*i] == '-')
			flags->left_aligned = ft_read_number(s, i);
		else if (s[*i] == '0')
			(*i) += ft_set_flag(&flags->leading_zeros, 1);
		else if (s[*i] == '.')
			flags->precision = ft_read_number(s, i);
		else if (s[*i] == '#')
			(*i) += ft_set_flag(&flags->leading_zeros_x, 1);
		else if (s[*i] == ' ')
			(*i) += ft_set_flag(&flags->leading_whitespace, 1);
		else if (s[*i] == '+')
			(*i) += ft_set_flag(&flags->leading_plus, 1);
		else if (s[*i] >= '1' && s[*i] <= '9')
			ft_read_width(s, i, flags);
		else if (ft_char_in_str("cspdiuxX%%", s[*i]) != NULL)
			return (ft_conversion_flag(s, i, flags));
	}
	return (flags);
}

static int	ft_read_number(const char *s, int *i)
{
	int	count_of_numbers;

	if (s[*i] == '-' || s[*i] == '.')
		(*i)++;
	count_of_numbers = ft_string_to_int(&s[*i]);
	while (s[*i] >= '0' && s[*i] <= '9')
		(*i)++;
	return (count_of_numbers);
}

static int	ft_set_flag(int *flag, int value)
{
	*flag = value;
	return (1);
}

static void	ft_read_width(const char *s, int *i, t_flags *flags)
{
	if (flags->left_aligned == -1)
		flags->right_aligned = ft_read_number(s, i);
	else
		flags->left_aligned = ft_read_number(s, i);
}

static t_flags	*ft_conversion_flag(const char *s, int *i, t_flags *flags)
{
	flags->conversion = s[*i];
	return (flags);
}
