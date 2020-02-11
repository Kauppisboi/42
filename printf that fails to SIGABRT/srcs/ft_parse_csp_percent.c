/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ft_parse_csp_percent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:29:55 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 17:30:56 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_address(va_list ap, t_format *f)
{
	long long int	address;
	int				upper;
	char			*tmp;
	char			*tmp2;

	upper = 0;
	address = va_arg(ap, long long int);
	f->null = address == 0 ? 1 : 0;
	tmp = ft_itoa_base_u(address, 16, 0);
	if (tmp == NULL)
		exit(7);
	tmp2 = ft_strjoin("0x", tmp);
	if (tmp2 == NULL)
		exit(7);
	ft_strdel(&tmp);
	f->nbr = tmp2;
}

static void	ft_print_str(va_list ap, t_format *f)
{
	char	*printable;

	printable = va_arg(ap, char*);
	f->null = printable == 0 ? 1 : 0;
	f->nbr = printable ? ft_strdup(printable) : ft_strdup("(null)");
	if (f->nbr == NULL)
		exit(7);
	printable = NULL;
}

static void	ft_parse_char(char c, t_format *f)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	f->nbr = ft_strdup(str);
	if (f->nbr == NULL)
		exit(7);
}

static char	ft_handle_char(va_list ap, t_format *f)
{
	char	printable;

	printable = va_arg(ap, int);
	f->null = printable == 0 ? 1 : 0;
	return (printable);
}

int			ft_parse_csp_percent(t_format *f, va_list ap)
{
	char	b;
	int		len;

	b = 0;
	if (f->format == 'c' || f->format == '%')
		ft_parse_char((f->format == '%') ? '%' : ft_handle_char(ap, f), f);
	else if (f->format == 's')
		ft_print_str(ap, f);
	else if (f->format == 'p')
		ft_print_address(ap, f);
	if (f->format == 's' && f->dot)
		ft_parse_precision(f);
	if (f->width)
		ft_parse_width(f);
	if (f->format == 'c' && f->null == 1)
	{
		f->minus ? ft_putchar('\0') : ft_putstr(f->nbr);
		f->minus ? ft_putstr(f->nbr) : ft_putchar('\0');
	}
	else
		ft_putstr(f->nbr);
	len = f->format == 'c' && f->null == 1 ? ft_strlen(f->nbr) + 1
		: ft_strlen(f->nbr);
	ft_struct_del(f);
	return (len);
}
