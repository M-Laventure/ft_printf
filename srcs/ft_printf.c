/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:49:31 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/20 10:46:39 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int is_flag_conv(str_format format)
{
	int i;

	while (format[i] && format[i] != '%' && !is_alt_special(format[i])) //si il y a un char alt_spe, il met fin a la specification de format
	{
		if (is_fconv(format[i]))
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

char *get_conv(flags->id_conv, param)
{
	char *tab[id_conv](param);	
}
		
/*int print_param(t_flags *t_flags)
{
	char *param;

	if (flags->conv = 'd')
		param = va_arg(va, int);
	if (!(param = va_arg(va, char *)))
	{
		ft_putstr("no matching argument");
		return (-1);
	}
	if (opt->str_bflags)
		ft_putstr(str_bflags);	
	if (padding != 0 && sign != '-')
		print_padding(opt->padding, opt->zero_fill);
	printf_conv(&flags, param);
	if (padding != 0 && sign == '-')
		print_padding(opt->padding)
	print("%s\n", param);
}*/

int	ft_printf(str_format format, ...)
{
	va_list	va;
	int		i;
	int		i_jump;
	char	*arg;	
	t_flag	flag;

	va_start (va, format);
	i = 0;
	while (format[i] != '\0')
	{
		ft_putchar(format[i]);
		if (format[i] == '%')
		{					
			if ((len_spec == is_flag_conv(format + i)) != -1)
			{
				get_args((format + i), flag, va);
				get_options(flag);
				//printf_param(str_format *format, &opt, va);
				i = i_jump;
			}
			// si aucune conv specifier faut-il print apres le % ?
		}
		i++;
	}
	va_end (va);
}

int main()
{
	return (0);
}
