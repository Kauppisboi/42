/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:22:48 by jrignell          #+#    #+#             */
/*   Updated: 2019/10/20 12:38:01 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s1[i] != '\0')
		++i;
	j = 0;
	while (s2[j] != '\0' && (size_t)j < n)
	{
		s1[i + j] = s2[j];
		++j;
	}
	s1[i + j] = '\0';
	return (s1);
}
