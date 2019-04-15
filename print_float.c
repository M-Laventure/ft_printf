/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:44:53 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/15 15:39:56 by mybenzar         ###   ########.fr       */
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

static char	*ft_dftoa(double x)
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

static int pow2(int pow)
{
	const int pow2tab[52] =
	{
		1, 2, 4, 8, 16, 32, 64, 128, 
		256, 512, 1024, 2048, 4096, 16384,
	};

	return (pow2tab[pow]);
}

static int	get_exp(char *exp_str)
{
	int nb;
	int i;
	int j;

	j = 10;
	i = 0;
	nb = 0;
	while (exp_str[i] != '\0')
	{
		if (exp_str[i] == '1')
			nb = nb + pow2(j);
	//	printf("nb = %d\n", nb);
	//	printf("i = %d\n", i);
		i++;
		j--;
	}
	nb -= 1023;
	//(sign = 0) ? (nb -= 1023) : (nb += 1023);
	return (nb);
}

char	*ft_bintovlq(char *vlq, int base)
{
	int i;
	char *ret;

	i = 0;
	if (!(ret = ft_strnew(ft_strlen(vlq) + 1)))
		return (NULL);
	vlq_initialize(ret);
	while (vlq[i] != 0)
	{
		ret[i] = vlq_add(ret[i], vlq_mult(vlq[i], '2'));
		i++;
	}
}

char  *get_res(char *mantissa, int exp)
{
	char	*res;
	char	*left;
	char	right[53 - exp - 1];

	if (!(left = ft_strnew(exp + 1)))
		return (0);
	// multiply by 2^52 to get MSB
	left[0] = '1';
	// multiply by exp to get floating point
	if (!(ft_strncat(left, mantissa, exp)))
		return (0);
	printf("left = %s\n", left);
	mantissa += exp;
	if (!(ft_strncpy(right, mantissa, 52 - exp - 1)))
		return (0);
	printf("right = %s\n", right);
	res += ft_itoabase(left, 
	return (res);
}
static double ft_frexp(double x, int *exp)
{
	char *nb_str;
	char mantissa[54]; //if 64 bits, mantissa[23] else if 80 bits, mantissa[52] and exponent[11]
	char exp_str[12];
	int	sign;
	double res;

	(x < 0) ? (sign = 1) : (sign = 0);
	mantissa[53] = '\0';
	exp_str[11] = '\0';
	if (!(nb_str = ft_dftoa(x)))
		return (0);
	printf("nb_str = %s\n", nb_str);
	nb_str += sign;
	if (!(ft_strncpy(exp_str, nb_str, 11)))
		return (0);
	printf("exp_str = %s\n", exp_str);
	nb_str += 11;
	if (!(ft_strncpy(mantissa, nb_str, 52)))
		return (0);
	printf("mantissa = %s\n", mantissa);
	*exp = get_exp(exp_str);
	printf("exp = %d\n", *exp);
	res = get_res(mantissa, *exp);
	printf("res = %f\n", res);
	return (res);
}

void	print_df(/*t_flags *flags,*/ double x)
{
	int exp;
	
	printf("dtfoa returns : %s\n", ft_dftoa(x));
	ft_frexp(x, &exp);
	printf("this should be 6 : %d\n", get_exp("10000000101"));


}

/*void	print_ldf(t_flags *flags, long double x)
{

}
static long double ft_frexpl(long double, int *exp)
{

}

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

*/
