/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:19:37 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/29 10:18:45 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (!(sub_s = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (len)
	{
		sub_s[i++] = s[start++];
		len--;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
