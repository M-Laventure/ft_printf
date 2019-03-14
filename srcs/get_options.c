/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:28:14 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/14 15:27:07 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_options(str_format str, char f)
{
	if (ft_strchr(str, '+') != NULL)
		t_options.sign = 1;
	if (ft_strchr(str, ' ') != NULL)
		t_options.space = 1;
	if (ft_strchr(str, '-') != NULL)
	{
		while (ft_is_digit(str[i]))
			i++;
		t_options.padding = ft_strncpy(
	}
	t_options.width = *ft_strchr(str
}

