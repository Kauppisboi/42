/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:51:07 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/02 17:44:58 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char	*ft_itoa_base(long long int value, int base, int upper)
{
	long long	n;
	int			sign;
	int			i;
	char		*str;

	upper = (upper == 1) ? 'A' : 'a';
	if (value == LONG_MIN)
		return (ft_strcpy(ft_strnew(21), "-9223372036854775808"));
	n = (value < 0) ? -value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	n = (value < 0) ? -value : value;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i-- + sign)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + upper - 10;
		n /= base;
	}
	str[i] = (i == 0) ? '-' : 0;
	return (str);
}
