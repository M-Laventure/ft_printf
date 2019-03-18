/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:52:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/18 17:01:48 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
#define __PRINTF_H
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef const char * restrict str_format;

typedef struct	s_options
{				
		int		width;
		int		precision;
		int		padding;
		int		modif;
		int		sign;
		int		space;
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
void			get_options(str_format str, char f, t_options opt);

#endif

