/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:45:17 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 12:08:39 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

static void		ft_create_substrings(char const *s, char c, char **array);

char	**ft_split(char const *s, const char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **) malloc((ft_words_in_str(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	ft_create_substrings(s, c, array);
	return (array);
}

static void	ft_create_substrings(char const *s, const char c, char **array)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			array[word_count] = ft_get_substring(s, 0, i);
			word_count++;
			s += i;
		}
	}
	array[word_count] = NULL;
}
