/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pack_tetr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:52:06 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/18 18:49:15 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Attempts to place tetrimino inside grid.
** Returns 1 if placement was succesful (enough space) or 0 otherwise.
*/

static int	ft_place_tetr(t_grid *g, t_tet *t)
{
	int	x;
	int	y;
	int	enough_space;

	y = 0;
	if ((enough_space = ft_check_space(*g, t->shape)))
		while (t->shape[y])
		{
			x = 0;
			while (t->shape[y][x])
			{
				if (g->grid[g->y + y][g->x + x] == '.')
					g->grid[g->y + y][g->x + x] = t->shape[y][x];
				x++;
			}
			y++;
		}
	if (enough_space)
	{
		g->tetr_left--;
		t->placed = 1;
	}
	return (enough_space);
}

/*
** Attempts to place tetrimino inside grid.
*/

static int	ft_try_place_tetr(t_grid *g, int cur, t_tet **t)
{
	if (t[cur]->cols <= (g->size - g->x) && \
		t[cur]->rows <= (g->size - g->y) && \
		ft_place_tetr(g, t[cur]))
		return (1);
	return (0);
}

/*
** Clears tetrimino from grid.
*/

static void	ft_clr_tetr(t_grid *g, t_tet *tetr)
{
	int		x;
	int		y;

	y = 0;
	while (tetr->shape[y])
	{
		x = 0;
		while (tetr->shape[y][x])
		{
			if (tetr->shape[y][x] != '.')
				g->grid[g->y + y][g->x + x] = '.';
			x++;
		}
		y++;
	}
	tetr->placed = 0;
	g->tetr_left++;
}

/*
** Recursive function traversing through the grid, trying to place
** tetriminos on the way. It uses recursive backtracking for going through
** different ordering of tetriminos. Finally returns either 1 for success
** or 0 for failure.
*/

static int	ft_pack(t_grid g, t_tet **t)
{
	int	cur;

	g.y = 0;
	g.x = 0;
	if (g.tetr_left == 0)
		return (1);
	cur = ft_return_unplaced(t);
	while (g.y != g.size)
	{
		if (ft_try_place_tetr(&g, cur, t))
		{
			if (ft_pack(g, t))
				return (1);
			ft_clr_tetr(&g, t[cur]);
		}
		ft_trav_grid(&g);
	}
	return (0);
}

/*
** Initialization function for solving logic.
** Packs the tetriminos and prints the solution.
*/

void		ft_pack_tetr(t_tet **t)
{
	t_grid	g;
	int		tetr_count;

	tetr_count = 0;
	while (t[tetr_count])
		tetr_count++;
	g = ft_return_minimum_grid(tetr_count);
	while (ft_pack(g, t) == 0)
	{
		ft_grow_grid(&g);
	}
	ft_print_grid(g.grid);
	ft_free_grid_and_tetr(g, t);
}
