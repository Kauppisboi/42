/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:36:21 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/20 11:31:54 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_zero_or_space(t_format *f)
{
	int		i;

	i = 0;//printf("width %d prec %d len %d\n", f->width, f->prec, f->length);
	while  (!f->zero && i++ < f->width)
	{
		//printf("i is %d\n", i);
		write(1, " ", 1);
	}
	while (f->zero && i++ < f->width)
		write(1, "0", 1);
	f->width = 0;
}

static void	print_space_after_int(t_format *f)
{
	int		i;

	i = 0;//ft_putendl("here");
	while (!f->zero && i++ < f->width)
		write(1, " ", 1);
	f->width = 0;
}

static void	print_space_before_sign(t_format *f)
{
	int		i;

	i = 0;//printf("width %d prec %d len %d\n", f->width, f->prec, f->length);
	while (!f->zero && i++ < f->width)
		write(1, " ", 1);
	f->width = 0;
}

void		ft_parse_width(t_format *f)
{
//	printf("\nhere length %d width %d plus %d prec %d minus %d zero %d sign %d\n", f->length, f->width, f->plus, f->prec, f->minus, f->zero, f->sign);
	if (f->width && !f->minus && f->sign && !f->zero)
		return print_space_before_sign(f);
	else if (f->width && !f->minus)
		return print_zero_or_space(f);
	else if (f->width && f->minus && !f->zero)
		return print_space_after_int(f);
}/*
	int		len;
	char	*tmp;
	int		i;
	char	flag;
	
	tmp = NULL;
	len = (int)ft_strlen(f->nbr);
	f->width -= f->format == 'c' && f->null == 1 ? 1 : 0;
	if (len >= f->width && f->format != 's')
		return ;
	flag = ft_return_char(f);
	i = 0;
	if (f->prec >= f->width && f->format != 's')
		return ;
	if (f->width > len)
	{
		if (!(tmp = ft_strnew(((f->width) - len))))
			exit(4);
		while (f->width > len++)
			tmp[i++] = flag;
		ft_join_free_old(f, tmp);
	}
	if (!f->nbr)
		exit(4);
	f->format == 'd' || f->format == 'i' || f->format == 'f' ?
		swap_chars(f) : swap_0x(f);
*/