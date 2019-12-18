/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_l_L_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:19:22 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/17 16:22:46 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parse_l_L_f(char *format, va_list ap)
{
	if (*format == 'l')
//		ft_print_di_h_l((format - 1), ap);
		;
	else if (*format == 'L')
		;
//		ft_print_o_h_l((format - 1), ap);
	return (1);
}