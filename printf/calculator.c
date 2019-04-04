/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:20:44 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/04 21:32:10 by mybenzar         ###   ########.fr       */
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
	int		len;
	int		len1;
	int		len2;
	int		j;

	hold = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = ft_max(len1, len2) + 1;
	printf("len_max = %d\n", len);
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len != 0 && s1 && s2)
	{
		if ((s1[len] + s2[len] + hold - 48) <= 57)
		{
			res[len] = s1[len] + s2[len] - 48 + hold;
			hold = 0;
		}
		else
		{
			res[len] = '0';
			hold = 1;
		}
		len--;
		printf("res[%d] = %c\n", len, res[len]);
	}
	if (s1[len] == '\0' && s2)
	{
		j = len;
		while (s2[j] != '\0')
			res[len] = s2[j++];
		printf("j = %d\n", j);
	}
	else if (s2[len] == '\0' && s1)
	{
		j = len;
		while (s1)
			res[len--] = s1[j--];
	}
/*	


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
	i++;
	if (s1[i] == '\0' && s2[i] != '\0')
	{
	j = i;
	while (s2[j] != '\0')
	res[i++] = s2[j++];
	printf("j = %d\n", j);
	}
	else if (s2[i] == '\0' && s1[i] != '\0')
	{
	j = i;
	while (s1[j++] != '\0')
	res[j] = s1[j];
	}
	printf("res[%d] = %c\n", i, res[i]);
	}
	*/
return (res);
}
