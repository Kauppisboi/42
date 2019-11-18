/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:39:12 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/24 12:06:23 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*create_str(const char *s, char c)
{
	size_t	i;
	char	*new_str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(new_str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strncpy(new_str, s, i);
	new_str[i] = '\0';
	return (new_str);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	ctr;

	i = 0;
	ctr = 0;
	if (!s)
		return (0);
	if (s[i++] != c)
		ctr++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			ctr++;
		i++;
	}
	return (ctr);
}

static int		create_str_arr(const char *s, char **str_arr, char c, \
	size_t wrds)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s[i] != c && s[i])
	{
		str_arr[j++] = create_str(s, c);
		wrds--;
		i++;
	}
	while (wrds != 0)
	{
		if (s[i - 1] == c && s[i] != c)
		{
			str_arr[j++] = create_str(&s[i], c);
			if (str_arr[j - 1] == NULL)
				return (0);
			wrds--;
		}
		i++;
	}
	str_arr[j] = 0;
	return (1);
}

static void		ft_free_strings(char **str_arr)
{
	size_t	i;

	i = 0;
	while (str_arr[i] != NULL)
	{
		ft_strdel(&str_arr[i++]);
	}
	ft_memdel((void*)str_arr);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	word_count;
	char	**str_arr;

	word_count = ft_count_words(s, c);
	if (!(str_arr = (char**)malloc(sizeof(char*) * word_count + 1)))
		return (NULL);
	if (create_str_arr(s, str_arr, c, word_count) == 0)
		ft_free_strings(str_arr);
	return (str_arr);
}
