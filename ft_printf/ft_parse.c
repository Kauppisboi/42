/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:58:33 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/11 20:21:17 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_address(va_list ap)
{
	long long int	address;

	address = va_arg(ap, long long int);
	ft_putstr("0x");
	ft_print_hex(address);
}

static void	ft_print_char(va_list ap)
{
	char	printable;

	printable = va_arg(ap, int);
	ft_putchar(printable);
}

static void	ft_print_str(va_list ap)
{
	char	*printable;

	printable = va_arg(ap, char*);
	ft_putstr(printable);
}

int			ft_parse_str_char_ptr(char *str, va_list ap)
{
	str++;
	while (str && *str != '\0')
	{
		if (*str == 'c')
		{
			ft_print_char(ap);
			break;
		}
		if (*str == 's')
		{
			ft_print_str(ap);
			break;
		}
		if (*str == 'p')
		{
			ft_print_address(ap);
			break;
		}
		str++;
	}
	return (1);
}