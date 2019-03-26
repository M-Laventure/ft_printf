/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:03:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/26 15:42:24 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		get_base(char conv)
{
	if (conv == 'd' || conv == 'i' || conv == 'u')
		return (10);
	if (conv == 'o')
		return (8);
	if (conv == 'x' || conv == 'X' || conv == 'p')
		return (16);
	else
		return (-1);
}

static int		get_min_width(t_flags *flag, int len)
{
	if (flag->dot == 0)
		return (0);
	if (flag->dot < 0)
	{
		if (flag->width != 0 && flag->width > len)
		{
			flag->space = flag->space + flag->width - len;
			return (flag->width);
		}
		return (len);
	}
	else
	{
		if (flag->width != 0)
		{
			flag->zero = flag->dot - len;
			if (flag->dot > len && flag->dot > flag->width)
				return (flag->dot);
			else if (flag->dot > len && flag->dot < flag->width)
			{
				flag->space = flag->space + flag->width - flag->dot;
				return (flag->width);
			}
		}
		return (flag->dot);
	}
}

static void		*fill_with_char(char *str, int size, char c)
{
	int i;
	
	i = 0;
	while (i < size)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

char	*int_converter(t_flags *flag, intmax_t nb)
{
	char	*str;
	int		min_width;

	min_width = get_min_width(flag, ft_strlen(str));
	if (!(str = (char*)ft_memalloc(min_width + flag->plus)))
		return (NULL);
	if (flag->minus == 1)
	{
		if (flag->plus == 1)
			str[0] = '+';
		if (flag->zero != 0)
			fill_with_char(str, flag->zero, '0');
		str = ft_strcat(str, ft_itoabase(nb, get_base(flag->conv)));
		str = ft_strcat(str, fill_with_char(str, flag->space, ' '));
	}
	else
	{
		str = ft_strcat(str, fill_with_char(str, flag->space, ' '));
		if (flag->plus == 1)
			str[flag->space + 1] = '+';
		str = ft_strcat(str, ft_itoabase(nb, get_base(flag->conv)));
	}
	return (str);
}

/*
char	*str_converter(t_flags *flag, char *str)
{

}

void	print_param(t_flags *flag, char *str)
{

}*/
