/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:20:44 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/04 17:36:00 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

char	*str_sum(char *s1, char *s2)
{
	char	*res;
	int		hold;
	int		len_max;
	int		len1;
	int		len2;
	int		i;
	//int		j;

	//j = 0;
	hold = 0;
	i = 0;
	flag = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len_max = ft_max(len1, len2) + 1;
	printf("len = %d\n", len);
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (len1 >= len2)
		ft_memcpy(res, s1, len - 1);
	else
	{
		ft_memcpy(res, s2, len - 1);
		flag = 1;
	}
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((s1[i] + s2[i] + hold - 48) <= 57)
		{
			res[i] = s1[i] + s2[i] - 48 + hold;
			hold = 0;
		}
		else
		{
			res[i] = '0';
			hold = 1;
		}
		printf("res[%d] = %c\n", i, res[i]);
		i++;
	}
	return (res);
}
