/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:18:46 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/29 08:39:43 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	unsigned int	i;
	char			*new_s;

	if (!s)
		return (NULL);
	if (!(new_s = ft_strnew(ft_strlen(s))))
		return (new_s);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(s[i]);
		i++;
	}
	return (new_s);
}
