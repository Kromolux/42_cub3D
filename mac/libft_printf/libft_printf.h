/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:03:44 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/08 16:45:56 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# ifdef __linux__
#  define LINUX 1
# else
#  define LINUX 0
# endif
# include "../libft_tools/libft_tools.h"

typedef struct s_flags
{
	int		left_aligned;
	int		right_aligned;
	int		leading_zeros;
	int		precision;
	int		leading_zeros_x;
	int		leading_whitespace;
	int		leading_plus;
	char	conversion;
}				t_flags;

//ft_printf_bonus.c
int		ft_printf(const char *s, ...);

//ft_sprintf_bonus.c
char	*ft_sprintf(const char *s, ...);

//ft_init_flags_bonus.c
t_flags	*ft_initialize_flags(void);

//ft_read_flags_bonus.c
t_flags	*ft_read_flags(const char *s, int *i);

//ft_apply_flags_bonus.c
char	*ft_apply_flags(char *s, t_flags *flags);

//ft_apply_precision_bonus.c
char	*ft_apply_precision(char *s, t_flags *flags);

//ft_conversation0.c
char	*ft_read_conversation(const char *s, va_list *args);

//ft_conversation1.c
char	*ft_read_char(va_list *args);
char	*ft_read_string(va_list *args);
char	*ft_read_pointer(va_list *args);

//ft_output_bonus.c
int		ft_write_char(char c);
int		ft_write_string(char *s, t_flags *flags);

//ft_hex.c
char	*ft_read_hex(va_list *args, char c);
void	ft_create_hex_string(char *output, char *input, int n,
			int leading_zeros);

//ft_additional_tools_bonus.c
void	*ft_malloc_and_zero_mem(size_t size);
char	*ft_create_zero_x(char c, char *input);
char	*ft_add_char(char c, size_t count);

#endif