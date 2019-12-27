/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:36:21 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/27 14:15:20 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_parse_width(char *sub_str)
{
	unsigned int	i;
	unsigned int	len;
	int				width;

	i = 0;
	while (sub_str[i])
	{
		if (ft_isdigit(sub_str[i]))
			break;
		i++;
	}
	if (sub_str[i] == '\0')
		return ;
	len = 0;
	while (ft_isdigit(sub_str[i + len]) && sub_str[i + len] != '.')
		len++;
	if (sub_str[i + len] == '.')
		return ;
	width = ft_atoi_base(ft_strsub(sub_str, i, ++len), 10);
}