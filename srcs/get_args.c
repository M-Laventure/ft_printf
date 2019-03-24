/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:55:20 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/18 20:31:29 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** cette fonction doit etre dans le main car elle appelle directement va_list
** elle traite les arguments pour qu'ils soient comprehensibles par get_flags
** peut etre pour etre a la norme que get_args peut contenir get_flags
*/

// format designe le premier argument de printf, a partir du %
// param designe le premier parametre de printf, a savoir le deuxieme argument

void	struct_init(t_flags *flag)
{
	t_flags.width = 0;
	t_flags.precision = 0;
	t_flags.diese = 0;
	t_flags.padding = 0;
	t_flags.modif = 0;
	t_flag.minus = 0;
	t_flag.plus = 0;
	t_flag.zero_fill = 0;
	t_flag.id_conv = 0;
}


void	get_args(str_format format, t_flags *flag, va_list va)
{
	id_conv = get_format(str);
	t_flag.param = va_arg(va, char*);
	t_flag.str_bflagss = ft_strsub(format, 0, is_flag_conv(format));
}
