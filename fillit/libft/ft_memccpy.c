/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:32:11 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 18:36:33 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*byte_str1;
	unsigned char	*byte_str2;

	byte_str1 = (unsigned char*)dst;
	byte_str2 = (unsigned char*)src;
	i = 0;
	while (n > 0)
	{
		if (byte_str2[i] == (unsigned char)c)
		{
			byte_str1[i] = byte_str2[i];
			return (&byte_str1[i + 1]);
		}
		byte_str1[i] = byte_str2[i];
		i++;
		n--;
	}
	return (NULL);
}
