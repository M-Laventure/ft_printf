/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:11:05 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/19 18:01:55 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	print(t_flags *flag)
{
	if (flag.id_conv = "s" || flag.id_conv = "c")
		print_c(flag);
	if (flag.id_conv = "d" || flag.id_conv = "i")
		print_d(flag);
	if (flag.id_conv = "o")
		print_o(flag);
	if (flag.id_conv = "u")
		print_u(flag);
	if (flag.id_conv = "x" || flag.id_conv = "X")
		print_x(flag);
}

// pour print les 0 et les espaces
void	char_print(int nb_char, char c)
{
	int i;

	i = 1;
	if (nb_char == 0)
		return ;
	while (i <= nb_char)
	{
		ft_putchar(c);
		i++;
	}
}

void	print_c(t_flags *flag)
{
	int nb_space;

	if (flag.id_conv = "s")
	{
		nb_space = ABS(flag.width - flag.prec);
		char_print(nb_space, ' ');
		char_print(flag.zero_fill - 
	}
	if (flag.id_conv = "c")
	{

	}
}
