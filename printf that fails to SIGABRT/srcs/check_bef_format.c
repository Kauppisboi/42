/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bef_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:26:13 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 17:32:11 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_free_return(t_format *f)
{
	int		len;

	ft_putstr(f->nbr);
	len = ft_strlen(f->nbr);
	ft_struct_del(f);
	return (len);
}

int			check_bef_format(t_format *f, long long print)
{
	f->null = print == 0 ? 1 : 0;
	if (!f->len)
		f->nbr = ft_itoa_base((int)print, 10, 0);
	else
		hh_h_ll_l(f, print, 10, 0);
	if (!f->nbr)
		exit(1);
	f->sign = print >= 0 ? '+' : '-';
	if (f->dot)
		ft_parse_precision(f);
	if (f->plus || f->space || f->hash)
		ft_parse_flags(f);
	if (f->width)
		ft_parse_width(f);
	return (print_free_return(f));
}
