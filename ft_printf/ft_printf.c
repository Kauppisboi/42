/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:57:34 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/22 14:31:47 by jrignell         ###   ########.fr       */
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

static char		ft_check_type(const char c)
{
	char	*array;
	int		i;

	array = "diouxXf";
	i = 0;
	while (array[i] != '\0')
	{
		if (c == array[i])
			return (array[i]);
		++i;
	}
	return ('0');
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	unsigned int	i;
	unsigned int	len;
	char			*sub_str;
	int				ret;

	va_start(ap, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		len = 0;
		if (format[i] == '%')
		{
			while ((format[i + len] != ft_check_type(format[i + len])) && format[i + len]) // if format hasn't type error will happen
				len++;
			sub_str = ft_strsub(format, i, ++len);
			ret += ft_parse_diouxXf(sub_str, ap, ft_strlen(sub_str) - 1);
			len--;
		}
		else
		{
			write(1, &format[i], 1);
			ret++;
		}
		i += len + 1;
	}
	va_end(ap);
	printf("My printf returns %d\n", ret);
	return (ret);
}
/*

		if (*format == '%' && (*(format + 1) == 's' || (*(format + 1) == 'c') || (*(format + 1) == 'p')))
			ft_parse_str_char_ptr((char*)format++, ap);
		else if (*format == '%' && ft_check_type((char*)(format + 3)) == 1 && (((*(format + 1) == 'h') && (*(format + 2) == 'h')) || ((*(format + 1) == 'l') && (*(format + 2) == 'l'))))
		{
			ft_parse_hh_ll_diouxX((char*)(format + 3), ap);
			format += 3;
		}
		else if (*format == '%' && ft_check_type((char*)(format + 2)) == 1 && (*(format + 1) == 'h' || (*(format + 1) == 'l')))
		{
			ft_parse_h_l_diouxX((char*)(format + 2), ap);
			format += 2;
		}
		else if (*format == '%' && ft_check_type((char*)(format + 1)) == 1)
		{
			ft_parse_diouxX((char*)(format + 1), ap);
			format++;
		}
		else if (*format == '%' && *(format + 2) == 'f' && (*(format + 1) == 'L' || (*(format + 1) == 'l')))
			ft_parse_l_L_f((char*)(format + 2), ap);
		else if (*format == '%' && ft_check_type((char*)(format + 1)) == 6)
			ft_parse_f();
*/