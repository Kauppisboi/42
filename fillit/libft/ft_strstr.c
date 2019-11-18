/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:19:28 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 14:08:19 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	start_pos;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			start_pos = i;
			while (haystack[i] == needle[j] && needle[j])
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
