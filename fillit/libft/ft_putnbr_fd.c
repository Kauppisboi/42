/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:46:12 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/24 14:58:40 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	value;

	value = n;
	if (value < 0)
	{
		ft_putchar_fd('-', fd);
		value = -value;
	}
	if (value / 10)
		ft_putnbr_fd(value / 10, fd);
	ft_putchar_fd(value % 10 + '0', fd);
}
