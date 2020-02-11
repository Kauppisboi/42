/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal_ull.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:30:44 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/18 17:01:20 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_octal_ull(unsigned long long nbr)
{
	if (nbr >= 8)
		ft_print_octal_ull(nbr / 8);
	nbr = nbr % 8;
	nbr += '0';
	write(1, &nbr, 1);
}
