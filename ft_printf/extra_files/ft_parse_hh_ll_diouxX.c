/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hh_ll_diouxX.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:33:14 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/14 16:33:17 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_xX_hh_ll(char *format, va_list ap)
{
	long long int	printable;
	int				upper;

	upper = (*format == 'x') ? 0 : 1;
	format -= 2;
	if (*format == 'h' && *(format + 1) == 'h')
		{
			printable = va_arg(ap, int);
			ft_print_hex(printable, upper);
		}
	else if	(*format == 'l' && *(format + 1) == 'l')
		{
			printable = va_arg(ap, unsigned long long);
			ft_print_hex_ull(printable, upper);
		}
}

static void	ft_print_u_hh_ll(char *format, va_list ap)
{
	unsigned long long	printable;

	if (*format == 'h' && *(format + 1) == 'h')
		{
			printable = va_arg(ap, unsigned int);
			ft_putnbr(printable);
		}
	else if	(*format == 'l' && *(format + 1) == 'l')
		{
			printable = va_arg(ap, unsigned long long);
			ft_putnbr_ull_fd(printable, 1);
		}
}

static void	ft_print_o_hh_ll(char *format, va_list ap)
{
	long long int	printable;

	if (*format == 'h' && *(format + 1) == 'h')
		{
			printable = va_arg(ap, int);
			ft_print_octal(printable);
		}
	else if	(*format == 'l' && *(format + 1) == 'l')
		{
			printable = va_arg(ap, long long);
			ft_print_octal(printable);
		}
}

static void	ft_print_di_hh_ll(char *format, va_list ap)
{
	long long int	printable;

	if (*format == 'h' && *(format + 1) == 'h')
		{
			printable = va_arg(ap, int);
			ft_putnbr(printable);	
		}
	else if	(*format == 'l' && *(format + 1) == 'l')
		{
			printable = va_arg(ap, long long);
			ft_putnbr(printable);
		}
}

int			ft_parse_hh_ll_diouxX(char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		ft_print_di_hh_ll((format - 2), ap);
	else if (*format == 'o')
		ft_print_o_hh_ll((format - 2), ap);
	else if (*format == 'u')
		ft_print_u_hh_ll(format - 2, ap);
	else if (*format == 'x' || *format == 'X')
		ft_print_xX_hh_ll(format, ap);
	return (1);
}