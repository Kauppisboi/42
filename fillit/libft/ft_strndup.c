/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:20:25 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/14 19:34:57 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s1);
	if (!(dup = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_memcpy(dup, s1, n);
	dup[n] = '\0';
	return (dup);
}
