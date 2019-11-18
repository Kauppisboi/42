/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:01:41 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/29 08:33:25 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*byte_str1;
	unsigned char	*byte_str2;
	size_t			i;

	byte_str1 = (unsigned char*)s1;
	byte_str2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (byte_str1[i] != byte_str2[i])
			return (byte_str1[i] - byte_str2[i]);
		i++;
	}
	return (0);
}
