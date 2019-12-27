/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 12:20:05 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/27 13:15:47 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function return the index of the dot. It helps to define precision.
*/

int		ft_check_if_dot(char *sub_str)
{
	unsigned int	i;

	i = 0;
	while (sub_str[i])
	{
		if (sub_str[i] == '.')
			return (i);
		i++;
	}
	return (-1);
}

/*
** This function handles hashes '#', zeros '0', minus '-', plus '+' and space ' '.
** It returns the index of the flag.
*/

int		ft_return_flag(char *sub_str)
{
	unsigned int	i;

	i = 0;
	while (sub_str[i])
	{
		if (sub_str[i] == '#' || sub_str[i] == '0' || sub_str[i] == '-' ||
			sub_str[i] == '+' || sub_str[i] == ' ')
			return (i);
		i++;
	}
	return (-1);
}