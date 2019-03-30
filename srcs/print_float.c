/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:27:30 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/30 18:28:08 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*dec_to_rounded_a(float x, int prec)
{
	int		dec;
	char	*dec_str;
	int		len;

	dec = (int)((x - (long)x) * ft_power(10, prec + 1));
	if (!(dec_str = ft_itoa(dec)))
		return (NULL);
	len = ft_strlen(dec_str);
	if (str[len] >= '5')
		str[len - 1] += 1;
	return (dec_str);
}

void	float_converter(float x)
{
	int		i_part;
	char	*i_str;
	char	*d_str;
	
	i_part = (long)x;
	if (flag->dot == 0)
	{
		if (x - i_part >= 5)
			x += 1;
		x = i_part;
			
	}
	if (x - i_part == 0)
	{
		int_converter(i_part);
		return ;
	}
	if (!(i_str = ft_itoa((long)x)))
		return (NULL);
	(x < 0) ? ft_putchar('-') : ft_putchar('+');
	len = (int)ft_strlen(nb_str) + flag->dot;
	fill_zero_space(flag, len);
	if (flag->dot < len)
		flag->zero = 0;
	if (flag->minus == 1)
		print_nb_padding(flag, nb_str);
	else
		print_nb(flag, nb_str);
	flag->len += len + flag->zero + flag->plus + flag->space;

}
