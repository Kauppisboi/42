/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tet_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:57:04 by jrignell          #+#    #+#             */
/*   Updated: 2019/11/18 19:43:45 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Returns the rightmost x coordinate.
*/

static int	ft_get_rightmost_x(char **array)
{
	int		i;
	int		j;
	int		hash;
	int		x;

	i = -1;
	hash = 0;
	x = 0;
	while (array[++i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '#')
			{
				++hash;
				if (x < j)
					x = j;
			}
			if (hash == 4)
				return (x);
			++j;
		}
	}
	return (-1);
}

/*
** Returns the leftmost x coordinate.
*/

static int	ft_get_leftmost_x(char **array)
{
	int		i;
	int		j;
	int		hash;
	int		x;

	i = -1;
	hash = 0;
	x = 5;
	while (array[++i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '#')
			{
				++hash;
				if (x > j)
					x = j;
			}
			if (hash == 4)
				return (x);
			++j;
		}
	}
	return (-1);
}

/*
** Places the highest and lowest y coordinates into int array.
*/

static void	ft_get_highest_and_lowest_y(char **array, int *top, int *low)
{
	int		i;
	int		j;
	int		hash;

	i = 0;
	hash = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '#' && hash == 0)
				*top = i;
			if (array[i][j] == '#')
				++hash;
			if (hash == 4)
			{
				*low = i;
				return ;
			}
			++j;
		}
		++i;
	}
}

/*
** Returns properly formated string for tetr->shape.
*/

char		*ft_create_str(char *s, int n, char c)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = (char*)malloc(sizeof(char) * (n + 1))))
		ft_err_and_exit();
	while (i < n)
	{
		cpy[i] = s[i] == '#' ? c : '.';
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

/*
** Main function of this file. First, find the shape of tetrimino.
** Int array (dim) stores information about this.
*/

void		ft_create_tet_struct(char **array, t_tet **tetr_array)
{
	t_tet		*tetr;
	int			dim[4];
	int			y;
	static int	i = 0;

	tetr = NULL;
	ft_get_highest_and_lowest_y(array, &dim[0], &dim[1]);
	dim[2] = ft_get_leftmost_x(array);
	dim[3] = ft_get_rightmost_x(array);
	tetr = (t_tet*)malloc(sizeof(t_tet));
	tetr->rows = FT_ABS((dim[0] - dim[1]) + 1);
	tetr->cols = FT_ABS((dim[2] - dim[3]) + 1);
	if (!(tetr->shape = (char**)malloc(sizeof(char*) * (tetr->rows + 1))))
		ft_err_and_exit();
	y = -1;
	while (++y < tetr->rows)
		tetr->shape[y] = ft_create_str(&array[dim[0] + y][dim[2]],
									tetr->cols, 'A' + i);
	tetr->shape[y] = NULL;
	tetr_array[i++] = tetr;
	if (i == 27)
		ft_err_and_exit();
	tetr_array[i] = NULL;
}
