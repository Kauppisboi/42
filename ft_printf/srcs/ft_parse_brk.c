/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ft_parse_brk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:11:25 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 17:30:43 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printf_bonus(t_format *f, unsigned long long print)
{
	int		len;

	if (f->format == 'b')
		f->nbr = ft_itoa_base((int)print, 2, 0);
	else
		return (0);
	ft_putstr(f->nbr);
	len = ft_strlen(f->nbr);
	ft_struct_del(f);
	return (len);
}
