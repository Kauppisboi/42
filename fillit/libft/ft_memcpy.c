/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:23:53 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/29 09:59:01 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*byte_str1;
	unsigned char	*byte_str2;

	if (!dst && !src)
		return (dst);
	byte_str1 = (unsigned char*)dst;
	byte_str2 = (unsigned char*)src;
	i = 0;
	while (n > 0)
	{
		byte_str1[i] = byte_str2[i];
		i++;
		n--;
	}
	return (dst);
}
