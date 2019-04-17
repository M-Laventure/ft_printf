/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:09:08 by malavent          #+#    #+#             */
/*   Updated: 2019/04/17 14:47:14 by mybenzar         ###   ########.fr       */
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

#include <stdio.h>

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
		int sharp; 
		t_modif modif;
		int minus;	
		int plus; 
		char id_conv; 
		int	space;
		int zero;
}				t_flags;


int	ft_printf(const char *format, ...);

/*
**  Calculator Structure for Floats
*/

typedef struct	s_calc
{
	int len1;
	int len2;
	int	max;
	int min;
	int	sum;
	char *ten;
	int ten_dec;
}				t_calc;
	
/*
**  Print functions
*/

void	print_param(t_flags *flags, va_list va);
void 	int_converter(t_flags *flags, uintmax_t nb);
void 	str_converter(t_flags *flags, char *str);
void	pr_int(t_flags *flags, uintmax_t nb);
void	pr_uint(t_flags *flags, va_list va);
void	char_converter(t_flags *flags, unsigned char c);
void	float_converter(t_flags *flags, long double x);

void	print_df(/*t_flags *flags,*/ double x);
//void	print_ldf(t_flags *flags, long double x);

/*
**  Print Utils functions
*/

void	ft_putnstr(char *str, int size);
char 	*ft_strupper(char *str);

/*
**		Parsing Functions
*/

char 	*get_flag_conv(char *format, int *i, t_flags *flags);
int 	is_alt_special(char c);
int 	is_special(char c);
int 	get_size(char *spec, int *i); // chope la size pour la precision ou la width
void	get_flags(t_flags *flags); // chope les flags options
void	free_flags(t_flags *flags);

/*
**		Float Utils Functions
*/

char 	*vlq_sum(char *s1, char *s2);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	*vlq_mult(char *s1, char *s2);
void	vlq_initialize(char *vlq, int c, int size);
void	vlq_tmp_conv(char *s1, char *s2);
void	vlq_tmp_conv_rev(char *s, int size);
void	calc_info(t_calc *info, char *s1, char *s2);
void	free_calc(t_calc *info);
void	vlq_nshift(char *s, int size, int shifts);
void	vlq_shift_left(char *s, int size);

/*
**		Debug
*/

void	printf_flags(t_flags *flags);

#endif

