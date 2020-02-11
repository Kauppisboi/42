/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:34:35 by jrignell          #+#    #+#             */
/*   Updated: 2019/10/26 13:38:46 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_copy(void const *content, size_t content_size)
{
	unsigned char	*ptr;
	unsigned char	*ptr1;
	void			*new;

	if (!(new = ft_memalloc(content_size)))
		return (NULL);
	ptr = (unsigned char*)content;
	ptr1 = (unsigned char*)new;
	while (*ptr)
		*ptr1++ = *ptr++;
	return (new);
}
