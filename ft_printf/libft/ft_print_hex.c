/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:53:48 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/18 17:02:30 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(long long int nbr, int upper)
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
