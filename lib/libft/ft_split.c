/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:51 by johartma          #+#    #+#             */
/*   Updated: 2024/11/27 17:49:38 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*extract_word(const char *s, char c, size_t *len)
{
	size_t	word_len;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	*len = word_len;
	return (ft_substr(s, 0, word_len));
}

static void	free_split(char **arr_strs, size_t words_allocated)
{
	size_t	i;

	i = 0;
	while (i < words_allocated)
	{
		free(arr_strs[i]);
		i++;
	}
	free(arr_strs);
}

static int	fill_words(char **arr_strs, const char *s, char c)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			arr_strs[i] = extract_word(s, c, &word_len);
			if (!arr_strs[i])
			{
				free_split(arr_strs, i);
				return (-1);
			}
			i++;
			s += word_len;
		}
		else
			s++;
	}
	arr_strs[i] = NULL;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**arr_strs;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	arr_strs = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!arr_strs)
		return (NULL);
	if (fill_words(arr_strs, s, c) == -1)
		return (NULL);
	return (arr_strs);
}
