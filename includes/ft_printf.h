/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:52:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/14 12:29:14 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
#define __PRINTF_H
#include "../libftlibft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef const char * restrict str_format;

typedef struct	s_options
{				
		char	width;
		char	precision;
		char	padding;
		char	modif;
		char	sign;
}				t_options;

typedef struct	s_format
{
	t_options	options;
	char		format;
}				t_format;

int				ft_printf(str_format format, ...);


/*
** Process functions
*/


void			print_format(char f, t_options opt);
	
/*
**  Format functions
*/

char			get_format(str_format format);
t_options		get_options(str_format str, char f);

#endif

