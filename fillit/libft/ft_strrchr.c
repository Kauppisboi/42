/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:51:09 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 14:08:01 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	s_lngth;
	char	chr;

	chr = (char)c;
	s_lngth = ft_strlen(s);
	i = s_lngth;
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char*)&s[i]);
		else if (i == 0)
			return (NULL);
		i--;
	}
	return (NULL);
}
