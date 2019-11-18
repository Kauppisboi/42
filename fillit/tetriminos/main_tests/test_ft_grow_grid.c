/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_grow_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:58:09 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/11 18:28:27 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int	main(void)
{
	//printf("LEAKS OFF\n");
	char	**grid;
	t_grid	g;
	//char	leaks;

	//read(0, &leaks, 1);

	grid = (char**)malloc(sizeof(char*) * 4);
	grid[0] = strdup("...");
	grid[1] = strdup("...");
	grid[2] = strdup("...");
	grid[3] = NULL;
	g.grid = grid;
	g.size = 3;

	ft_print_grid(g.grid);
	printf("\n--> Running command \"ft_grow_grid(&grid)\"\n\n");
	ft_grow_grid(&g);
	ft_print_grid(g.grid);
	printf("\n--> Running command \"ft_grow_grid(&grid)\"\n\n");
	ft_grow_grid(&g);
	ft_print_grid(g.grid);

	//read(0, &leaks, 1);

	return (0);
}
