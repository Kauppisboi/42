/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_csp_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:29:55 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/20 15:47:20 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_output(t_format *f)
{
	if (f->dot)
		f->prec <= f->length ? ft_putnstr(f->nbr, f->o_prec) : ft_putstr(f->nbr);
	else
		ft_putstr(f->nbr);
}

static void	calculate_width_prec(t_format *f)
{//printf("\nength %d width %d minus %d prec %d dot %d ret %d\n", f->length, f->width, f->minus, f->prec, f->dot, f->ret);
	if (f->dot && f->prec && f->prec <= f->length)
	{
		f->length = f->prec;
	}
	if (f->length >= f->width)
		f->width = 0;
	if (f->width > f->length)
		f->width -= f->length;
	if (f->format == 'p')
		f->width -= 2;
	f->width = f->width < 0 ? 0 : f->width;
}

static void	calculate_bytes(t_format *f)
{
	f->length = ft_strlen(f->nbr);
//printf("\nlength %d width %d minus %d prec %d dot %d ret %d\n", f->length, f->width, f->minus, f->prec, f->dot, f->ret);
	if (f->dot && !f->prec)
		f->length = 0;
	if (f->width && f->width >= f->length)
		f->ret = f->width;
	if (f->length >= f->width)
		f->ret = (f->dot && !f->prec) ? : f->length;
	if (f->dot && !f->width && f->prec < f->length)
		f->ret -= f->length - f->prec;
	f->ret -= f->format == 'p' ? 2 : 0;
	calculate_width_prec(f);
}
static int	ft_print_address(va_list ap, t_format *f)
{
	long long	address;

	address = va_arg(ap, long long);
	f->null = address == 0 ? 1 : 0;
	f->nbr = f->null ? ft_strdup("0") : ft_itoa_base_u(address, 16, 0);
	calculate_bytes(f);
	f->ret += 2;
	if (f->width && !f->minus)
		ft_parse_width(f);
	write(1, "0x", 2);
	print_output(f);
	if (f->width)
		ft_parse_width(f);
	ft_struct_del(f);
	return (f->ret);
}

static void	ft_print_str(va_list ap, t_format *f)
{
	char	*printable;

	printable = va_arg(ap, char*);
	f->null = printable == 0 ? 1 : 0;
	f->nbr = printable ? ft_strdup(printable) : ft_strdup("(null)");
	printable = NULL;
}

static int	ft_parse_char(char c, t_format *f)
{	
	f->null = c == 0 ? 1 : 0;
	f->nbr = ft_strnew(1);
	*f->nbr = c;
	calculate_bytes(f);
	if (f->null)
		f->width--;
	if (f->null && !f->o_width)
		f->ret++;
	if (f->width && !f->minus)
		ft_parse_width(f);
	ft_putchar(*f->nbr);
	if (f->width)
		ft_parse_width(f);
	ft_struct_del(f);
	return (f->ret);
}

int			ft_parse_csp_percent(t_format *f, va_list ap)
{

	if (f->format == 'c' || f->format == '%')
		return (ft_parse_char(f->format == '%' ? '%' : va_arg(ap, int), f));
	else if (f->format == 's')
		ft_print_str(ap, f);
	else if (f->format == 'p')
		return (ft_print_address(ap, f));
	calculate_bytes(f);
//	printf("\nlength %d width %d minus %d prec %d dot %d\n", f->length, f->width, f->minus, f->prec, f->dot);
	if (f->width && !f->minus)
		ft_parse_width(f);
	print_output(f);
	if (f->width)
		ft_parse_width(f);
	ft_struct_del(f);
	return (f->ret);
}
