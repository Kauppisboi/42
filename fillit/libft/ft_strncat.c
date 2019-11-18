/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:45:11 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/29 09:40:53 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1_size;
	size_t	i;

	s1_size = ft_strlen(s1);
	i = 0;
	while (n && s2[i])
	{
		s1[i + s1_size] = s2[i];
		i++;
		n--;
	}
	s1[i + s1_size] = '\0';
	return (s1);
}
