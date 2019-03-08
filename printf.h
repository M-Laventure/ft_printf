/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:50:28 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/08 16:03:35 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
#define __PRINTF_H
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_struct
{
	char	(*f[?]) (const char *str);

}				t_struct;

int	ft_printf(const char *format, ...);

#endif

