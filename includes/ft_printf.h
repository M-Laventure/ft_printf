/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:52:43 by mybenzar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/03/27 11:42:50 by mybenzar         ###   ########.fr       */
=======
/*   Updated: 2019/03/27 11:00:40 by malavent         ###   ########.fr       */
>>>>>>> 0136373d44a5f301d8d3db3265dcc456e3a6524e
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
#define __PRINTF_H
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
# define ER_MODIF "warning : non compatible modifier"
# define F_TYPE "diouxXcspf"
/*emum id_conv
{
	char = 'c', string = 's', pointer = 'p', double = 'd', dec_int = 'i', octal_num = 'o', float_point = 'f', unsigned_dec = 'u', hex_num_lwrcase = 'x', hex_num_uprcase = 'X'
}*/


typedef enum	e_modif
{
	n, l, ll, L, h, hh
}				t_modif;

typedef struct	s_flags
{
		void *arg;
		char *spec;
		va_list arg_list;
		int	width;
		int dot;
		int sharp; //width - (len(param) + plus + change selon la conversion passe ex :pour "%o ou %x" / SI padding < 0 lors du calcul le param est plus grand que la width donc set a 0
		t_modif modif;
		int minus;	//left_justified
		int plus; //print '+' before printing the parameter
		char id_conv; //type de la conversion
		int	space;
		int zero; // si 0 le premier digit apres % alors le padding se fait avec des 0 -> set a ' ' ou '0', les 0 sont forcement au debut, le flag 0 est ignore si flag - mais pas pour les char 
}				t_flags;


int	ft_printf(const char *format, ...);


/*
** Parsing
*/


	
/*
**  Print functions (if any is needed)
*/

void	print_param(t_flags *flag, char *str);
void 	int_converter(t_flags *flag, intmax_t nb);
void 	str_converter(t_flags *flag, char *str);

/*
**		Utils Functions
*/

char *get_flag_conv(char *format, int *i, t_flags *flags);
int is_alt_special(char c);
int is_special(char c);
int get_size(char *spec, int *i); // chope la size pour la precision ou la width
void	get_flags(t_flags *flags); // chope les flags options
void	free_flags(t_flags *flags);
#endif

