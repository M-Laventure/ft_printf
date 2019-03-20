/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:25:45 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/20 18:38:14 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	str_converter(t_flags *flag)
{
	char	str[100];
	int		i;
	int		base;

	if (flag.conv = 'd' || flag.conv = 'i' || flag.conv = 'u')
		base = 10;
	if (flag.conv = 'o')
		base = 8;
	if (flag.conv = 'x' || flag.conv = 'X' || flag.conv = 'p')
		base = 16;
		

	i = 99;

}
