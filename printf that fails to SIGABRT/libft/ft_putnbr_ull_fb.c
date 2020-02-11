/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ull_fb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:33:20 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/02 17:37:56 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ull_fd(unsigned long long int n, int fd)
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
