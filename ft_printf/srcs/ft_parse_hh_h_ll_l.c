/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hh_h_ll_l.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:11:35 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/20 16:32:53 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		which_len(t_format *f)
{
	char	*c;
	int		len;

	c = NULL;
	len = 0;
	if (!(c = ft_strchr(f->s_str, 'l')))
		if (!(c = ft_strchr(f->s_str, 'h')))
			if (!(c = ft_strchr(f->s_str, 'L')))
				return (0);
	if (*c == 'L')
		len =  ('L');
	else if (*c == 'l' && *(c + 1) != 'l')
		len = ('l');
	else if (*c == 'l' && *(c + 1) == 'l')
		len =  (2 * 'l');
	else if (*c == 'h' && *(c + 1) != 'h')
		len =  ('h');
	else if (*c == 'h' && *(c + 1) == 'h')
		len =  (2 * 'h');
	c = NULL;
	return (len);
}

void	hh_h_ll_l(t_format *f, long long print, int base, int upper)
{
	if (f->len == 2 * 'l')
		f->nbr = ft_itoa_base(print, base, upper);
	else if (f->len == 'l')
		f->nbr = ft_itoa_base((long)print, base, upper);
	else if (f->len == 'h')
		f->nbr = ft_itoa_base((short)print, base, upper);
	else if (f->len == 2 * 'h')
		f->nbr = ft_itoa_base((signed char)print, base, upper);
	else
		f->nbr = ft_itoa_base(print, base, upper);
}

void	hh_h_ll_l_u(t_format *f, unsigned long long print, int base, int upper)
{
	if (f->len == 2 * 'l')
		f->nbr = ft_itoa_base_u(print, base, upper);
	else if (f->len == 'l')
		f->nbr = ft_itoa_base_u((unsigned long)print, base, upper);
	else if (f->len == 2 * 'h')
		f->nbr = ft_itoa_base_u((unsigned char)print, base, upper);
	else if (f->len == 'h')
		f->nbr = ft_itoa_base_u((unsigned short)print, base, upper);
	else
		f->nbr = ft_itoa_base_u(print, base, upper);
}
