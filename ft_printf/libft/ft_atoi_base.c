/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:32:20 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/02 17:45:23 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isbase(char c, int base)
{
	char	*str;
	char	*str2;

	str = "012345679abcdef";
	str2 = "012345679ABCDEF";
	while (base--)
	{
		if (str[base] == c || str2[base] == c)
			return (1);
	}
	return (0);
}

static int	ft_right_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		sign;
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (ft_isbase(str[i], str_base) && str[i])
		res = res * str_base + ft_right_value(str[i++]);
	return (res * sign);
}
