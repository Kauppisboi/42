/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:08:49 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 13:55:59 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*byte_str;
	size_t			i;

	i = 0;
	byte_str = (unsigned char*)s;
	while (n > 0)
	{
		if (byte_str[i] == (unsigned char)c)
			return (&byte_str[i]);
		i++;
		n--;
	}
	return (NULL);
}
