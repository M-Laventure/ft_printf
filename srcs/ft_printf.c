/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:49:31 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/18 10:47:45 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int is_flag_conv(str_format format)
{
	int i;

	while (format[i] && format[i] != '%' && !is_alt_special(format[i])) //si il y a un char alt_spe, il met fin a la specification de format
	{
		if (is_fspec(format[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	print_padding(int nb_fill, int zero_fill)
{
	while (nb_fill--)
		ft_putchar(zero_fill);
}

int print_param(s_flags *t_flags)
{
	void *param;
	if (!(param = va_arg(va, void *)))
	{
		ft_putstr("no matching argument");
		return (-1);
	}
	if (opt->str_bflags)
		ft_putstr(str_bflags);
	
	if (padding != 0 && sign != '-')
			print_padding(opt->padding, opt->zero_fill);
	printf_conv(&opt, param);
	if (padding != 0 && sign == '-')
		print_padding(opt->padding)
	print("%s\n", param);
}

int	ft_printf(const char * restrict format, ...)
{
	va_list	va;
	int		i;
	int		i_jump;
	char	*arg;	
	t_options flags;

	va_start (va, format);
	i = 0;
	while (format[i] != '\0')
	{
		ft_putchar(format[i]);
		if (format[i] == '%')
		{
					
			if ((len_spec == is_flag_conv(format + i)) != -1)
			{
				get_options((format + i), &opt);
				printf_param(str_format *format, &opt, va);
				i = i_jump;
			}
			// si aucune conv specifier faut-il print apres le % ?
		}
		i++;
		opt = t_options ft_get_options(int f);
		print_format(f, va_arg(va, void));
	}
	va_end (va);
}

int main()
{
	return (0);
}
