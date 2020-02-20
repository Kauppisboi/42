/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:54:20 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/20 12:32:40 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_parse_hash_flag(t_format *f, int i)
{
	if (i == 1)
	{
		f->ret += f->o_width > f->length && f->o_width > f->o_prec ? 0 : 2;
		if (f->format == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
	else if (i == 2)
	{
		f->ret += f->o_width > f->length && f->o_width > f->o_prec ? 0 : 1;
		if (f->format == 'o')
			write(1, "0", 1);
		else if (!ft_strchr(f->nbr, '.'))
			write(1, ".", 1);
	}
}

static void	ft_parse_space(void)
{
	write(1, " ", 1);
}

static void	ft_parse_plus_flag(void)
{
	write(1, "+", 1);
}

void		ft_parse_flags(t_format *f)
{
//	printf("\nwidth %d prec %d ret %d len %d\n", f->width, f->prec, f->ret, f->length);
//	f->hash = 0;
	if ((f->format == 'd' || f->format == 'i' || f->format == 'f')
		&& f->plus)
			ft_parse_plus_flag();
	else if ((f->format == 'd' || f->format == 'i' || f->format == 'f')
		&& !f->plus && f->space && !f->sign)
		ft_parse_space();
	if ((f->format == 'x' || f->format == 'X') && f->hash && f->null != 1)
		ft_parse_hash_flag(f, 1);
	else if ((f->format == 'o' || f->format == 'f') && f->hash)// && !f->null)
	{
		f->hash = f->width && f->width >= f->length && f->width >= f->prec ? 0 : f->hash;
		ft_parse_hash_flag(f, 2);
	}
		
}
