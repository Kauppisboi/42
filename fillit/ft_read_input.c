/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:22:44 by jrignell          #+#    #+#             */
/*   Updated: 2019/11/18 19:46:03 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks whether array has 6 or 8 adjacent hashes '#'. If not, error.
*/

static void	ft_check_number_of_adjacent(char **array)
{
	int		adj;
	int		i;
	int		j;

	adj = 0;
	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (array[i][j] == '#' && j < 3 && array[i][j + 1] == '#')
				++adj;
			if (array[i][j] == '#' && j > 0 && array[i][j - 1] == '#')
				++adj;
			if (array[i][j] == '#' && i > 0 && array[i - 1][j] == '#')
				++adj;
			if (array[i][j] == '#' && i < 3 && array[i + 1][j] == '#')
				++adj;
			++j;
		}
		++i;
	}
	if (!(adj == 6 || adj == 8))
		ft_err_and_exit();
}

/*
** There should be 4 hashes '#' and 12 dots '.' in every string. Number of
** new lines depend on whether the existing string is last or not. Last one has
** 4 new lines and others have 5 new lines. If these conditions aren't met,
** error.
*/

static void	ft_check_hash_dot_nl(char *s, int last)
{
	int		hash;
	int		dot;
	int		nl;

	hash = 0;
	dot = 0;
	nl = 0;
	while (*s && (*s == '#' || *s == '.' || *s == '\n'))
	{
		if (*s == '#')
			++hash;
		if (*s == '.')
			++dot;
		if (*s == '\n')
			++nl;
		++s;
	}
	if (last && (nl != 4 || hash != 4 || dot != 12))
		ft_err_and_exit();
	if (!last && (nl != 5 || hash != 4 || dot != 12))
		ft_err_and_exit();
}

/*
** New lines should be found from indexes [4], [9], [14] and [19]. If not,
** error.
** Also, function checks if last tetrimino has 20 characters. If not, error.
** All the other tetrimino (exluding last one), should have new line in index
** [20]. If not, error.
*/

static void	ft_check_buf(char *s, int last)
{
	if (!(s[4] == '\n' && s[9] == '\n' && s[14] == '\n' && s[19] == '\n'))
		ft_err_and_exit();
	if (last && ft_strlen(s) != 20)
		ft_err_and_exit();
	else if (!(s[20] == '\n') && !last)
		ft_err_and_exit();
}

/*
** Frees the allocated array.
*/

static void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array[i]);
	free(array);
}

/*
** Main function for this file. Reads 21 bytes in every iteration. Validates
** the read buf and after this passes the buf, of which have been converted
** into 2D-array, to ft_check_number_of_adjacent(). Lastly, function passes the
** array to ft_create_tet_struct()-function which ultimately creates
** tetriminos struct which have been used in the last section,
** ft_pack()function.
*/

void		ft_read_input_and_validate(int fd, t_tet **tetr_array)
{
	char	buf[21 + 1];
	int		ret;
	int		last;
	char	**array;

	last = 0;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		if (ret < 0 || fd < 0)
			ft_err_and_exit();
		buf[ret] = '\0';
		if (ret == 20)
			last = 1;
		ft_check_buf(buf, last);
		ft_check_hash_dot_nl(buf, last);
		array = ft_strsplit(buf, '\n');
		ft_check_number_of_adjacent(array);
		ft_create_tet_struct(array, tetr_array);
		ft_free_array(array);
	}
	if (ret != 0 || last != 1)
		ft_err_and_exit();
}
