/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:49:31 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/14 13:35:08 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char * restrict format, ...)
{
	va_list	va;
	int		i;
	char	*arg;
	char	f;	
	t_options opt;
	
	va_start (va, format);
	i = 0;
	while (format[i] != '\0')
	{
		while (format[i] != "%" && format[i])
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] == "%")
			f = ft_get_format(format + i);
	
	opt = t_options ft_get_options(int f);
	print_format(f, va_arg(va, void));
	}
	va_end (va);
}

