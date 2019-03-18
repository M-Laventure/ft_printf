/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:28:14 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/18 17:51:14 by mybenzar         ###   ########.fr       */
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
		opt.padding = ft_atoi(str + i);
	}
	if (ft_strchr() != NULL)
	{

	}
	
}

