/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_h_l_diouxX.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:31:47 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/19 15:06:56 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_xX_h_l(char *format, va_list ap)
{
	long long int	printable;
	int				upper;

	upper = (*format == 'x') ? 0 : 1;
	format--;
	if (*format == 'h')
		{
			printable = va_arg(ap, int);
			ft_print_hex((unsigned short)printable, upper);
		}
	else if	(*format == 'l')
		{
			printable = va_arg(ap, unsigned long long);
			ft_print_hex_ull(printable, upper);
		}
}

static void	ft_print_u_h_l(char *format, va_list ap)
{
	unsigned long long	printable;

	if (*format == 'h')
		{
			printable = va_arg(ap, unsigned int);
			ft_putnbr((unsigned short)printable);
		}
	else if	(*format == 'l')
		{
			printable = va_arg(ap, unsigned long long);
			ft_putnbr_ull_fd(printable, 1);
		}
}

static void	ft_print_o_h_l(char *format, va_list ap)
{
	long long int	printable;

	if (*format == 'h')
		{
			printable = va_arg(ap, int);
			ft_print_octal((unsigned short)printable);
		}
	else if	(*format == 'l')
		{
			printable = va_arg(ap, unsigned long int);
			ft_print_octal_ull(printable);
		}
}

static void	ft_print_di_h_l(char *format, va_list ap)
{
	long int	printable;

	if (*format == 'h')
		{
			printable = va_arg(ap, int);
			ft_putnbr(printable);	
		}
	else if	(*format == 'l')
		{
			printable = va_arg(ap, long int);
			ft_putnbr(printable);
		}
}

int			ft_parse_h_l_diouxX(char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		ft_print_di_h_l((format - 1), ap);
	else if (*format == 'o')
		ft_print_o_h_l((format - 1), ap);
	else if (*format == 'u')
		ft_print_u_h_l(format - 1, ap);
	else if (*format == 'x' || *format == 'X')
		ft_print_xX_h_l(format, ap);
	return (1);
}