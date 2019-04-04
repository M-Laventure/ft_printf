/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:44:53 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/04 12:31:02 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** reminder of float limits (float, double and long double) :
** FLT_MAX
** DBL_MAX
** LDBL_MAX
*/

static char	*dftoa(double x)
{
	int					i;
	unsigned long		tmp;
	char				*nb_str;

	i = 0;
	if (!(nb_str = (char *)malloc(sizeof(char) * 65)))
		return (NULL);
	tmp = *(unsigned long *)(&x);
	while (tmp)
	{
		if (tmp & 1)
			nb_str[i] = '1';
		else
			nb_str[i] = '0';
		printf("nb_str[%d] = %c\n", i, nb_str[i]);
		tmp >>= 1;
		i++;
	}
	nb_str[i] = '\0';
	ft_strrev(nb_str);
	return (nb_str);
}

static int	get_exp(char *exp_str, int sign)
{
	int nb;
	int i;
	int j;
	const int pow2tab[12] =
	{
		1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048
	};
	
	i = 0;
	j = 0;
	nb = 0;
	while (exp_str[i] != '\0')
	{
		if (exp_str[i] == '1')
		{
		printf("exp_str[%d] = %c\n", i, exp_str[i]);
		printf("pow2tab[%d] = %i\n", i, pow2tab[i]);
			nb += pow2tab[j];
			j++;
		printf("nb = %d\n", nb);
		}
		i++;
	}
	(sign = 0) ? (nb -= 1023) : (nb += 1023);
	return (nb);
}

static double ft_frexpl(double x, int *exp)
{
	char *nb_str;
	char mantissa[54]; //if 64 bits, mantissa[23] else if 80 bits, mantissa[52] and exponent[11]
	char exp_str[12];
	int	sign;
	double res;

	(x < 0) ? (sign = 1) : (sign = 0);
	mantissa[53] = '\0';
	exp_str[11] = '\0';
	if (!(nb_str = dftoa(x)))
		return (0);
	printf("nb_str = %s\n", nb_str);
	nb_str += sign;
	if (!(ft_strncpy(exp_str, nb_str, 11)))
		return (0);
	printf("exp_str = %s\n", exp_str);
	nb_str += 11 + sign;
	if (!(ft_strncpy(mantissa, nb_str , 52)))
		return (0);
	*exp = get_exp(exp_str, sign);
	res = 0;
	nb_str = NULL;
	return (res);
}

void	print_df(/*t_flags *flags,*/ double x)
{
	int exp;
	
	printf("dtfoa returns : %s\n", dftoa(x));
	ft_frexpl(x, &exp);
	printf("my *exp = %d\n", exp);

}

/*void	print_ldf(t_flags *flags, long double x)
{

}
static long double ft_frexpl(long double, int *exp)
{

}
*/


