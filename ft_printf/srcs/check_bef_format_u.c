/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bef_format_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:29:38 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/20 18:11:45 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	null_with_prec_width(t_format *f)
{//printf("\nlength %d width %d prec %d minus %d zero %d null %d\n", f->length, f->width, f->prec, f->minus, f->zero, f->null);
//	f->hash = !f->o_width && !f->o_prec && f->hash ? 0 : f->hash;
	if (!f->null && f->width && f->hash && f->width > f->length && f->width > f->prec)
		f->width -= f->hash;
	else if (!f->null && !f->dot && f->hash && f->o_width > f->length)
		f->width -= f->hash;
	if (f->null && f->hash && f->width > f->length && f->dot && f->format != 'o')
		f->width += f->hash;
	else if (f->format != 'o' && f->null && f->prec && f->o_width > f->o_prec)
		f->width += f->hash;
}

static void	ft_help(t_format *f)
{
	f->plus = 0;
	f->space = 0;
	calculate_returnable_bytes(f);
//	printf("\nlength %d width %d prec %d minus %d zero %d null %d\n", f->length, f->width, f->prec, f->minus, f->zero, f->null);
//	if (f->null && f->hash)
//		f->width += (f->o_prec || f->o_width) ? f->hash : 0;
	null_with_prec_width(f);
	f->hash = !f->dot && !f->prec && f->null && f->format == 'o' ? 0 : f->hash;
	if (f->hash && f->format == 'o' && f->o_prec > f->length)
	{
		f->width += f->o_prec > f->o_width ? 0 : 1;
		f->hash = 0;
	}
	if (f->hash && f->zero)
		ft_parse_flags(f);
	if (f->width && !f->minus)
		ft_parse_width(f);
	
	if (f->hash && !f->zero)
		ft_parse_flags(f);
	if (f->dot)
		ft_parse_precision(f);
	print_pos_num(f);
	if (f->width && f->minus && !f->zero)
		ft_parse_width(f);
}

int			check_bef_format_u(t_format *f, unsigned long long print)
{
	int		upper;

	f->null = print == 0 ? 1 : 0;
	upper = (f->format == 'X') ? 1 : 0;
//	f->sign = 0;
	if ((!f->len && f->format == 'o'))
		f->nbr = ft_itoa_base_u((unsigned)print, 8, 0);
	else if (f->len && f->format == 'o')
		hh_h_ll_l_u(f, print, 8, 0);
	else if (!f->len && (f->format == 'x' || f->format == 'X'))
		f->nbr = ft_itoa_base_u((unsigned)print, 16, upper);
	else if (f->len && (f->format == 'x' || f->format == 'X'))
		hh_h_ll_l_u(f, print, 16, upper);
	else if (!f->len && f->format == 'u')
		f->nbr = ft_itoa_base_u((unsigned)print, 10, 0);
	else if (f->len && f->format == 'u')
		hh_h_ll_l_u(f, print, 10, 0);
	f->hash = f->format == 'u' ? 0 : f->hash;
	ft_help(f);
	ft_struct_del(f);
	return (f->ret);
}
