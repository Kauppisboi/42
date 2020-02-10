/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1ft_parse_diouxf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:32:49 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 17:30:08 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		diouxf(t_format *f, va_list ap)
{
	if (f->format == 'd' || f->format == 'i')
		return (check_bef_format(f, va_arg(ap, long long)));
	else if (f->format == 'o' || f->format == 'u'
			|| f->format == 'x' || f->format == 'X')
		return (check_bef_format_u(f, va_arg(ap, unsigned long long)));
	else if (f->format == 'f')
		return (ft_parse_f(f, ap));
	else if (f->format == 'c' || f->format == 's'
			|| f->format == 'p' || f->format == '%')
		return (ft_parse_csp_percent(f, ap));
//	else if (f->format == 'b' || f->format == 'r' || f->format == 'k')
//		return (printf_bonus(f, va_arg(ap, unsigned long long)));
	return (0);
}
