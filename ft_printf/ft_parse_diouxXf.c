/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_diouxXf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:32:49 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/27 11:41:40 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*helper_for_check_prev(char *sub_str, unsigned long long printable,
								unsigned len, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_itoa_base_u(ft_parse_hh_h_ll_l_u(sub_str, printable, len),
			16, (c == 'X') ? 1 : 0));
	else if (c == 'o')
		return (ft_itoa_base_u(ft_parse_hh_h_ll_l_u(sub_str, printable, len),
			8, 0));
	else if (c == 'u')
		return (ft_itoa_base_u(ft_parse_hh_h_ll_l_u(sub_str, printable, len),
			10, 0));
	return (0);
}

static int	ft_check_previous_u(char *sub_str, unsigned long long printable,
								unsigned len, char c)
{
	int		upper;
	char	*str;

	upper = 0;
	str = NULL;
	if (sub_str[len] == '%' && c == 'o' )
		str = ft_itoa_base((long long)printable, 8, 0);
	else if (sub_str[len] == '%' && (c == 'x' || c == 'X'))
	{
		upper = (c == 'X') ? 1 : 0;
		str = ft_itoa_base_u(printable, 16, upper);
	}
	else if (sub_str[len] == '%' && c == 'u')
		str = ft_itoa_base_u(printable, 10, 0);
	else if ((sub_str[len] == 'h' || sub_str[len] == 'l') && (c == 'x' ||
				c == 'X' || c == 'o' || c == 'u'))
		str = helper_for_check_prev(sub_str, printable, len, c);
	ft_putstr(str);
	return (ft_strlen(str));
}

static int	ft_check_previous(char *sub_str, long long printable,
								unsigned len, char c)
{	char	*str;

	str = NULL;
	if (sub_str[len] == '%' && c == 'd')
		str = ft_itoa_base(printable, 10, 0);
	else if ((sub_str[len] == 'h' || sub_str[len] == 'l') && c == 'd')
		str = ft_itoa_base(ft_parse_hh_h_ll_l(sub_str, printable, len), 10, 0);
	ft_putstr(str);
	return (ft_strlen(str));
}

static int	ft_parse_xX(char *sub_str, va_list ap, unsigned len)
{
	unsigned long long	printable;
	char				x;

	x = sub_str[len];
	printable = va_arg(ap, unsigned long long);
	return (ft_check_previous_u(sub_str, printable, --len, x));
}

int			ft_parse_diouxXf(char *sub_str, va_list ap, unsigned int len)
{
	long long int		printable_ll;
	unsigned long long	printable_ull;

	printable_ll = 0;
	printable_ull = 0;
	if (sub_str[len] == 'd' || sub_str[len] == 'i')
	{

		printable_ll = va_arg(ap, long long);
		return (ft_check_previous(sub_str, printable_ll, --len, 'd'));
	}
	else if (sub_str[len] == 'o')
	{
		printable_ll = va_arg(ap, unsigned long long);
		return (ft_check_previous_u(sub_str, printable_ull, --len, 'o'));
	}
	else if (sub_str[len] == 'u')
	{
		printable_ull = va_arg(ap, unsigned long long);
		return (ft_check_previous_u(sub_str, printable_ull, --len, 'u'));
	}
	else if (sub_str[len] == 'x' || sub_str[len] == 'X')
		return (ft_parse_xX(sub_str, ap, len));
	else if (sub_str[len] == 'f')
		return (0);
	return (0);
}