/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 10:57:01 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/27 14:07:43 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision(char *sub_str)
{
	unsigned int	i;
	unsigned int	prec;
	int				prec_int;

	prec = 0;
	i = ft_check_if_dot(sub_str);
	while (ft_isdigit(sub_str[i++]))
		prec++;
	i = ft_check_if_dot(sub_str);
	prec_int = ft_atoi_base(ft_strsub(sub_str, i, ++prec), 10);
}