/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:20:17 by jrignell          #+#    #+#             */
/*   Updated: 2019/10/19 17:06:14 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!*needle)
		return ((char*)haystack);
	i = 0;
	while (haystack[i] != '\0' && (size_t)i < len)
	{
		if (needle[0] == haystack[i])
		{
			j = 1;
			while (haystack[i + j] == needle[j] && needle[j] != '\0' &&
				(size_t)(i + j) < len)
				++j;
			if (needle[j] == '\0')
				return ((char*)&haystack[i]);
		}
		++i;
	}
	return (0);
}
