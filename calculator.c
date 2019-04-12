/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:20:44 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/12 11:13:55 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

char	*str_max(char *s1, char *s2, int len1, int len2)
{
	if (ft_max(len1, len2) == len1)
		return (s1);
	else
		return (s2);
}

char	*str_sum(char *s1, char *s2)
{
	char	*res;
	int		hold;
	int		i;
	int		len1;
	int		len2;

	hold = 0;
	len1 = ft_strlen(s1) - 1;
	len2 = ft_strlen(s2) - 1;
	i = ft_max(len1, len2) + 1;
	printf("len_max = %d\n", i);
	printf("len1 = %d\n", len1);
	printf("len2 = %d\n", len2);
	if (!(res = ft_strnew(i)))
		return (NULL);
	while (i >= 0)
		res[--i] = 0;
	i = ft_max(len1, len2) + 1;
	while (len1 >= 0 || len2 >= 0 || i >= 0)
	{
			printf("s1[%d] = %d ", len1, s1[len1]);
			printf("+ s2[%d] = %d ", len2, s2[len2]);
			res[i] = res[i] + ((len1 >= 0) ? s1[len1] : 0);
			res[i] = res[i] + ((len2 >= 0) ? s2[len2] : 0);
			if (hold == 1)
			{
				res[i] += 1;
				hold = 0;
			}
			res[i] = res[i] - ((len1 >= 0 && len2 >= 0) ? 48 : 0);
			if (len1 < 0 && len2 < 0)
				res[i] = '0';
			printf("= res[%d] = %c\n", i, res[i]);
			if (len1 >= 0 && len2 >= 0 && ((s1[len1] + s2[len2] + hold - 48) > 57))
			{	
				printf("coucou\n");
				printf("sum = %d + %d + %d - 48\n", s1[len1], s2[len2], hold);
				res[i] = '0';
				hold = 1;
			}
			i--;
			len1--;
			len2--;
	}

	return (res);
}

/*
** calculates the n power of two and returns it in a string
*/
/*
static char	*pow2(int pow)
{
	const char *pow2tab[52] =
	{
		"1", "2", "4", "8", "16", "32", "64", "128", 
		"256", "512", "1024", "2048", "4096", "16384",
		"32768", "65536", "131072", "262144",
		"524288", "1048576", "2097152", "4194304",
		"8388608", "16777216", "33554432", "67108864",
		"134217728", "268435456", "536870912",
		"1073741824", "2147483648", "4294967296",
		"8589934592", "17179869184", "34359738368",
		"68719476736", "137438953472", "274877906944",
		"549755813888", "1099511627776", "2199023255552",
		"4398046511104", "8796093022208", "17592186044416",
		"35184372088832", "70368744177664", "140737488355328",
		"281474976710656", "562949953421312", "1125899906842624",
		"2251799813685248", '/0'
	};
	
	return (pow2tab[pow]);
}

char	*str_ptwo(int exp)
{
	char *res;

	if (exp <= 52)
		return (pow2(exp));
	else
	{
		i = pow2;
		
		while (i < exp)
		{
			
		}
	}

}
*/
