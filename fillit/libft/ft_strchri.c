/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 09:13:12 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/31 09:52:48 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tries to find character c from string s.
** Returns index of character if found, -1 otherwise.
*/

long	ft_strchri(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == (char)c)
			return (--i);
	return (-1);
}
