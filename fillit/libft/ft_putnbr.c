/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:45:06 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 14:37:59 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long	value;

	value = nb;
	if (value < 0)
	{
		ft_putchar('-');
		value = -value;
	}
	if (value / 10)
		ft_putnbr(value / 10);
	ft_putchar(value % 10 + '0');
}
