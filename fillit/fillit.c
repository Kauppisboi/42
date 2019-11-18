/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:23:46 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/18 18:24:10 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_print_usage_and_exit(void)
{
	ft_putendl("usage: ./fillit target_file");
	exit(0);
}

int			main(int argc, char **argv)
{
	t_tet	*t[27];
	int		fd;

	if (argc != 2)
		ft_print_usage_and_exit();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_err_and_exit();
	ft_read_input_and_validate(fd, t);
	ft_pack_tetr(t);
	return (0);
}
