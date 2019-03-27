/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:03:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/27 09:06:10 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	{
		flag->space = flag->width;
		return (flag->width);
	}
	else if (flag->dot < 0)
	{
		if (flag->width == 0 || flag->width < len)
			return (len);
		else if (flag->width > len)
		{
			flag->space = flag->width - len;
			return (flag->width);
		}
	}
	else
	{
		if (flag->dot > len)
			flag->space = flag->width - len;
		else if (flag->dot < flag->width)
			flag->space = flag->width - flag->dot;
		else if (flag->dot > flag->width)
			return (flag->dot);
		return (flag->width);
	}
	return (-1);
}

static void		fill_zero_space(t_flags *flag, int len)
{
	if (flag->dot <= 0 && flag->width > len)
			flag->space = flag->space + flag->width - len;
	else if (flag->dot > 0 && flag->width != 0)
	{
			if (flag->dot > len && flag->dot > flag->width)
				flag->zero = flag->zero + flag->dot - flag->width;
			else if (flag->dot > len && flag->dot < flag->width)
			{
				flag->zero = flag->zero + flag->dot - len;
				flag->space = flag->space + flag->width - flag->dot;
			}
			else if (flag->dot <= len && flag->dot > flag->width)
				flag->zero = flag->zero + flag->dot - len;
			else if (flag->dot <= len && flag->dot < flag->width && len < flag->width)
					flag->space = flag->space + flag->width - len;
	}
	else if (flag->dot != 0 && flag->width == 0)
		flag->zero = flag->zero + flag->dot - len;
}

static void		print_nchar(int size, char c)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		ft_putchar(c);
		i++;
	}
}

static void		ft_putnstr(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_putchar(str[i++]);
}

void	int_converter(t_flags *flag, intmax_t nb)
{
	char	*nb_str;
	int		len;

	if (!(nb_str = ft_itoabase(nb, get_base(flag->conv))))
		return ;
	len = (int)ft_strlen(nb_str);
	fill_zero_space(flag, len);
	if (flag->dot < len)
		flag->zero = 0;
	if (flag->minus == 1)
	{
		if (flag->plus == 1)
			ft_putchar('+');
		if (flag->zero != 0)
			print_nchar(flag->zero, '0');
		ft_putstr(nb_str);
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
	}
	else
	{
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
		if (flag->plus == 1)
			ft_putchar('+');
		if (flag->zero != 0)
			print_nchar(flag->zero, '0');
		ft_putstr(nb_str);
	}
}


void	str_converter(t_flags *flag, char *str)
{
	int min_width;
	int	len;

	len = (int)ft_strlen(str);
	min_width = get_min_width(flag, len);
	if (flag->dot < len)
		flag->zero = 0;
	if (flag->minus == 1)
	{
		if (flag->dot != 0)
			ft_putnstr(str, min_width);
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
	}
	else
	{
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
		if (flag->dot != 0)
			ft_putnstr(str, min_width);
	}
}

/*void	print_param(t_flags *flag, char *str)
{

}*/



