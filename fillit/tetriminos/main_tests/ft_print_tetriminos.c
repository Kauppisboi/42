/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:17:01 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/14 21:12:05 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// FOR DEV ONLY, DELETE THIS
void	ft_print_tetriminos(t_tet **tetriminos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("PRINTING TETRIMINOS\n");
	while (tetriminos[i])
	{
		printf("\n");
		j = 0;
		while (tetriminos[i]->shape[j])
		{
			printf("%s\n", tetriminos[i]->shape[j]);
			++j;
		}
		i++;
	}
	printf("\n");
	printf("I on %d", i);
}

