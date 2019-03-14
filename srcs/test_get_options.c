/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:09:42 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/14 12:22:42 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>

int	main(void)
{
	//comportement sur #
	// flag '0' is ignored when flag '-' is present
	printf("%#0-0x\n", 123456);
	printf("%0x\n", 123456);
	printf("%#x\n", 123456);
	//qui est prioritaire entre + - et #
	printf("%-10#x\n", 123456); //le flag -10 est execute, le flag # aussi
	printf("% d\n", +123456); //le # marche au debut ou au milieu
}

/*
 * %
 * +
 * -
 * #
 * 0
 * space
 * h hh l ll L
 * d i o u x X c s p f
 *
*/ 
