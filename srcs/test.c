/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:09:42 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/30 18:32:35 by mybenzar         ###   ########.fr       */
/*   Updated: 2019/03/27 11:20:18 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>

int	main(void)
{
	float nb = 123.6788;
	printf("%3.0f\n", nb);

/*	void *ptr;
	t_flags *flag;
	
	flag = malloc(sizeof(t_flags));
	ft_bzero(flag, sizeof(t_flags));
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

	//test sur flag "s"
	printf("%-2s\n", "hello"); //comment faire pour print 2 zeros et un padding de 3 ?
	printf("%02s\n", "hello"); //le flag 0 cree un undefined behavior avec le %s
	
	//test sur flag "d"
	printf("%05d\n", 422222);
	printf("%5d\n", 42);

	//test sur les modificateurs
	printf("h et d : %hd\n", 45);
	printf("h et o : %ho\n", 45);
	printf("h et u : %hu\n", 45);
	printf("h et x : %hx\n", 45);
	printf("h et c : %hX\n", 45);
	printf("h et c : %hc\n", 'a');
	printf("h et s : %hs\n", "string");
	printf("h et p : %hp\n", ptr);

	//test de int_converter
	ft_putendl("---------------------------------------");
	ft_putendl("debut de test de int converter");
	ft_putendl("---------------------------------------");
	flag->plus = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->id_conv = 'd';
	flag->minus = 0;
	flag->width = 8;
	flag->dot = 10;
	flag->sharp = 1;
	flag->modif = n;
	ft_putstr("my printf returns      :");
	int_converter(flag, 42);
	printf("\nthe real printf returns:%8.10d", 42);
	printf("\n");
	
	//test de str_converter
	char *str = "Hello World!";
	ft_putendl("---------------------------------------");
	ft_putendl("debut de test de str converter");
	ft_putendl("---------------------------------------");
	flag->plus = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->id_conv = 's';
	flag->minus = 0;
	flag->width = 8;
	flag->dot = 10;
	flag->sharp = 0;
	flag->modif = n;
	ft_putstr("my printf returns      :");
	str_converter(flag, str);
	printf("\nthe real printf returns:%8.10s", str);
*/
	//test de float_converter
	char *str = "Hello World!";
	ft_putendl("---------------------------------------");
	ft_putendl("debut de test de str converter");
	ft_putendl("---------------------------------------");
	flag->plus = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->id_conv = 'f';
	flag->minus = 0;
	flag->width = 8;
	flag->dot = -1;
	flag->sharp = 0;
	flag->modif = n;
	ft_putstr("my printf returns      :");
	str_converter(flag, str);
	printf("\nthe real printf returns:%8.10s", str);
	return (0);
}

