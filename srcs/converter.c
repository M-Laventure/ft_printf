/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:03:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/29 14:12:30 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"


//rajouter la len dans les fonctions oxX

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

static int		min_width_no_precision(t_flags *flag, int len)
{
	if (flag->dot == 0)
	{
		flag->space = flag->width;
		return (flag->width);
	}
	else if (flag->dot < 0)
	{
		if (flag->width == 0 || flag->width <= len)
			return (len);
		else if (flag->width > len)
		{
			flag->space = flag->width - len;
			return (flag->width);
		}
	}
	return (-1);
}

static int		get_min_width(t_flags *flag, int len)
{
	if (flag->dot <= 0)
		return (min_width_no_precision(flag, len));
	else
	{
		//if (flag->width == 0)
		//	return (len);
		if (flag->dot > len)
			flag->space = flag->width - len;
		else if (flag->dot < flag->width)
		{
			flag->space = flag->width - flag->dot;
			return (flag->dot);
		}
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
			flag->zero = flag->zero + flag->dot - len;
		else if (flag->dot > len && flag->dot < flag->width)
		{
			flag->zero = flag->zero + flag->dot - len;
			flag->space = flag->space + flag->width - flag->dot;
		}
		else if (flag->dot <= len && flag->dot > flag->width)
			flag->zero = flag->zero + flag->dot - len;
		else if (flag->dot <= len && flag->dot < flag->width
				&& len < flag->width)
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
	while (i < size && str[i] != '\0')
		ft_putchar(str[i++]);
}

static void		print_exp(t_flags *flag)
{
	if (flag->id_conv == 'o' || flag->id_conv == 'x' || flag->id_conv == 'X')
		ft_putchar('0');
	if (flag->id_conv == 'x')
	{
		ft_putchar('x');
		flag->len += 2;
		return ;
	}
	if (flag->id_conv == 'X')
		ft_putchar('X');
	flag->len += flag->len;
}

static void		print_nb_padding(t_flags *flag, char *nb_str)
{
	if (flag->plus == '+')
		ft_putchar('+');
	if (flag->plus == '-')
		ft_putchar('-');
	if (flag->sharp == 1)
		print_exp(flag);
	if (flag->zero != 0)
		print_nchar(flag->zero, '0');
	ft_putstr(nb_str);
	if (flag->space != 0)
		print_nchar(flag->space, ' ');
}

static void		print_nb(t_flags *flag, char *nb_str)
{
	if (flag->space != 0)
		print_nchar(flag->space, ' ');
	if (flag->plus == '+')
		ft_putchar('+');
	if (flag->plus == '-')
		ft_putchar('-');
	if (flag->zero != 0)
		print_nchar(flag->zero, '0');
	if (flag->sharp == 1)
		print_exp(flag);
	ft_putstr(nb_str);
}

void	char_converter(t_flags *flag, unsigned char c)
{
	fill_zero_space(flag, 1);
	if (flag->minus == 1)
	{
		ft_putchar(c);
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
	}
	else
	{
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
		ft_putchar(c);
	}
	flag->len = 1 + flag->space;
}

void	int_converter(t_flags *flag, intmax_t nb)
{
	char	*nb_str;
	int		len;

	if (!(nb_str = ft_itoabase((intmax_t)nb, get_base(flag->id_conv))))
		return ;
	printf("nb_str= %s\n", nb_str);
	len = (int)ft_strlen(nb_str);
	fill_zero_space(flag, len);
	if (flag->dot < len)
		flag->zero = 0;
	if (flag->minus == 1)
		print_nb_padding(flag, nb_str);
	else
		print_nb(flag, nb_str);
	flag->len += len + flag->zero + flag->plus + flag->space;
}

void	str_converter(t_flags *flag, char *str)
{
	int min_width;
	int	len;

	len = (int)ft_strlen(str);
	min_width = get_min_width(flag, len);
	if (DEBUG)
	{
	//	printf_flags(flag);
	//	printf("min_width=%d\n", min_width);
	}
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
	flag->len = min_width + flag->space;
}

