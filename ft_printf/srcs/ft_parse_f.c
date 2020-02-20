/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:45:25 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/20 18:11:50 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_check_prev_f(t_format *f, long double print, int precision)
{
	f->null = print == 0 ? 1 : 0;
	f->nbr = ft_lftoa(print, precision);
	f->sign = print < 0 ? 1 : 0;
	calculate_returnable_bytes(f);
	if (f->width && !f->minus && f->sign && !f->zero)
		ft_parse_width(f);
	f->sign ? print_in_case_of_sign(f, 1) : 0;
	if ((f->plus || f->space) && f->zero)
		ft_parse_flags(f);
	if (f->width && !f->minus)
		ft_parse_width(f);
	if ((f->plus || f->space) && !f->zero)
		ft_parse_flags(f);
	f->sign ? print_in_case_of_sign(f, 2) : ft_putstr(f->nbr);
	if (ft_strchr(f->nbr, '.') && f->hash)
		f->ret--;
	if (f->hash)
		ft_parse_flags(f);
	if (f->width && f->minus && !f->zero)
		ft_parse_width(f);
	ft_struct_del(f);
	return (f->ret);
}

static int	ft_precision_f(t_format *f)
{
	char	*ptr;
	int		ret;

	if (!f->s_str)
		exit (6);
	ret = 0;
	if ((ptr = ft_strchr(f->s_str, '.')) == NULL)
		return (6);
	ptr++;
	if (!ft_isdigit(*ptr))
	{
		ptr = NULL;
		return (0);
	}
	ret = ft_atoi(ptr);
	ptr = NULL;
	return (ret);
}

int			ft_parse_f(t_format *f, va_list ap)
{
	long double	print;

	print = f->len == 'L' ? va_arg(ap, long double) : va_arg(ap, double);
	return (ft_check_prev_f(f, print, ft_precision_f(f)));
}
