/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_diouxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:38:23 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/14 17:12:12 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_xX(char *format, va_list ap)
{
	int		upper;
	int		printable;

	upper = (*format == 'x') ? 0 : 1;
	printable = va_arg(ap, int);
	ft_print_hex(printable, upper);
}

int			ft_parse_diouxX(char *format, va_list ap)
{
	long long int		printable_ll;
	unsigned long long	printable_ull;
	
	if (*format == 'd' || *format == 'i')
	{
		printable_ll = va_arg(ap, int);
		ft_putnbr(printable_ll);
	}
	else if (*format == 'o')
	{
		printable_ll = va_arg(ap, unsigned int);
		ft_print_octal(printable_ll);
	}
	else if (*format == 'u')
	{
		printable_ull = va_arg(ap, unsigned long long);
		ft_putnbr_ull_fd(printable_ull, 1);
	}
	else if (*format == 'x' || *format == 'X')
		ft_print_xX(format, ap);
	return (1);
}