/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:05:02 by jrignell          #+#    #+#             */
/*   Updated: 2019/10/21 15:40:43 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;

	i = (unsigned char*)s1;
	j = (unsigned char*)s2;
	if (!(*i || *j))
		return (0);
	while (n-- > 0 && *i++ == *j++)
		;
	return ((int)(*--i - *--j));
}
