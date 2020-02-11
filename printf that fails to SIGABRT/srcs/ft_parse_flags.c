/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5ft_parse_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:54:20 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 17:31:35 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_nbr_zero_free(t_format *f)
{
	ft_strdel(&f->nbr);
	f->nbr = f->dot && f->prec == 0 ? ft_strdup("\0") : ft_strdup("0");
	if (f->nbr == NULL)
		exit(1);
}

static void	ft_parse_hash_flag(t_format *f)
{
	if (f->format == 'o' && *f->nbr == '0' && ft_strlen(f->nbr) == 1)
		ft_nbr_zero_free(f);
	else if (f->format == 'o' && *f->nbr != '0')
		ft_str_free(f, ft_strdup("0"), 1, 1);
	else if ((f->format == 'x' || f->format == 'X') && *f->nbr == '0'
		&& ft_strlen(f->nbr) == 1)
		ft_nbr_zero_free(f);
	else if (f->format == 'x' && *f->nbr)
		ft_str_free(f, ft_strdup("0x"), 1, 1);
	else if (f->format == 'X' && *f->nbr)
		ft_str_free(f, ft_strdup("0X"), 1, 1);
	else if (f->format == 'f' && f->dot && f->prec == 0)
		ft_str_free(f, ft_strdup("."), 0, 1);
}

static void	ft_parse_space(t_format *f)
{
	if (*f->nbr >= '0' && *f->nbr <= '9' && f->sign == '+')
		ft_str_free(f, ft_strdup(" "), 1, 1);
}

static void	ft_parse_plus_flag(t_format *f)
{
	if (*f->nbr >= '0' && *f->nbr <= '9' && f->sign == '+')
		ft_str_free(f, ft_strdup("+"), 1, 1);
	else if (*f->nbr == '\0')
		ft_str_free(f, ft_strdup("+"), 1, 1);
}

void		ft_parse_flags(t_format *f)
{
	if ((f->format == 'd' || f->format == 'i' || f->format == 'f')
		&& f->plus && f->sign == '+')
		ft_parse_plus_flag(f);
	else if ((f->format == 'd' || f->format == 'i' || f->format == 'f')
		&& !f->plus && f->space)
		ft_parse_space(f);
	if ((f->format == 'x' || f->format == 'X') && f->hash && f->null != 1)
		ft_parse_hash_flag(f);
	else if ((f->format == 'o' || f->format == 'f') && f->hash)
		ft_parse_hash_flag(f);
	if (f->nbr == NULL)
		exit(3);
}
