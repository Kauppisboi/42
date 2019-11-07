/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:42:15 by jrignell          #+#    #+#             */
/*   Updated: 2019/10/23 20:13:23 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned char	*copy;
	size_t			last_i;
	size_t			first_i;
	size_t			i;

	last_i = ft_strlen(s) - 1;
	first_i = 0;
	while (s[first_i] != '\0' && ft_isspace((int)s[first_i]))
		++first_i;
	while (last_i >= first_i && ft_isspace((int)s[last_i]))
		--last_i;
	++last_i;
	if (!(copy = ft_memalloc(last_i - first_i + 1)))
		return (NULL);
	i = 0;
	while (first_i < last_i)
		copy[i++] = s[first_i++];
	return ((char*)copy);
}
