/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:25:45 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/24 15:55:22 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		get_base(char conv)
{
	if (conv = 'd' || conv = 'i' || conv = 'u')
		return (10);
	if (conv = 'o')
		return (8);
	if (conv = 'x' || conv = 'X' || conv = 'p')
		return (16);
	else
		return (-1);
}

void	int_converter(t_flags *flag, uintmax_t nb)
{
	char	str[100];
	int		i;
	int		space;
	int		base;
	int		len;

	base = get_base(flag.conv);
	i = 99;
	str[i] = '\0';
	if (t_flags.minus == 0)
	{
		str[i--] = 48 + nb % base;
		len++;
	}
	if (flag.zero && flag.width)
	{
		while (
	}
	else
	{
		
	}
		

}
