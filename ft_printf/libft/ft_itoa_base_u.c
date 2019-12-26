/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:56:26 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/22 14:42:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_u(unsigned long long int value, int base, int upper)
{
	unsigned long long	n;
	int					sign;
	int					i;
	char				*str;

	upper = (upper == 1) ? 'A' : 'a'; 
	n = value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((value /= base) >= 1)
		i++;
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