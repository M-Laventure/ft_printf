/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:25:41 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/27 15:15:09 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"



void	print_param(t_flags *flags)
{
	intmax_t nb_sign;

	if (flags->id_conv == 'd')
	{	nb_sign = conv_signed(flags);
		if (nb_sign < 0 && flags->space == 1)
		{
			nb_sign = -nb_sign;
			flags->plus = '-';
			flags->space = 0;
		}
	}
	if (ft_strchr("ouxX", flags->id_conv != NULL))
		pr_uint(flags);
	else
		other_conv(flags);	
}

intmax_t	conv_signed(t_flags *flags)
{
	if (flags->modif == h)
		return (va_arg(flags->arg_list, short int));
	if (flags->modif == hh)
		return (va_arg(flags->arg_list, char));
	if (flags->modif == l)
		return (va_arg(flags->arg_list, long int));
	if (flags->modif == ll)
		return (va_arg(flags->arg_list, long long int));
	else
		return (va_arg(flags->arg_list, int));
}

void	pr_int(t_flags *flags, intmax_t nb)
{
	if (flags->modif == h)
		int_converter(flag, nb);
	if (flags->modif == hh)
		int_converter(flags, nb);
	if (flags->modif == l)
		int_converter(flag, nb);
	if (flags->modif == ll)
		int_converter(flag, nb);
	else
		int_converter(flag, nb);
}

void	pr_uint(t_flags *flags)
{
	if (flags->modif == h)
		int_converter(flag, va_arg(flags->arg_list, unsigned int));
	if (flags->modif == hh)
		int_converter(flag, va_arg(flags->arg_list, unsigned char));
	if (flags->modif == l)
		int_converter(flag, va_arg(flags->arg_list, unsigned long int));
	if (flags->modif == ll)
		int_converter(va_arg(flags->arg_list, unsigned long long int));
	else
		int_converter(va_arg(flags->arg_list, unsigned int));
}


void	other_conv(t_flag *flags)
{
	if (flags->id_conv = 'p')
	{
		if (flags->modif == h)
			print_memory(flags, va_arg(flags->arg_list, short int *));
		if (flags->modif == l)
			printf_memory(flags, va_arg(flags->arg_list, long int *));
		else
			print_memory(flags, va_arg(flags->arg_list, void *));

	}
	if (flags->id_conv = 's')
	{
		if (flags->modif == l)
			str_converter(flags, va_arg(flags->arg_list, wchar_t *));
		str_converter(flags, va_arg(flags->arg_list, char *));
	}
	if (flags->id_conv == 'c' && flags->modif == n)
	{
		if (flags->modif == l)
			str_converter(flags, va_arg(flags->arg_list, wint_t));
		if (flags->modif == hh)
			str_converter(flags, va_arg(flags->arg_list, char *));
		str_converter(flags, va_arg(flags->arg_list, unsigned char));
	}
}
