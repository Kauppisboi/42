/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6ft_parse_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:36:21 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 17:31:48 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_join_free_old(t_format *f, char *tmp)
{
	char	*s1;

	s1 = NULL;
	if (f->minus)
		s1 = ft_strjoin(f->nbr, tmp);
	else
		s1 = ft_strjoin(tmp, f->nbr);
	if (s1 == NULL)
		exit(4);
	ft_strdel(&f->nbr);
	f->nbr = s1;
	ft_strdel(&tmp);
}

static char	ft_return_char(t_format *f)
{
	if (f->minus)
		return (' ');
	if (f->zero && f->format == 'f')
		return ('0');
	if (f->zero && f->format != 'c' && f->format != 's'
		&& f->format != 'p' && !f->prec)
		return ('0');
	return (' ');
}

void		ft_parse_width(t_format *f)
{
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
}
