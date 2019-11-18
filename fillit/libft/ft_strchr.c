/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:06:03 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 14:07:44 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_lngth;
	char	chr;

	chr = (char)c;
	s_lngth = ft_strlen(s);
	i = 0;
	while (i <= s_lngth)
	{
		if (s[i] == chr)
		{
			return ((char*)&s[i]);
		}
		i++;
	}
	return (NULL);
}
