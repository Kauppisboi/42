/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:26:13 by jrignell          #+#    #+#             */
/*   Updated: 2019/12/27 13:35:18 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

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
/*
	char *str1 = "Moi";
	printf("Hello %p %c %s\n", str1, 'a', str1);
	ft_printf("Hello %p %c %s\n", str1, 'a', str1);
*/

/*
**	CHECK %hhd and %lld
*/
/*
	printf("Number x is %hhd in hhd\nAnd %lld in lli\n", (char)'b', (long long)3132132321321);
	ft_printf("Number x is %hhd in hhd\nAnd %lli in lli\n\n", (char)'b', (long long)3132123321321);
*/
/*
**	CHECK %hho and %llo
** %d--> for int
** %u--> for unsigned int
** %ld--> for long int
** %lu--> for unsigned long int
** %lld--> for long long int
** %llu--> for unsigned long long int
*/

//	int i =	printf("%i %o %u *%x %X\n", 213, 165, 123132, 159, 465);
//	printf("Real printf returns %d\n", i);
//	ft_printf("%i %o %u %x %X\n", 213, 165, 123132, 159, 465);

/*
**	CHECK %hhu and %llu
*/
/*
	printf("%llu\n", (unsigned long long)ULONG_MAX+1);
	ft_printf("%llu\n", (unsigned long long)ULONG_MAX+1);
*/
/*
**	CHECK %llx, %llX, %hhx and %hhX
*/
/*
	unsigned char eena = (unsigned char)4200;
	printf("%hhx %hhX %llx %llX\n", eena, (unsigned char)255, (unsigned long long)ULONG_MAX, (unsigned long long)-45);
	ft_printf("%hhx %hhX %llx %llX\n", eena, (unsigned char)255, (unsigned long long)ULONG_MAX, (unsigned long long)-45);
*/
/*
**	CHECK %hd %ld %hi and %li
*/
/*
	printf("%hd %ld %hi %li\n", (short)(SHRT_MAX+1), (long)(LONG_MIN), (short)(SHRT_MIN-1), (long)(LONG_MAX));
	ft_printf("%hd %ld %hi %li\n", (short)(SHRT_MAX+1), (long)(LONG_MIN), (short)(SHRT_MIN-1), (long)(LONG_MAX));
*/
/*
**	CHECK %ho %lo with SHRT_MAX, LONG_MIN, SHRT_MIN, LONG_MAX
*/
/*
	printf("%ho %lo %ho %lo\n", (short)(SHRT_MAX+1), (long)(LONG_MIN), (short)(SHRT_MIN-1), (long)(LONG_MAX));
	ft_printf("%ho %lo %ho %lo\n", (short)(SHRT_MAX+1), (long)(LONG_MIN), (short)(SHRT_MIN-1), (long)(LONG_MAX));
*/
/*
**	CHECK %hu %lu with INT_MAX, LONG_MAX, ULONG_MAX, ULONG_MAX
*/
/*
	printf("%hu %lu %hu %lu\n", (short)(INT_MAX), (long)(LONG_MAX), (short)(ULONG_MAX), (long)(ULONG_MAX));
	ft_printf("%hu %lu %hu %lu\n", (short)(INT_MAX), (long)(LONG_MAX), (short)(ULONG_MAX), (long)(ULONG_MAX));
*/
/*
**	CHECK %hx %hX %lx %lX with INT_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX
*/
/*
	printf("%hx %hX %lx %lX\n", (short)(INT_MAX), (short)(ULONG_MAX), (long)(ULONG_MAX), (unsigned long)(ULONG_MAX));
	ft_printf("%hx %hX %lx %lX\n", (short)(INT_MAX), (short)(ULONG_MAX), (long)(ULONG_MAX),  (unsigned long)(ULONG_MAX));
*/
/*
**	CHECK %d %i %o %u %x %X with LONG_MAX, LONG_MIN, 16, (unsigned)(-1)
*/
/*
	printf("%d %i %o %u %x %X\n", (int)(LONG_MAX), (int)(LONG_MIN), (signed)(16), (unsigned)(-1), 2, 3);
	ft_printf("%d %i %o %u %x %X\n", (int)(LONG_MAX), (int)(LONG_MIN), (signed)(16), (unsigned)(-1), 2, 3);
*/
/*
	printf("\n%.10lf\n", (double)0.3);
	float y;
	int i = (3 << 2);

	y = i;
	for (int j = 0; j < 5; j++)
	{
		printf("%d %f     ", i, y);
		printf("%08x %08x\n", i, *((int*)&y));
		y += 1.0;
		i += 1;
	}
	ft_putnbr(LONG_MIN);
*/

	printf("Two spaces%3d\n", 10);
	int i = ft_strlen("10");
	printf("%d\n", i);
	return (0);
}