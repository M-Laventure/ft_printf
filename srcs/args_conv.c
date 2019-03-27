/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:25:41 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/27 11:42:31 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	int_conv(t_flags *flag)
{
	if (flags->modif == h)
		int_converter(flag, va_arg(flags->arg_list, short int));
	if (flags->modif == hh)
		int_converter(flag, va_arg(flags->arg_list, char));
	if (flags->modif == l)
		int_converter(flag, va_arg(flags->arg_list, long int));
	if (flags->modif == ll)
		int_converter(va_arg(flags->arg_list, long long int));
	else
		int_converter(va_arg(flags->arg_list, int));
}

void	uint_conv(t_flags *flag)
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


void	str_conv(t_flag *flag)
{
	if (flags->id_conv = 'p' && flags->modif == n)
		print_memory(flag, va_arg(flags->arg_list, void *));
	if (flags->id_conv = 's' && flags->modif == n)
		str_converter(flag, va_arg(flags->arg_list, char *));
	if (flags->id_conv == 'c' && flags->modif == n)
		str_converter(flag, va_arg(flags->arg_list, unsigned char));
}

/*
void args_conv(t_flags *flags)
{
	if (flags->id_conv == 'd')
		return (int_conv(flags));
	if (ft_strchr("ouxX", flags->id_conv != NULL))
		return (uint_conv(t_flags *flags));
	if (flags->id_conv = 'c')
		if (flags->modif == l)
			return (var_arg(
		return (va_arg(flags->arg_list, unsigned char));
	if (flags->id_conv = 's')
	{
		if (flag->modif = l)
			return (va_arg(flags->arg_lst, wchar_t));
		return (va_arg(flags->arg_lst, char *);
	}

		
	if (flags->id_conv = 'p')
		return (p_conv(flags));
}*/
