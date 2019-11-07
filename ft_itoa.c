/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:46:53 by jrignell          #+#    #+#             */
/*   Updated: 2019/10/26 12:52:15 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	array_len(int n)
{
	if (n < 0)
		return (array_len(n * -1) + 1);
	if (n < 10 && n >= 0)
		return (1);
	else if (n >= 10)
		return (array_len(n / 10) + 1);
	return (0);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	size_t	sign;

	if (n == -2147483648)
		return (ft_strcpy(ft_strnew(11), "-2147483648"));
	if (!(str = ft_strnew(array_len(n))))
		return (NULL);
	sign = (n < 0) ? 1 : 0;
	len = array_len(n);
	str[len] = '\0';
	n = (n < 0) ? n * -1 : n;
	while (len-- > sign)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
