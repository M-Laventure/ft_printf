/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:09:08 by malavent          #+#    #+#             */
/*   Updated: 2019/04/15 12:22:04 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
#define __PRINTF_H
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <wchar.h>
# define ER_MODIF "warning : non compatible modifier"
# define F_TYPE "diouxXcspf"
# define VALID "0123456789#0.+- hlLdiouxXcspf"

#define DEBUG 1

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
void 	int_converter(t_flags *flags, uintmax_t nb);
void 	str_converter(t_flags *flags, char *str);
void	pr_int(t_flags *flags, uintmax_t nb);
void	pr_uint(t_flags *flags, va_list va);
void	print_memory(t_flags *flags, void *ptr);
void	char_converter(t_flags *flags, unsigned char c);
void	float_converter(t_flags *flags, long double x);

void	print_df(/*t_flags *flags,*/ double x);
//void	print_ldf(t_flags *flags, long double x);

/*
**		Utils Functions
*/

char 	*get_flag_conv(char *format, int *i, t_flags *flags);
int 	is_alt_special(char c);
int 	is_special(char c);
int 	get_size(char *spec, int *i); // chope la size pour la precision ou la width
void	get_flags(t_flags *flags); // chope les flags options
void	free_flags(t_flags *flags);

/*
**		FLOAT UTILS FUNCTIONS
*/

char 	*str_sum(char *s1, char *s2);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	*str_mult(char *s1, char *s2);

/*
**		DEBUG
*/

void	printf_flags(t_flags *flags);

#endif

