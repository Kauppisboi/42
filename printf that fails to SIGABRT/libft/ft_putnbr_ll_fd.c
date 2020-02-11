/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:21:13 by jrignell          #+#    #+#             */
/*   Updated: 2020/01/31 12:24:27 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ll_fd(long long n, int fd)
{
	unsigned long long int	num;

	num = 0;
	if (n < 0)
		num = (unsigned long long int)(n * -1);
	else
		num = n;
	if (num >= 10)
		ft_putnbr_ull_fd(num / 10, fd);
	ft_putchar_fd((char)(num % 10 + '0'), fd);
}
