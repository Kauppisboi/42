/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_find_highest_l_leftmost_r.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:10:40 by jrignell          #+#    #+#             */
/*   Updated: 2019/11/13 20:50:37 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		main(void)
{
	char *str = "...#\n..##\n...#\n....\n";
	
	char **array;

	array = ft_strsplit(str, '\n');
	ft_create_tet_struct(array);
	return (0);
}
