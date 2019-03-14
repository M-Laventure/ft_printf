/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:28:14 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/14 14:31:22 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_options(str_format str, char f)
{
	char c;

	c = *ft_strchr(str, '-');
	ft_putchar(c);
	ft_putchar('\n');
}

