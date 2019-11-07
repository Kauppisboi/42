/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:54:02 by jrignell          #+#    #+#             */
/*   Updated: 2019/10/28 13:39:43 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*join;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		join[i + j] = s2[j];
		++j;
	}
	return (join);
}
