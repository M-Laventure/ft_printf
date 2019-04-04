/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/04 12:31:02 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <float.h>
#include <math.h>

/*
char *ft_get_stdout(int *pfd, int *save);

int main(void)
{
	printf("the real printf returns:%-12c\n", '\n');
	ft_putchar('\n');
	ft_printf("my printf returns      :%-12c\n", '\n');
	printf("the real printf returns:%4c\n", 'U');
	ft_putchar('\n');
	ft_printf("my printf returns      :%4c\n", 'U');
	ft_printf("my printf : hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	printf("the real one: hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	ft_printf("my printf returns      :test %-12i et %--2.4s %24s !\n", 0, NULL, "coco");
	printf("the real printf returns:test %-12i et %--2.4s %24s !\n", 0, NULL, "coco");
	ft_printf("my printf returns      :toto %###.0o%#.o et %#.1o !\n", 0, 0, 0);
	printf("the real printf returns:toto %###.0o%#.o et %#.1o !\n", 0, 0, 0);	
	ft_printf("my printf returns      :toto %#.o et %#.1o\n", 0, 0);
	printf("the real printf returns:toto %#.o et %#.1o\n", 0, 0);
	ft_printf("my printf returns      :%o\n", -123654789);
	printf("the real printf returns:%o\n", -123654789);	
	return (0);
}
*/

int	main(void)
{
	/*printf("FLT_MAX = %f\n", FLT_MAX);
	printf("DBL_MAX = %lf\n", DBL_MAX);
	printf("LDBL_MAX = %LF\n", LDBL_MAX);*/
	double f;
	int		exp;

	f = -25.3;
	printf("frexp = %f\n, *exp = %d\n", frexp(f, &exp), exp);
	print_df(f);
}
