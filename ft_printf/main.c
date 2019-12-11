/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:26:13 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/11 20:19:38 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)

{
/*
	char a = 'a';
	char c = 'c';
	printf("Hello %c %c %c\n", a, 'b', c);
	ft_printf("Hello %c %c %c\n", a, 'b', c);
*/
/*
	char *str = "World";
	printf("Hello %s\n", str);
	ft_printf("Hello %s\n", str);
	printf("Hello %s\n", "Mellou");
	ft_printf("Hello %s\n", "Mellou");
*/	
/*
**	CHECK %p %c %s
*/
	char *str1 = "Moi";
	printf("Hello %p %c %s\n", str1, 'a', str1);
	ft_printf("Hello %p %c %s\n", str1, 'a', str1);


	return (0);
}