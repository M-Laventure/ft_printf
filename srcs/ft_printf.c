/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:49:31 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/25 14:38:02 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	print_param(t_flags *t_flags)
{
	
}


int	ft_printf(str_format format, ...)
{
	va_list	va;
	int		i;
	int		i_jump;
	char	*arg;	
	t_flags flags;

	va_start (va, format);
	i = 0;
	while (format[i] != '\0')
	{
		ft_putchar(format[i]);
		if (format[i] == '%')
		{
			i++;
			if ((flags.spec = get_flag_conv(format, &i, &flags)) != NULL)
			{
				get_flags(&flags);
				print_param(&flags, va);
				i = i_jump;
			}
			// si aucune conv specifier faut-il print apres le % ?
		}
		i++;
	}
	va_end (va);
}
