/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:20:21 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/19 15:01:43 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putnbr_fd(long long int n, int fd)
{
	long long int	num;

	if (n == LONG_MIN)
	{
		write(1, "-9223372036854775808", 20);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (long long int)(n * -1);
	}
	else
		num = (long long int)n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((char)(num % 10 + '0'), fd);
}
