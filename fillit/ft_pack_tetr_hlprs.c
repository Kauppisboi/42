/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pack_tetr_hlprs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:35:46 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/18 18:12:14 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Returns an unplaced tetrimino from an array.
*/

int		ft_return_unplaced(t_tet **t)
{
	int	cur;

	cur = 0;
	while (t[cur]->placed == 1)
		cur++;
	return (cur);
}

/*
** Checks if Tetrimino fits into grid.
** Returns 1 if there's space and 0 otherwise.
*/

int		ft_check_space(t_grid g, char **shape)
{
	int	x;
	int	y;

	y = 0;
	while (shape[y])
	{
		x = 0;
		while (shape[y][x])
		{
			if (g.grid[g.y + y][g.x + x] != '.' && shape[y][x] != '.')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/*
** Changes to current location on the grid (stored into values x and y).
*/

void	ft_trav_grid(t_grid *g)
{
	if (g->x == g->size - 1)
	{
		g->x = 0;
		g->y++;
	}
	else
		g->x++;
}

/*
** Frees grid and tetriminos array.
*/

void	ft_free_grid_and_tetr(t_grid g, t_tet **t)
{
	int	i;
	int	j;

	i = 0;
	while (g.grid[i])
		free(g.grid[i++]);
	free(g.grid);
	i = 0;
	while (t[i])
	{
		j = 0;
		while (t[i]->shape[j])
			free(t[i]->shape[j++]);
		free(t[i]->shape[j]);
		free(t[i]->shape);
		free(t[i++]);
	}
}
