/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:45:58 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 14:08:56 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	start_pos;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			start_pos = i;
			while (haystack[i] == needle[j] && needle[j] && i < len)
			{
				i++;
				j++;
			}
			if (!needle[j])
				return ((char*)&haystack[start_pos]);
			i = start_pos;
		}
		i++;
	}
	return (NULL);
}
