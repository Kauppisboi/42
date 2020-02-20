/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bef_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:26:13 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/20 17:12:28 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_sign_space_plus_prec_width(t_format *f, int i)
{
	if (i == 2)
	{//printf("width %d prec %d len %d hash %d\n", f->width, f->prec, f->length, f->hash);
		if (f->dot)
			f->width -= f->prec >= f->length ? (f->prec + f->plus + f->space + f->hash)
				: (f->length + f->plus + f->space + f->hash);
		else
			f->width -= f->width > f->length ? f->length + f->space + f->plus// + f->hash
				: f->length;
		f->width += f->null && !f->prec && f->dot ? 1 : 0;// f->hash;
		f->prec -= f->length;
		f->prec = f->prec < 0 ? 0 : f->prec;
		//printf("width %d prec %d len %d hash %d\n", f->width, f->prec, f->length, f->hash);
	}
	else if (i == 3)
		{
			//printf("\nwidth %d prec %d len %d\n", f->width, f->prec, f->length);
			f->width = 0;
			f->prec -= f->length;
			f->zero = 0;
			f->prec = f->prec < 0 ? 0 : f->prec;
			//printf("width %d prec %d len %d\n", f->width, f->prec, f->length);
		}	
}

void	calculate_width_and_prec_zero_flag(t_format *f)
{
	if (f->sign)
	{
		f->plus = 0;
		f->space = 0;
		f->prec++;
	}
	if (f->width && f->width > f->prec && f->width > f->length)
		check_sign_space_plus_prec_width(f, 2);
	else
		check_sign_space_plus_prec_width(f, 3);
}

void	print_in_case_of_sign(t_format *f, int i)
{
	if (i == 1)
	{
		if ((f->o_width && f->zero) || f->prec)
			ft_putchar('-');
	}
	else if (i == 2)
	{
		if ((f->o_width && f->zero) || f->prec)
		{
			ft_putstr(&f->nbr[1]);
		}
		else
			ft_putstr(f->nbr);
	}
}

void	calculate_returnable_bytes(t_format *f)
{
	int		ret;

	ret = 0;
	f->length = ft_strlen(f->nbr);
//printf("\nlength %d width %d minus %d zero %d sign %d plus %d space %d prec %d\n", f->length, f->width, f->minus, f->zero, f->sign, f->plus, f->space, f->prec);	
	if (f->width && f->width > f->prec && f->width > f->length)
		ret = f->width;
	else if (f->prec && f->prec >= f->width && f->prec >= f->length)
		ret = f->prec;
	else if (f->length >= f->width && f->length >= f->prec)
		ret = f->length;
//		ret = (!f->o_prec && !f->o_width) && !f->minus ? f->length + f->plus + f->space : f->length;//tamaa
	if (f->dot && !f->prec && f->null && !f->width)
		ret--;
	calculate_width_and_prec_zero_flag(f);
	if (f->sign && f->o_prec == ret)
		ret++;
	if (!f->sign && !f->o_width && !f->o_prec && (f->space || f->plus))
		ret++;
	f->ret = ret;
}

void	print_pos_num(t_format *f)
{
	if (f->null && f->dot && !f->prec)
		return ;
	else
		ft_putstr(f->nbr);
}

int			check_bef_format(t_format *f, long long print)
{
	f->null = print == 0 ? 1 : 0;
	f->hash = 0;
	if (!f->len)
		f->nbr = ft_itoa_base((int)print, 10, 0);
	else
		hh_h_ll_l(f, print, 10, 0);
	f->sign = *f->nbr == '-' ? 1 : 0;
	calculate_returnable_bytes(f);//printf("\nhere length %d width %d plus %d prec %d minus %d zero %d sign %d\n", f->length, f->width, f->plus, f->prec, f->minus, f->zero, f->sign);	
	if (f->width && !f->minus && f->sign && !f->zero)
		ft_parse_width(f);
	f->sign ? print_in_case_of_sign(f, 1) : 0;
	if ((f->plus || f->space) && f->zero)
		ft_parse_flags(f);
	if (f->width && !f->minus)
		ft_parse_width(f);
	if ((f->plus || f->space) && !f->zero)
		ft_parse_flags(f);
	if (f->dot)
		ft_parse_precision(f);
	f->sign ? print_in_case_of_sign(f, 2) : print_pos_num(f);
	if (f->width && f->minus && !f->zero)
		ft_parse_width(f);
	ft_struct_del(f);
	return (f->ret);
}
