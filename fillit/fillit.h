/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:50:50 by jrignell          #+#    #+#             */
/*   Updated: 2019/11/18 18:12:30 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>
# define FT_ABS(x) (x > 0 ? x : -x)

typedef struct	s_tet
{
	int			rows;
	int			cols;
	int			placed;
	char		**shape;
}				t_tet;

typedef struct	s_grid
{
	int			x;
	int			y;
	int			size;
	int			tetr_left;
	char		**grid;
}				t_grid;

t_grid			ft_return_minimum_grid(int tetr_count);
void			ft_read_input_and_validate(int fd, t_tet **tetr_array);
void			ft_create_tet_struct(char **array, t_tet **tetr_array);
void			ft_err_and_exit(void);
void			ft_grow_grid(t_grid *g);
void			ft_print_grid(char **grid);
void			ft_pack_tetr(t_tet **tetriminos);
void			ft_print_tetriminos(t_tet **tetriminos);
int				ft_return_unplaced(t_tet **t);
int				ft_check_space(t_grid g, char **shape);
void			ft_trav_grid(t_grid *g);
void			ft_free_grid_and_tetr(t_grid g, t_tet **t);

#endif
