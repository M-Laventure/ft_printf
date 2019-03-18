/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:11:16 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/18 20:32:10 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int is_fconv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'|| c == 'i' || 
	c == 'o' || c == 'f' || c == 'u' || c == 'x' || c == 'X')
				return (1);
		return (0);
} 

int is_special(char c)
{
		if (c == '"' || c == '\'' || c == '%')
				return (1);
		return (0);
}

int is_alt_special(char c)
{
		if (c == '\n' || c == '\a' || c == '\f' || c == '\b' || c == '\r' || c == '\t' || c == '\v')
				return (1);
		return (0);
}
