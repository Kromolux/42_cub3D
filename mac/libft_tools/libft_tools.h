/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:12:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 11:09:05 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TOOLS_H
# define LIBFT_TOOLS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16384
# endif

//string evaluations
size_t	ft_strlen(const char *s);
char	*ft_char_in_str(const char *s, const char c);
int		ft_char_first(const char *s, const char c, size_t size);
size_t	ft_words_in_str(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_count_of_in_str(const char *s, const char c);
int		ft_check_hex(const char *input);

//string manipulations
size_t	ft_replace_in_string(char *s, char c_replace, char c_with);
char	*ft_get_substring(char const *s, size_t start, size_t len);
char	**ft_split(char const *s, const char c);
char	*ft_string_dup(const char *s);
char	*ft_string_dup_skip_white(const char *s);

//string copy all size == 0 || number of size
size_t	ft_copy(char *dst, char *src, size_t size);

//numbers
char	*ft_int_to_string(long n);
long	ft_string_to_int(const char *nptr);
int		ft_string_to_hex(char *input);

//memory reallocation and string copy + memory free
char	*ft_realloc(char *s1, char *s2, int free_s1, int free_s2);
void	*ft_calloc(size_t size);
void	*ft_calloc_char(size_t size, char c);

//char array
void	ft_free_char_array(char **array);

//reading from a file descriptor till '\n'
char	*ft_get_next_line(int fd);

//reading from a file descriptor till EOF
char	*ft_read_file(int fd);

//mem
void	*ft_memset(void *s, int c, size_t n);
void	ft_free(void *ptr);

#endif