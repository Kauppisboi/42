/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_and_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:56:27 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/13 21:14:27 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Prints error message and exits the program.
*/

void	ft_err_and_exit(void)
{
	write(1, "error\n", 6);
	exit(1);
}
