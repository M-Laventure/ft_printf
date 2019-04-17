/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:20:44 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/17 12:09:53 by mybenzar         ###   ########.fr       */
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

void	vlq_initialize(char *vlq, int c, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		vlq[i] = c;
		//	printf("in vlq initialize vlq[%d] = %d\n", i, vlq[i]);
		i++;
	}
	vlq[i] = '\0';
}

char	*str_max(char *s1, char *s2, int len1, int len2)
{
	if (ft_max(len1, len2) == len1)
		return (s1);
	else
		return (s2);
}

void	calc_info(t_calc *info, char *s1, char *s2)
{
	int i;

	i = 0;
	info->len1 = ft_strlen(s1);
	info->len2 = ft_strlen(s2);
	info->max = ft_max(info->len1, info->len2);
	info->min = ft_min(info->len1, info->len2);
	info->sum = info->len1 + info->len2;
	if (!(info->ten = ft_strnew(info->len2)))
		return ;
	while (info->ten[i] != '\0')
		info->ten[i++] = 0;
	info->ten_dec = 1;
}

void	free_calc(t_calc *info)
{
	ft_bzero(info, sizeof(t_calc));
	free(info);
}

char	*vlq_sum(char *s1, char *s2)
{
	char	*res;
	int		hold;
	int		i;
	t_calc	*info;
	//	int		len1;
	//	int		len2;

	//	len1 = ft_strlen(s1) - 1;
	//	len2 = ft_strlen(s2) - 1;
	if (DEBUG)
	{
		printf("\n\nI'm in vlq_sum\n");
		printf("sum = %s et res = %s\n", s1, s2);
	}
	if (!(info = (t_calc *)malloc(sizeof(t_calc))))
		return (NULL);
	calc_info(info, s1, s2);
	info->len1 -= 1;
	info->len2 -= 1;
	i = info->max + 1;
	//	i = ft_max(len1, len2) + 1;
	if (DEBUG)
	{
		printf("len_max = %d\n", i);
		printf("len1 = %d\n", info->len1);
		printf("len2 = %d\n", info->len2);
	}
	if (!(res = ft_strnew(i)))
		return (NULL);
	vlq_initialize(res, 0, i);
	i--;
	while (info->len1 >= 0 || info->len2 >= 0 || i >= 0)
	{
		hold = 0;
		if (info->len1 >= 0 && info->len2 >= 0 && ((s1[info->len1] + s2[info->len2] + res[i] - 48) > 57))
		{	
			res[i] += s1[info->len1] + s2[info->len2] - 10 - 48;
			if (DEBUG)
				printf("res[%d] = %d\n", i, res[i]);
			hold = 1;
		}
		/*	else if (len1 < 0 && len2 < 0)
			res[i] = 0;*/
		else
		{
			printf("step0 res[%d] = %d\n", i, res[i]);
			res[i] = res[i] + ((info->len1 >= 0) ? s1[info->len1] : 0);
			printf("step1 res[%d] = %d\n", i, res[i]);
			res[i] = res[i] + ((info->len2 >= 0) ? s2[info->len2] : 0);
			printf("step2 res[%d] = %d\n", i, res[i]);
			res[i] = res[i] - ((info->len1 >= 0 && info->len2 >= 0) ? 48 : 0);
			if (DEBUG)
				printf("apres le else res[%d] = %d\n", i, res[i]);
		}
		i--;
		if (i >= 0)
			res[i] += hold;
		info->len1--;
		info->len2--;
	}
	i = 0;
	while (res[i] == 0)
		i++;
	free_calc(info);
	return (res + i);
}
/*
   char	vlq_mult_conv(char a, char b)
   {
   return (a * b + 48 * (1 - 48 * (48 * (a + b))))
   }*/

void	vlq_tmp_conv(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
		s1[i++] -= 48;
	i = 0;
	while (s2[i])
		s2[i++] -= 48;
}

void	vlq_tmp_conv_rev(char *s, int size)
{
	int i;

	i = 0;
	printf("\n\nin vlq_tmp_conv_rev\n");
	printf("size = %d\n", size);
	while (i < size)
	{
		s[i] += 48;
		printf("s[%d] = %c\n", i, s[i]);
		i++;
	}
}

char	*vlq_mult(char *s1, char *s2)
{	
	char	*sum;
	char	*res;
	t_calc	*info;
	int		j;
	int		i;
	int		hold;

	if (DEBUG)
		printf("\n\nI'm in vlq_mult\n");
	if (!(info = (t_calc *)malloc(sizeof(t_calc))))
		return (NULL);
	calc_info(info, s1, s2);
	info->len1 -= 1;
	info->len2 -= 1;
	i = info->sum;
	if (DEBUG)
	{
		printf("len_max = %d\n", i);
		printf("len1 = %d\n", info->len1);
		printf("len2 = %d\n", info->len2);
	}
	if (!(res = ft_strnew(i + 1)))
		return (NULL);
	if (!(sum = ft_strnew(info->max)))
		return (NULL);
	// l'idee est de faire tous les calculs sans les 48 et de les remettre a la fin pour simplifier
	vlq_tmp_conv(s1, s2);
	vlq_initialize(sum, 0, info->max);
	while (info->len2 >= 0 || i >= 0)
	{
		vlq_initialize(res, 0, info->sum + 1);
		j = info->len1;
		while (j >= 0)
		{
			hold = 0;
			if (j >= 0 && info->len2 >= 0 && s1[j] * s2[info->len2] + res[i] >= 10)
			{
				hold = (res[i] + s1[j] * s2[info->len2]) / 10;
				res[i] = (res[i] + s1[j] * s2[info->len2]) % 10;
				if (DEBUG)
				{
					printf("dans le if, hold = %d\n", hold);
					printf("dans le if, res[%d] = %d\n", i, res[i]);
				}
			}
			else if (info->len2 < 0)
				res[i] = 0;
			else
			{
				printf("before here res[%d] = %d\n", i, res[i]);
				res[i] = ((j >= 0) ? s1[j] : 1);
				printf("here res[%d] = %d\n", i, res[i]);
				res[i] = res[i] * ((info->len2 >= 0) ? s2[info->len2] : 1);
				if (DEBUG)
				{
					printf("apres le else s1[%d] = %d\n", j, s1[j]);
					printf("apres le else s2[%d] = %d\n", info->len2, s2[info->len2]);
					printf("apres le else res[%d] = %d\n", i, res[i]);
				}
			}
			i--;
			res[i] += hold;
			j--;
		}
		// multiply by 10 the intermediate result only after first iteration
		//printf("info->tendec = %d\n", info->ten_dec);
		//res = ft_strncat(res, info->ten, info->ten_dec++);
		if (DEBUG)
			printf("res[%d] after strncat  = %d\n", i+2, res[i+2]);
		vlq_tmp_conv_rev(res, info->sum + 1);
		if (DEBUG)
			printf("res after tmp_conv = %s\n", res);
		if (info->len2 == 0 && info->ten_dec == 2)
		{
			i = 0;
			while (res[i] == '0')
				i++;
			return (res + i);
		}
		//if (info->ten_dec >= 2)
			sum = vlq_sum(sum, res);
		info->len2--;
		i++;
		if (DEBUG)
		{
			printf("sum = %s\n", sum);
			printf("len2= %d\n", info->len2);
			printf("i = %d\n", i);
		}
	}
	i = 0;
	while (sum[i] == '0')
		i++;
	free_calc(info);
	return (sum + i);
}

