/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:55:24 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/02 17:27:20 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("%8.10ld\n", -2147483648);
	ft_printf("%8.10ld", -2147483648);
	/*ft_putnbr(printf("the real printf :%10.8f\n", 12.3456789));
	ft_putchar('\n');
	ft_putnbr(ft_printf("not real printf :%10.8f\n", 12.3456789));
	*/
	return (0);
}


