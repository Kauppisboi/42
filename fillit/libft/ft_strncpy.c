/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:08:34 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 14:01:56 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	src_lngth;

	i = 0;
	src_lngth = ft_strlen(src);
	while (len)
	{
		if (i < src_lngth)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
		len--;
	}
	return (dst);
}
