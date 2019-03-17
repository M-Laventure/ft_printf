/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:52:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/14 19:38:27 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
#define __PRINTF_H
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

emum e_fconv
{
	char = 'c', string = 's', pointer = 'p', double = 'd', dec_int = 'i', octal_num = 'o', float_point = 'f', unsigned_dec = 'u', hex_num_lwrcase = 'x', hex_num_uprcase = 'X'
}

typedef const char * restrict str_format;

typedef struct	s_options
{				
		int	width = 0;
		int precision = 0;
		int padding = 0;
		int modif = 0;
		int sign = 0;
		int 
}				t_options;

typedef struct	s_flags
{
	t_options *options;
	char conv;
}				t_flags;

int	ft_printf(str_format format, ...);


/*
** Process functions
*/


void print_param(str_format *format, t_options *opt, va_list va);
	
/*
**  Format functions
*/

int	ft_get_format(str_format format);

//Utils Functions

int is_fconv(char c);
int is_alt_special(char c);
int is_special(int c);

#endif

