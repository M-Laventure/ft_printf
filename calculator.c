/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:20:44 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/12 18:55:18 by mybenzar         ###   ########.fr       */
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
			if (hold == 1)
			{
				res[i] += 1;
				hold = 0;
			}
			if (len1 >= 0 && len2 >= 0 && ((s1[len1] + s2[len2] + hold - 48) > 57))
			{	
				printf("sum = %d + %d + %d - 48\n", s1[len1], s2[len2], hold);
				res[i] = (s1[len1] + s2[len2] + hold - 48) % 10;
				hold = 1;
			}
			else
			{
				res[i] = res[i] + ((len1 >= 0) ? s1[len1] : 0);
				res[i] = res[i] + ((len2 >= 0) ? s2[len2] : 0);
			}
			res[i] = res[i] - ((len1 >= 0 && len2 >= 0) ? 48 : 0);
			if (len1 < 0 && len2 < 0)
				res[i] = '\0';
			i--;
			len1--;
			len2--;
	}
	return (res);
}
/*
char	*str_mult(char *s1, char *s2)
{	
	char	*sum;
	char	*res;
	int		len1;
	int		len2;
	int		hold;

	i = len1 + len2;
	res = ft_strnew(i);
	sum = ft_strnew(ft_max(len1, len2));
	while (len1 >= 0 || len2 >= 0 || i >= 0)
	{
		sum[i] = sum[i] * s1[i] 
	}

}

*/
/*
** calculates the n power of two and returns it in a string
*/
/*
char	*str_ptwo(int exp)
{
}
*/
