/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 09:22:31 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 19:04:07 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*byte_str1;
	unsigned char	*byte_str2;
	size_t			i;

	if (!dst && !src)
		return (dst);
	byte_str1 = (unsigned char*)src;
	byte_str2 = (unsigned char*)dst;
	i = len;
	if (byte_str1 < byte_str2)
		while (i--)
			byte_str2[i] = byte_str1[i];
	else if (byte_str1 > byte_str2)
		ft_memcpy(dst, src, len);
	return (dst);
}
