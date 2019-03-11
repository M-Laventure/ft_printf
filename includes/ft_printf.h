/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:52:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/11 16:40:52 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
#define __PRINTF_H
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef const char * restrict str_format;

typedef struct	s_options
{				
		int	width;
		int precision;
		int padding;
		char modif;
		char sign;
}				t_options;

typedef struct	s_format
{
	t_options options;
	int format;
}				t_format;

int	ft_printf(str_format format, ...);


/*
** Process functions
*/


void print_format(f, va_arg(va, void), t_options opt);
	
/*
**  Format functions
*/

int	ft_get_format(str_format format);

#endif

