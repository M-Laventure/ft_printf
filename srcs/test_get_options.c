/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:09:42 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/18 13:50:29 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>

int	main(void)
{
	t_options	opt;

	//test de get option
	get_options("hello%-545d\n", 'd', opt);
	
	/*
	//comportement sur #
	// flag '0' is ignored when flag '-' is present
	// le # force le traiement comme un x quand il est utilise avec un d
	printf("check : %#d", 123456);
	printf("%#0-0x\n", 123456);
	printf("%0x\n", 123456);
	printf("%#x\n", 123456);
	//qui est prioritaire entre + - et #
	printf("%-10#x\n", 123456); //le flag -10 est execute, le flag # aussi
	printf("% d\n", +123456); //le # marche au debut ou au milieu
	// check pour les doublons
	printf("juste le + :%+d\n", 123456);
	printf("juste 10 : % 123   10d\n", 123456);
	printf("juste 10 : %10d\n", 123456);
	printf("le + et 10 : %+10d", 123456);
*/
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
