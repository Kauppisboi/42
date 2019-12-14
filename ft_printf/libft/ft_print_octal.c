/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:50:14 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/14 15:18:54 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_octal(long long nbr)
{
	if (nbr >= 8)
		ft_print_octal(nbr / 8);
	nbr = nbr % 8;
	nbr += '0';
	write(1, &nbr, 1);
}