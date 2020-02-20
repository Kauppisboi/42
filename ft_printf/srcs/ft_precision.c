/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:41:08 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/20 16:39:00 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	int		i;

	i = 0;
	while (i++ < f->prec)
		write(1, "0", 1);
//	f->prec = 0;
}
