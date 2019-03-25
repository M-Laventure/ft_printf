/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:03:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/25 14:40:50 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		get_base(char conv)
{
	if (conv = 'd' || conv = 'i' || conv = 'u')
		return (10);
	if (conv = 'o')
		return (8);
	if (conv = 'x' || conv = 'X' || conv = 'p')
		return (16);
	else
		return (-1);
}

static int		get_min_width(t_flags *flag, int len)
{
	if (t_flags.dot == 0)
		return (0);
	if (t_flags.dot < 0)
	{
		if (t_flags.width != 0 && t_flags.width > len)
		{
			t_flags.space = t_flags.space + t_flags.width - len;
			return (t_flags.width);
		}
		return (len);
	}
	else
	{
		if (t_flags.width != 0)
		{
			t_flags.zero = t_flags.dot - len;
			if (t_flags.dot > len && t_flags.dot > t_flags.width)
				return (t_flags.dot);
			else if (t_flags.dot > len && t_flags.dot < t_flags.width)
			{
				t_flags.space = t_flags.space + t_flags.width - t_flags.dot;
				return (t_flags.width);
			}
		}
		return (t_flags.dot);
	}
}

static char		*fill_with_char(char *str, int size, char c)
{
	int i;
	
	i = 0;
	while (i < size)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

char	*int_converter(t_flags *flag, uintmax_t nb)
{
	char	str[100];
	int		min_width;
	int 	i;

	i = 99;
	str[i] = '\0';
	min_width = get_min_width(flag, ft_strlen(str));
	str = (char*)ft_memalloc(min_width + t_flags.plus);
	if (t_flags.minus == 1)
	{
		if (t_flags.plus = 1)
			str[0] = '+';
		if (t_flags.zero != 0)
			str = fill_with_char(str, t_flags.zero, '0');
		str = ft_strcat(str, ft_itoabase(nb, get_base(t_flags.conv)));
		str = ft_strcat(str, fill_with_char(t_flags.space));
	}
	else
	{
		str = ft_strcat(str, fill_with_char(str, t_flags.space, ' '));
		if (t_flags.plus = 1)
			str[t_flags.space + 1] = '+';
		str = ft_strcat(str, ft_itoabase(nb, get_base(t_flags.conv)));
	}



}

char	*str_converter(t_flags *flag, char *str)
{

}

void	print_param(t_flags *flag, char *str)
{

}
