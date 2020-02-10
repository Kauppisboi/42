/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bef_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:26:13 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 20:48:35 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	calculate_width_and_prec(t_format *f)
{
	if (f->prec >= f->width)
		f->width = 0;
	if (f->prec && f->width > f->prec)
		f->width = f->width - f->prec - f->space - f->plus;
	if (f->width && !f->prec)
		f->width = f->width - ft_strlen(f->nbr) - f->space - f->plus;
	f->prec = f->prec - ft_strlen(f->nbr);
}

static int	calculate_returnable_len(t_format *f)
{
	int		len;
	int		ret;

	ret = 0;
	len = ft_strlen(f->nbr);
	if (f->width && f->width > f->prec)
	{
		if (f->width > len)
		{
			ret = f->width;
			return (ret);
		}
	}
	if (f->prec && f->prec >= f->width && f->prec >= len)
	{
		if (f->prec >= len)
			ret = f->prec;
	}
	if (len >= f->width)
	{
		if (len >= f->prec)
			ret = len;
	}
	if (f->plus || f->space)
		ret++;
	return (ret);
}

int			check_bef_format(t_format *f, long long print)
{
	int		ret;
	
	f->null = print == 0 ? 1 : 0;
	f->sign = print >= 0 ? '+' : '-';
	if (!f->len)
		f->nbr = ft_itoa_base((int)print, 10, 0);
	else
		hh_h_ll_l(f, print, 10, 0);
	ret = calculate_returnable_len(f);
	calculate_width_and_prec(f);
	if (f->width)
		ft_parse_width(f);
	if (f->plus || f->space)
		ft_parse_flags(f);
	if (f->dot)
		ft_parse_precision(f);
	ft_putstr(f->nbr);
	return (ret);
}
