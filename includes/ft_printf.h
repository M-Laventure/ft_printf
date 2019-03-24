/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:52:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/24 13:02:46 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
#define __PRINTF_H
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/*emum id_conv
{
	char = 'c', string = 's', pointer = 'p', double = 'd', dec_int = 'i', octal_num = 'o', float_point = 'f', unsigned_dec = 'u', hex_num_lwrcase = 'x', hex_num_uprcase = 'X'
}*/

typedef const char * restrict str_format;


typedef struct	s_flags
{
		void *param;
		char *spec; // la string entre % et le premier flag
		int	width;
		int dot;
		int sharp;
		int padding; //width - (len(param) + plus + change selon la conversion passe ex :pour "%o ou %x" / SI padding < 0 lors du calcul le param est plus grand que la width donc set a 0
		int modif;
		int minus;	//left_justified
		int plus; //print '+' before printing the parameter
		int id_conv; //type de la conversion
		int zero_fill; // si 0 le premier digit apres % alors le padding se fait avec des 0 -> set a ' ' ou '0', les 0 sont forcement au debut, le flag 0 est ignore si flag - mais pas pour les char 
}				t_flags;


int	ft_printf(str_format format, ...);


/*
** Process functions
*/


void print_param(str_format *format, t_flags *flags, va_list va);
	
/*
**  Format functions
*/

int	ft_get_format(str_format format);

//Utils Functions

char *get_flag_conv(str_format format, int *i, t_flags *flags);
int is_alt_special(char c);
int is_special(char c);
int get_size(char *spec, int *i); // chope la size pour la precision ou la width
void	get_flags(t_flags *flags); // chope les flags options
void	struct_init(t_flags *flags);
#endif

