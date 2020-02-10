/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_check_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:33:23 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 17:32:29 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_if_width(t_format *f)
{
	char			*ptr;
	int				ret;
	unsigned int	i;

	ret = 0;
	if ((ptr = ft_strchr(f->s_str, '$')) != NULL)
	{
		ret = ft_atoi(++ptr);
		ptr = NULL;
		return (ret);
	}
	else
		i = 0;
	ptr = NULL;
	while (f->s_str[i] && f->s_str[i] != '.')
	{
		if (f->s_str[i] != '0' && ft_isdigit(f->s_str[i]))
			return (ft_atoi(&f->s_str[i]));
		i++;
	}
	return (0);
}

int		iszero(t_format *f)
{
	int		i;

	i = 0;
	while (f->s_str[i])
	{
		if (f->s_str[i] == '.' || (f->s_str[i] >= '1' && f->s_str[i] <= '9'))
			return (0);
		else if (f->s_str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}
