/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bef_format_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:29:38 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 17:32:19 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_check_flags(t_format *f)
{
	if (f->dot)
		ft_parse_precision(f);
	if (f->plus || f->space || f->hash)
		ft_parse_flags(f);
	if (f->width)
		ft_parse_width(f);
	if (!f->nbr)
		exit(5);
}

int			check_bef_format_u(t_format *f, unsigned long long print)
{
	int		upper_or_len;

	f->null = print == 0 ? 1 : 0;
	upper_or_len = (f->format == 'X') ? 1 : 0;
	f->sign = print >= 0 ? '+' : '-';
	if ((!f->len && f->format == 'o'))
		f->nbr = ft_itoa_base((unsigned)print, 8, 0);
	else if (f->len && f->format == 'o')
		hh_h_ll_l_u(f, print, 8, 0);
	else if (!f->len && (f->format == 'x' || f->format == 'X'))
		f->nbr = ft_itoa_base_u((unsigned)print, 16, upper_or_len);
	else if (f->len && (f->format == 'x' || f->format == 'X'))
		hh_h_ll_l_u(f, print, 16, upper_or_len);
	else if (!f->len && f->format == 'u')
		f->nbr = ft_itoa_base_u((unsigned)print, 10, 0);
	else if (f->len && f->format == 'u')
		hh_h_ll_l_u(f, print, 10, 0);
	if (!f->nbr)
		exit(5);
	ft_check_flags(f);
	ft_putstr(f->nbr);
	upper_or_len = ft_strlen(f->nbr);
	ft_struct_del(f);
	return (upper_or_len);
}
