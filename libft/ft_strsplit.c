/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:04:52 by jrignell          #+#    #+#             */
/*   Updated: 2019/11/07 13:49:38 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s1, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s1[i] != '\0')
	{
		while (s1[i] == c && s1[i] != '\0')
			++i;
		if (s1[i] != c && s1[i] != '\0')
			++words;
		while (s1[i] != c && s1[i] != '\0')
			++i;
	}
	return (words);
}

static size_t	word_length(char const *s, char c, size_t j)
{
	size_t	len;

	len = 0;
	while (s[j] != '\0' && s[j] != c)
	{
		++len;
		++j;
	}
	if (!len)
		return (word_length(s, c, ++j));
	return (len);
}

static char		**write_chars_to_array(char const *s, char **array,
									char c, size_t j)
{
	size_t	i;
	size_t	k;
	char	*o_str;
	size_t	l;
	size_t	words;

	o_str = (char*)s;
	i = 0;
	words = count_words(s, c);
	while (i < words)
	{
		while (s[j] == c)
			++j;
		l = 0;
		k = word_length(s, c, j);
		array[i] = (char*)malloc(k + 1);
		while (k--)
			array[i][l++] = o_str[j++];
		array[i][l] = '\0';
		++i;
	}
	array[i] = 0;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	words;
	size_t	str_j;
	char	**array;

	str_j = 0;
	words = count_words(s, c);
	array = (char**)malloc((words + 1) * sizeof(char*));
	array = write_chars_to_array(s, array, c, str_j);
	return (array);
}
