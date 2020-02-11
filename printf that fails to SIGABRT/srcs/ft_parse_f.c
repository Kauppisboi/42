/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ft_parse_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:45:25 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 17:31:05 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_check_prev_f(t_format *f, long double print, int precision)
{
	int		len;

	f->null = print == 0 ? 1 : 0;
	f->nbr = ft_lftoa(print, precision);
	if (!f->nbr)
		exit (6);
	f->sign = print >= 0 ? '+' : '-';
	if (f->plus || f->space || f->hash)
		ft_parse_flags(f);
	if (f->width)
		ft_parse_width(f);
	if (!f->nbr)
		exit (6);
	ft_putstr(f->nbr);
	len = ft_strlen(f->nbr);
	ft_struct_del(f);
	return (len);
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
