/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:28:14 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/14 21:27:49 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_options(str_format str, char f, t_options opt)
{
	int i;
	int j;

	if (ft_strchr(str, '+') != NULL)
		opt.sign = 1;
	if (ft_strchr(str, ' ') != NULL)
		opt.space = 1;
	if (ft_strchr(str, '-') != NULL)
	{
		i = ft_strlen(str) - ft_strlen(ft_strchr(str, '-')) + 1;
		j = 0;
		ft_putnbr(i);
		ft_putchar('\n');
		while (ft_isdigit(str[i]))
		{
			j++;
			i++;
		}
		ft_putnbr(j);
		ft_putchar('\n');
		opt.padding = ft_atoi(ft_strsub(str, i, j + i - 1));
		ft_putnbr(opt.padding);
		ft_putchar('\n');
	}
}

