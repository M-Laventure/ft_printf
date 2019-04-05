/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:20:44 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/05 12:37:08 by mybenzar         ###   ########.fr       */
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
	i = ft_max(len1, len2) + 2;
	printf("len_max = %d\n", i);
	printf("len1 = %d\n", len1);
	printf("len2 = %d\n", len2);
	if (!(res = ft_strnew(i)))
		return (NULL);
	while (i >= 0)
		res[--i] = 0;
	i = ft_max(len1, len2) + 2;
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
