/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:33:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/01/03 12:00:49 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/includes/libft.h"
# define FT_TYPES "diouxXf"

# include <stdio.h> // DEV

/*
typedef struct	s_struct
{
	int		parameter;
	int		flags;
	int		width;
	int		precision;
	int		length;
	int		type;
}				t_syntax;
*/

int					ft_printf(const char *format, ...);
int					ft_parse_diouxXf(char *str_sub, va_list ap, unsigned len);
long long int		ft_parse_hh_h_ll_l(char *sub_str, long long print, unsigned len, unsigned min_i);
unsigned long long	ft_parse_hh_h_ll_l_u(char *sub_str, unsigned long long print,
									unsigned len, unsigned min_i);
int					ft_check_if_dot(char *sub_str);
int					ft_return_flag(char *sub_str);
//t_syntax		ft_put_zero(void);

#endif