/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:27:09 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/20 16:27:00 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_only_int(char *dec, long long *num, int minus)
{
	if (dec[0] >= '5' && minus)
		(*num)--;
	else if (dec[0] >= '5' && !minus)
		(*num)++;
	ft_strdel(&dec);
}

static void	ft_add_one(char *decimal, long long *num, int minus)
{
	decimal[0] = '0';
	minus ? (*num)-- : (*num)++;
}

static void	ft_round(char *decimal)
{
	size_t	len;

	len = ft_strlen(decimal) - 1;
	if (decimal[len] >= '5' && decimal[len] <= '9')
	{
		if (len == 0)
			decimal[len]++;
		else
		{
			decimal[len - 1]++;
			decimal[len] = '0';
		}
	}
	while (--len)
	{
		if (decimal[len] >= '0' && decimal[len] <= '9')
			break ;
		else if (decimal[len] == ':')
		{
			decimal[len] = '0';
			decimal[len - 1]++;
		}
	}
}

static char	*return_after_point(long double zero_point, int prec)
{
	char	*decimal;
	size_t	i;
	size_t	num;
	int		temp;

	decimal = ft_strnew(prec + 1);
	i = 0;
	num = 0;
	temp = prec;
	prec++;
	while (prec--)
	{
		zero_point *= 10;
		num = (int)zero_point;
		decimal[i++] = num + '0';
		zero_point -= num;
	}
	decimal[i] = '\0';
	ft_round(decimal);
	if (temp > 0)
		decimal[i - 1] = '\0';
	return (decimal);
}

char		*ft_lftoa(long double value, size_t precision)
{
	char		*double_str;
	char		*decimal;
	long long	num;
	int			minus;
	char		*tmp;

	num = (long int)value;
	tmp = NULL;
	minus = (value < 0) ? 1 : 0;
	value = (value >= 0) ? value - num : FT_ABS(value) - FT_ABS(num);
	decimal = return_after_point(value, precision);
	(decimal[0] == ':') ? (ft_add_one(decimal, &num, minus)) : decimal[0];
	if (precision == 0)
	{
		ft_only_int(decimal, &num, minus);
		tmp = ft_itoa_base(num, 10, 0);
		decimal = (num == 0 && minus == 1) ? ft_strjoin("-", tmp) : ft_strdup(tmp);
		ft_strdel(&tmp);
		return (decimal);
	}
	tmp = ft_itoa_base(num, 10, 0);
	double_str = ft_strjoin(tmp, ".");
	ft_strdel(&tmp);
	tmp = num == 0 && minus ? ft_strjoin("-", double_str) : ft_strdup(double_str);
	ft_strdel(&double_str);
	double_str = ft_strjoin(tmp, decimal);
	ft_strdel(&tmp);
	ft_strdel(&decimal);
	return (double_str);
}
