/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_minimum_grid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:44:34 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/18 17:17:25 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Returns correctly sized grid based on the number of tetriminos.
*/

t_grid	ft_return_minimum_grid(int tetr_count)
{
	char	**grid;
	t_grid	g;
	int		min_tetr_area;
	int		grid_size;
	int		i;

	grid_size = 2;
	min_tetr_area = tetr_count * 4;
	while (grid_size * grid_size < min_tetr_area)
		grid_size++;
	if (!(grid = (char**)malloc(sizeof(char*) * (grid_size + 1))))
		ft_err_and_exit();
	i = 0;
	while (i < grid_size)
		grid[i++] = ft_memset(ft_strnew(grid_size), '.', grid_size);
	grid[i] = NULL;
	g.size = grid_size;
	g.grid = grid;
	g.x = 0;
	g.y = 0;
	g.tetr_left = tetr_count;
	return (g);
}
