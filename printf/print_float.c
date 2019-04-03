/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:44:53 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/03 19:31:13 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


static char	*float_to_binary(double x)
{
	int					i;
	unsigned long		tmp;
	char				*nb_str;

	i = 0;
	if (!(nb_str = (char *)malloc(sizeof(char) * 65)))
		return (NULL);
	tmp = (unsigned long)x;
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
	return (nb_str);
}
/*
char	power_of_two(char *binary, int exp)
{
	int i;
	i = 0;

	while (binary[i] != '\0')
	{
		if (binary[i])
			exp / ft_power(2, i);
	}
}
*/

/*
** reminder of float limits (float, double and long double) :
** FLT_MAX
** DBL_MAX
** LDBL_MAX
*/

void	print_df(/*t_flags *flags,*/ double x)
{
	char *binary;
	char *mantissa; //if 64 bits, mantissa[23] else if 80 bits, mantissa[52] and exponent[11]
	char *exp;

	if (!(binary = float_to_binary(x)))
		return ;
	ft_putendl(binary);
	if (!(exp = ft_strsub(binary, 1, 8)))
		return ;
	ft_putendl(exp);
	if (!(mantissa = ft_strsub(binary, 9, 23)))
		return ;
	ft_putendl(mantissa);
	printf("coucou\n");


	
	
}

/*void	print_ldf(t_flags *flags, long double x)
{

}*/

