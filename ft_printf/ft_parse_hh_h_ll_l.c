/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hh_h_ll_l.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:11:35 by jrignell          #+#    #+#             */
/*   Updated: 2020/01/03 11:46:33 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		ft_parse_hh_h_ll_l(char *sub_str, long long print, unsigned len, unsigned min_i)
{
	char		c;
	char		prev;
	unsigned	start;

	c = sub_str[len];
	prev = sub_str[len - 1];
	if (prev == 'l' && c == 'l' && sub_str[len - 2] == '%')
		return (print);
	else if (c == 'l' && sub_str[len - 1 - min_i] == '%')
		return ((long)print);
	else if (prev == 'h' && c == 'h' && sub_str[len - 2 - min_i] == '%')
		return ((signed char)print);
	else if (c == 'h' && sub_str[len - 1 - min_i] == '%')
		return ((short)print);
	else
	{
		start = ((c == 'l' && prev == 'l') || (c == 'h' && prev == 'h')) ? 3 : 2;
		len -= start;
		while (sub_str[len--] != '%')
				min_i++;
		return (ft_parse_hh_h_ll_l(sub_str, print, len, min_i));
	}
	return 0;
}

unsigned long long	ft_parse_hh_h_ll_l_u(char *sub_str, unsigned long long print,
								unsigned len, unsigned min_i)
{
	char		c;
	char		prev;
	unsigned	start;

	c = sub_str[len];
	prev = sub_str[len - 1];
	if (prev == 'l' && c == 'l' && sub_str[len - 2 - min_i] == '%')
		return (print);
	else if (c == 'l' && sub_str[len - 1 - min_i] == '%')
		return ((unsigned long)print);
	else if (prev == 'h' && c == 'h' && sub_str[len - 2 - min_i] == '%')
		return ((unsigned char)print);
	else if (c == 'h' && sub_str[len - 1 - min_i] == '%')
		return ((unsigned short)print);
	else		
	{
		start = ((c == 'l' && prev == 'l') || (c == 'h' && prev == 'h')) ? 3 : 2;
		len -= start;
		while (sub_str[len--] != '%')
				min_i++;
		return (ft_parse_hh_h_ll_l_u(sub_str, print, len, min_i));
	}
	return 0;
}