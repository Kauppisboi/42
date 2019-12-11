/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:57:34 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/11 20:57:50 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
t_syntax ft_put_zero(void)
{
	t_syntax	ptr;

	ptr.flags = '0';
	ptr.length = '0';
	ptr.parameter = '0';
	ptr.precision = '0';
	ptr.type = '0';
	ptr.width = '0';
	return (ptr);
}
*/
static int		ft_check_type(char *format)
{
	char	*array;

	array = "diouxX";
	while (array)
	{
		if (*format == *array)
			return (1);
		++array;
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 's' || (*(format + 1) == 'c') || (*(format + 1) == 'p')))
			ft_parse_str_char_ptr((char*)format++, ap);
		else if (*format == '%' && ft_check_type((char*)(3 + format)) == 1 && ((*(format + 1) == 'h' && (*(format + 2)) == 'h') ||
									((*(format + 1) == 'l' && (*(format + 2)) == 'l'))))
			ft_parse_hh_ll((char*)format + 2);
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (1);
}