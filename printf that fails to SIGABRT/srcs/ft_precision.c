/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4ft_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:41:08 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 17:31:19 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_free_old(t_format *f)
{
	ft_strdel(&f->nbr);
	f->nbr = ft_strdup("\0");
	if (f->nbr == NULL)
		exit(0);
}

static void	ft_precision_s(t_format *f, int prec)
{
	char	*tmp;

	if (prec < (int)ft_strlen(f->nbr))
	{
		tmp = NULL;
		if (!(tmp = ft_strsub(f->nbr, 0, prec)))
			exit(0);
		ft_strdel(&f->nbr);
		f->nbr = tmp;
	}
	tmp = NULL;
}

int			ft_if_precision_diouxs(t_format *f)
{
	char	*ptr;
	int		ret;

	ret = 0;
	if ((ptr = ft_strchr(f->s_str, '.')) == NULL)
		return (0);
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

/*
** The minimum number of digits to be printed,
** for the integer formats %d, %o, %x, and %u
*/

void		ft_parse_precision(t_format *f)
{
	int		len;
	char	*tmp;
	int		i;

	tmp = NULL;
	if (f->format != 's' && *f->nbr == '0' && ft_strlen(f->nbr) == 1)
		ft_free_old(f);
	len = (int)ft_strlen(f->nbr);
	i = 0;
	if (f->format == 's')
		return (ft_precision_s(f, f->prec));
	if (f->nbr[0] == '-' || f->nbr[0] == ' ')
		f->prec++;
	if (f->prec > len)
	{
		if (!(tmp = ft_strnew(f->prec - len)))
			exit(0);
		while (f->prec > len++)
			tmp[i++] = '0';
		ft_str_free(f, tmp, 1, 0);
	}
	if (f->nbr)
		return swap_chars(f);
	exit(0);
}
