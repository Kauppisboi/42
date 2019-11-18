/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:18:52 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 17:35:41 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c_to_appnd;
	size_t	dst_lngth;
	size_t	src_lngth;

	dst_lngth = ft_strlen(dst);
	src_lngth = ft_strlen(src);
	c_to_appnd = dstsize - dst_lngth - 1;
	if (dstsize < dst_lngth || dstsize - dst_lngth == 0)
		return (dstsize + src_lngth);
	ft_strncpy(&dst[dst_lngth], src, c_to_appnd);
	dst[dst_lngth + c_to_appnd] = '\0';
	return (dst_lngth + src_lngth);
}
