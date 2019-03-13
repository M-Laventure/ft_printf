/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:52:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/11 16:40:52 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_options	get_options(str_format str, char f)
{
	int i;

	i = 0;
	while (str[i] != f)
	{
		if (str[i] == '\'' || str[i] == '\\' || str[i] == '\"')
			i++;
		if (str[i] == '-')
		{
			while (ft_isdigit(str[++i]))
				t_options.padding = str[i];
		}
		if (str[i] == '+')
			t_options.sign = str[i];
		if (
	}
}
