/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hh_h_ll_l.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:11:35 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/27 13:21:08 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		ft_parse_hh_h_ll_l(char *sub_str, long long printable, unsigned len)
{
	char	c;

	c = sub_str[len];
	if (sub_str[len - 1] == 'l' && c == 'l' && sub_str[len - 2] == '%')
		return (printable);
	else if (c == 'l' && sub_str[len - 1] == '%')
		return ((long)printable);
	else if (sub_str[len - 1] == 'h' && c == 'h' && sub_str[len - 2] == '%')
		return ((signed char)printable);
	else if (c == 'h' && sub_str[len - 1] == '%')
		return ((short)printable);
	else if (ft_check_if_dot(sub_str) > -1)		//something here--> this is the case when there is something else than '%' before hh,h,l,ll
		return (0);
	return 0;
}

unsigned long long	ft_parse_hh_h_ll_l_u(char *sub_str, unsigned long long printable,
								unsigned len)
{
	char	c;

	c = sub_str[len];
	if (sub_str[len - 1] == 'l' && c == 'l' && sub_str[len - 2] == '%')
		return (printable);
	else if (c == 'l' && sub_str[len - 1] == '%')
		return ((unsigned long)printable);
	else if (sub_str[len - 1] == 'h' && c == 'h' && sub_str[len - 2] == '%')
		return ((unsigned char)printable);
	else if (c == 'h' && sub_str[len - 1] == '%')
		return ((unsigned short)printable);
	else		//something here--> this is the case when there is something else than '%' before hh,h,l,ll
		return 0;
	return 0;
}