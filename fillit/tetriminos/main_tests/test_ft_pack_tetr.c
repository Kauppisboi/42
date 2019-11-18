/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_pack_tetr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:51:15 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/13 11:57:49 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int 	main(void)
{
	t_tet	*tetr1 = NULL;
	t_tet	*tetr2 = NULL;
	t_tet	*tetr3 = NULL;
	t_tet	*tetr4 = NULL;
	t_tet	*tetr5 = NULL;
	t_tet	*tetr6 = NULL;
	t_tet	*tetr7 = NULL;
	t_tet	*tetr8 = NULL;
	t_tet	**shape_arr = NULL;

	shape_arr = (t_tet**)malloc(sizeof(t_tet*) * 9);

	tetr1 = (t_tet*)malloc(sizeof(t_tet));
	tetr1->rows = 4;
	tetr1->cols = 1;
	tetr1->shape = (char**)malloc(sizeof(char*) * 5);
	tetr1->shape[0] = ft_strdup("A");
	tetr1->shape[1] = ft_strdup("A");
	tetr1->shape[2] = ft_strdup("A");
	tetr1->shape[3] = ft_strdup("A");
	tetr1->shape[4] = NULL;

	tetr2 = (t_tet*)malloc(sizeof(t_tet));
	tetr2->rows = 1;
	tetr2->cols = 4;
	tetr2->shape = (char**)malloc(sizeof(char*) * 2);
	tetr2->shape[0] = ft_strdup("BBBB");
	tetr2->shape[1] = NULL;

	tetr3 = (t_tet*)malloc(sizeof(t_tet));
	tetr3->rows = 2;
	tetr3->cols = 3;
	tetr3->shape = (char**)malloc(sizeof(char*) * 3);
	tetr3->shape[0] = ft_strdup("CCC");
	tetr3->shape[1] = ft_strdup("..C");
	tetr3->shape[2] = NULL;

	tetr4 = (t_tet*)malloc(sizeof(t_tet));
	tetr4->rows = 2;
	tetr4->cols = 3;
	tetr4->shape = (char**)malloc(sizeof(char*) * 3);
	tetr4->shape[0] = ft_strdup(".DD");
	tetr4->shape[1] = ft_strdup("DD.");
	tetr4->shape[2] = NULL;

	tetr5 = (t_tet*)malloc(sizeof(t_tet));
	tetr5->rows = 2;
	tetr5->cols = 2;
	tetr5->shape = (char**)malloc(sizeof(char*) * 3);
	tetr5->shape[0] = ft_strdup("EE");
	tetr5->shape[1] = ft_strdup("EE");
	tetr5->shape[2] = NULL;

	tetr6 = (t_tet*)malloc(sizeof(t_tet));
	tetr6->rows = 2;
	tetr6->cols = 3;
	tetr6->shape = (char**)malloc(sizeof(char*) * 3);
	tetr6->shape[0] = ft_strdup("FF.");
	tetr6->shape[1] = ft_strdup(".FF");
	tetr6->shape[2] = NULL;

	tetr7 = (t_tet*)malloc(sizeof(t_tet));
	tetr7->rows = 3;
	tetr7->cols = 2;
	tetr7->shape = (char**)malloc(sizeof(char*) * 4);
	tetr7->shape[0] = ft_strdup("GG");
	tetr7->shape[1] = ft_strdup(".G");
	tetr7->shape[2] = ft_strdup(".G");
	tetr7->shape[3] = NULL;

	tetr8 = (t_tet*)malloc(sizeof(t_tet));
	tetr8->rows = 2;
	tetr8->cols = 3;
	tetr8->shape = (char**)malloc(sizeof(char*) * 3);
	tetr8->shape[0] = ft_strdup("HHH");
	tetr8->shape[1] = ft_strdup(".H.");
	tetr8->shape[2] = NULL;




	shape_arr[0] = tetr1;
	shape_arr[1] = tetr2;
	shape_arr[2] = tetr3;
	shape_arr[3] = tetr4;
	shape_arr[4] = tetr5;
	shape_arr[5] = tetr6;
	shape_arr[6] = tetr7;
	shape_arr[7] = tetr8;
	shape_arr[8] = NULL;

	ft_pack_tetr(shape_arr);
	return (0);
}
