/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:56:26 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/20 16:11:45 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_u(unsigned long long int value, int base, int upper)
{
	unsigned long long	n;
	int					i;
	char				*str;

	upper = (upper == 1) ? 'A' : 'a';
	n = value;
	i = 1;
	while ((value /= base) >= 1)
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);	
	//if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
	//	return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + upper - 10;
		n /= base;
	}
	str[i] = (i == 0) ? '-' : 0;
	return (str);
}
