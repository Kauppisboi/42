/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grow_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:10:42 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/18 18:51:06 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Frees grid given as argument.
*/

static void	ft_free_grid(char **grid_ptr)
{
	int		i;

	if (!grid_ptr)
		return ;
	i = 0;
	while (grid_ptr[i] != NULL)
		free(grid_ptr[i++]);
	free(grid_ptr);
}

/*
** Replaces grid with a bigger one (g-size + 1).
*/

void		ft_grow_grid(t_grid *g)
{
	int	i;

	g->size++;
	ft_free_grid(g->grid);
	if (!(g->grid = (char**)malloc(sizeof(char*) * (g->size + 1))))
		ft_err_and_exit();
	i = 0;
	while (i < g->size)
	{
		if (!(g->grid[i] = ft_strnew(g->size)))
			ft_err_and_exit();
		ft_memset(g->grid[i++], '.', g->size);
	}
	g->grid[i] = NULL;
}
