/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:33:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/10 18:06:46 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/includes/libft.h"

#include <stdio.h> // delete this

typedef struct			s_format
{
	char				*s_str;
	int					format;
	int					len;
	int					prec;
	int					width;
	int					hash;
	int					space;
	int					zero;
	int					minus;
	int					plus;
	int					sign;
	int					dot;
	long long			num;
	long double			f_num;
	unsigned long long	u_num;
	char				*nbr;
	int					null;
	int					length;
}						t_format;

/*
********************************************************************************
**                                                                            **
**                         FORMAT FUNCTIONS                                   **
**                                                                            **
********************************************************************************
*/

int						ft_printf(const char *format, ...);
int						diouxf(t_format *f, va_list ap);
int						ft_parse_csp_percent(t_format *f, va_list ap);
int						ft_parse_f(t_format *f, va_list ap);
int						check_bef_format(t_format *f, long long print);
int						check_bef_format_u(t_format *f, unsigned long long print);
void					hh_h_ll_l(t_format *f, long long print, int base, int upper);
void					hh_h_ll_l_u(t_format *f, unsigned long long p, int b, int up);
void					ft_parse_precision(t_format *f);
void					ft_parse_flags(t_format *f);
void					ft_parse_width(t_format *f);

/*
********************************************************************************
**                                                                            **
**                         HELPER FUNCTIONS                                   **
**                                                                            **
********************************************************************************
*/

int						ft_check_if_width(t_format *f);
int						iszero(t_format *f);
int						ft_if_precision_diouxs(t_format *f);
void					swap_chars(t_format *f);
void					swap_0x(t_format *f);
int						which_len(t_format *f);
void					ft_put_zero(t_format *f);
void					ft_str_free(t_format *f, char *tmp, int i, int j);
void					ft_struct_del(t_format *f);
//void					ft_set_null(char **ptr);
void					ft_set_struct_null(t_format **f);

/*
********************************************************************************
**                                                                            **
**                         BONUS FUNCTIONS                                    **
**                                                                            **
********************************************************************************
*/

//int					printf_bonus(t_format *f, unsigned long long print);

#endif
