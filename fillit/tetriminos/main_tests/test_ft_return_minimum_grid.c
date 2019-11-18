/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_return_minimum_grid.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:34:23 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/13 21:20:55 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int	main(int argc, char **argv)
{
	(void)argc;
	char	**grid;
	t_grid	g;
	int		i;

	i = 0;
	grid = NULL;
	if (argc == 1)
	{
		printf("Provide a number as argument!\n");
		exit(1);
	}
	if (argc == 2)
	{
		g = ft_return_minimum_grid(atoi(argv[1]));
		printf("tetriminos count: %d\n", atoi(argv[1]));
	}
	printf(" -- PRINTING GRID --\n");
	while (g.grid[i])
		printf("%s\n", g.grid[i++]);
	return (0);
}
