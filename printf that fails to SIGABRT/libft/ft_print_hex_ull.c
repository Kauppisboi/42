/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:22:39 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/18 17:01:04 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex_ull(unsigned long long nbr, int upper)
{
	if (nbr >= 16)
		ft_print_hex(nbr / 16, upper);
	nbr = nbr % 16;
	if (upper)
		nbr += (nbr < 10) ? '0' : 'A' - 10;
	else
		nbr += (nbr < 10) ? '0' : 'a' - 10;
	write(1, &nbr, 1);
}
