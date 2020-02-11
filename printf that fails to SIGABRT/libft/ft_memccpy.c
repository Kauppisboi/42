/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:09:24 by jrignell          #+#    #+#             */
/*   Updated: 2019/10/28 18:36:27 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (!n)
		return (0);
	while (n-- > 0)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		if ((unsigned char)c == *(unsigned char*)src)
			return (++dst);
		dst++;
		src++;
	}
	return (NULL);
}
