/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:09:42 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/19 15:25:41 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"

#include <stdio.h>

int	main(void)
{
	//comportement sur #
	// flag '0' is ignored when flag '-' is present
	// le # force le traiement comme un x quand il est utilise avec un d
	printf("check : %#d\n", 123456);
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
	printf("le + et 10 : %+10d\n", 123456);
	
	// check pour les 0 : le 0 sans n ne fait pas de fill
	printf("check du 0 avec n : %04d\n", 2);
	printf("check du 0 sans n : %0d\n", 2);

	// check pour les float : par defaut, ils ont une taille de 7 sans compter le - ou le +
	// si la width precisee en argument est inferieure a 7, il prend la largeur par defaut de 7
	printf("je ne suis pas un vrai float : %f\n", 5);
	printf("je suis un vrai float: %4f\n", 5.123456789);
	printf("je suis un vrai float avec un signe : %.9f\n", -5.2);
	printf("je suis un vrai float avec un signe : %+f\n", +5.2);
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
