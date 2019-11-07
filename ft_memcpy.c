/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:29:23 by jrignell          #+#    #+#             */
/*   Updated: 2019/10/28 20:14:47 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dst == src)
		return (dst);
	d = (char*)dst;
	s = (char*)src;
	while (n--)
		*(d++) = *(s++);
	return (dst);
}
