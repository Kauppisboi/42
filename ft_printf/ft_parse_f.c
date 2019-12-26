/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:45:25 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/21 17:48:03 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_f(char *str_sub, va_list ap, unsigned len)
{
	long double	printable;

	printable = va_arg(ap, double);
	ft_check_previous_u(printable, str_sub, --len, 'x');
}

int			ft_parse_f(char *str_sub, va_list ap, unsigned len)
{
	return (0);
}