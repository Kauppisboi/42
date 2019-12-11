/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:53:01 by jrignell          #+#    #+#             */
/*   Updated: 2019/10/24 12:38:03 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	size_t	i;

	if (!s || !(fresh = ft_memalloc(ft_strlen((const char*)s) + 1)))
		return (NULL);
	i = 0;
	while (s[i] && f)
	{
		fresh[i] = f(i, s[i]);
		++i;
	}
	return (fresh);
}
