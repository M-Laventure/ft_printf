/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:04:36 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/19 15:57:58 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_flags(t_flags *flag)
{
	int i;
	int len;

	len = ft_strlen(t_flag.param);
	if (ft_strchr(t_flags.str_bflags, '+') != NULL)
		flag.plus = 1;
	if (ft_strchr(t_flags.str_bflags, ' ') != NULL)
		flag.space = 1;
	if (ft_strchr(t_flags.str_bflags, '-') != NULL)
	{
		i = ft_strlen(t_flags.str_bflags) - ft_strlen(ft_strchr(t_flags.str_bflags, '-')) + 1;
		flag.padding = ft_atoi(t_flags.str_bflags + i);
	}
	if (ft_strchr(t_flags.str_bflags, '#') != NULL)
	{
		//ici param est considere comme un hexadecimal meme si le flag n'est pas x (undefined behaviour)
		flag.id_conv = 'x';
		flag.diese = 1;
	}
	if (ft_strchr(t_flags.str_bflags, '0') != NULL)
	{
		// afficher n caracteres, completes a gauche par des '0'. du coup il faut reussir a recuperer le n
		flag.zero_fill = n - len;
	}
}

