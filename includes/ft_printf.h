/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:09:08 by malavent          #+#    #+#             */
/*   Updated: 2019/03/27 21:16:50 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
#define __PRINTF_H
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <wchar.h>
# define ER_MODIF "warning : non compatible modifier"
# define F_TYPE "diouxXcspf"
# define VALID "0123456789#0.+- hlLdiouxXcspf"
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
		int len;
		char *spec;
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

void	print_param(t_flags *flags, va_list va);
void 	int_converter(t_flags *flags, intmax_t nb);
void 	str_converter(t_flags *flags, char *str);
void	pr_int(t_flags *flags, intmax_t nb);
void	pr_uint(t_flags *flags, va_list va);
void	print_memory(t_flags *flags, void *ptr);
void 	wstr_converter(t_flags *flags, wchar_t *str);
void	wint_converter(t_flags *flags, wint_t nb);
void	char_converter(t_flags *flags, unsigned char c);
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

