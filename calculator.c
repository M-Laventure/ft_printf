/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:20:44 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/15 15:39:55 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int		ft_min(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

void	vlq_initialize(char *vlq)
{
	int i;

	i = 0;
	while (vlq[i] != 0)
		vlq[i++] = 0;
}

char	*str_max(char *s1, char *s2, int len1, int len2)
{
	if (ft_max(len1, len2) == len1)
		return (s1);
	else
		return (s2);
}

char	*vlq_sum(char *s1, char *s2)
{
	char	*res;
	int		hold;
	int		i;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1) - 1;
	len2 = ft_strlen(s2) - 1;
	i = ft_max(len1, len2) + 1;
	printf("len_max = %d\n", i);
	printf("len1 = %d\n", len1);
	printf("len2 = %d\n", len2);
	if (!(res = ft_strnew(i)))
		return (NULL);
	vlq_initialize(res);
	res[i] = '\0';
	i--;
	while (len1 >= 0 || len2 >= 0 || i >= 0)
	{
			hold = 0;
			if (len1 >= 0 && len2 >= 0 && ((s1[len1] + s2[len2] + res[i] - 48) > 57))
			{	
				res[i] += s1[len1] + s2[len2] - 10 - 48;
				printf("res[%d] = %d\n", i, res[i]);
				hold = 1;
			}
		/*	else if (len1 < 0 && len2 < 0)
				res[i] = 0;*/
			else
			{
				res[i] = res[i] + ((len1 >= 0) ? s1[len1] : 0);
				res[i] = res[i] + ((len2 >= 0) ? s2[len2] : 0);
				res[i] = res[i] - ((len1 >= 0 && len2 >= 0) ? 48 : 0);
				printf("apres le else res[%d] = %d\n", i, res[i]);
			}
			i--;
			res[i] += hold;
			printf("res[%d] = %d\n", i, res[i]);
			len1--;
			len2--;
	}
	return (res);
}

char	vlq_mult_conv(char a, char b)
{
	return (a * b + 48 * (1 - 48 * (48 * (a + b))))
}

char	*vlq_mult(char *s1, char *s2)
{	
	char	*sum;
	char	*res;
	int		len1;
	int		len2;
	int		hold;

	i = len1 + len2;
	res = ft_strnew(i);
	sum = ft_strnew(ft_max(len1, len2));
	sum[i] = 1;
	while (len1 >= 0 || len2 >= 0 || i >= 0)
	{
		// l'idee est de faire tous les calculs sans les 48 et de les remettre a la fin pour simplifier
		sum[i] = vlq_mult_conv(sum[i], s1[i]);
		ret = 
		sum[i] = sum[i] * s2[i];
	}

}

/*
** calculates the n power of two and returns it in a string
*/
/*
char	*str_ptwo(int exp)
{
}
*/
