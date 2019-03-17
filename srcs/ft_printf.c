/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:49:31 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/14 16:01:14 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int valid_spec(str_format format)
{
	int i;

	while (format[i] && format[i] != '%' && !is_alt_special(format[i]))
	{
		if (is_fspec(format[i]))
			return (i);
		i++;
	}
	return (-1);
}

int printf_param(str_format *format, &opt, va)
{
	void *param;
	if (!(param = va_arg(va, void *)))
	{
		ft_putstr("no matching argument");
		return (-1);
	}
	printf("%s\n", param);
}

int	ft_printf(const char * restrict format, ...)
{
	va_list	va;
	int		i;
	int		len_spec;
	char	*arg;
	char	f;	
	t_options opt;

	va_start (va, format);
	i = 0;
	while (format[i] != '\0')
	{
		ft_putchar(format[i]);
		if (format[i] == '%')
		{
			if ((len_spec == valid_spec(format + i)) != -1))
			{
				get_options((format + i), &opt);
				printf_param(str_format *format, &opt, va);
				i = len_spec;
			}
		}
		i++;
		opt = t_options ft_get_options(int f);
		print_format(f, va_arg(va, void));
	}
	va_end (va);
}

