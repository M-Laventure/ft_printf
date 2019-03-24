/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flagss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:04:36 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/20 13:36:06 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_flags(t_flags *flag, str_format format)
{
	int i;
	int len;

	len = ft_strlen(t_flags.param);
	if (ft_strchr(format, '+') != NULL)
		flags.plus = 1;
	if (ft_strchr(format, ' ') != NULL)
		flags.space = 1;
	if (ft_strchr(format, '-') != NULL)
	{
		i = ft_strlen(format) - ft_strlen(ft_strchr(format, '-')) + 1;
		flags.padding = ft_atoi(format + i);
	}
	if (ft_strchr(format, '#') != NULL)
	{
		//ici param est considere comme un hexadecimal meme si le flags n'est pas x (undefined behaviour)
		flags.id_conv = 'x';
		flags.diese = 1;
	}
	if (ft_strchr(format, '0') != NULL)
	{
		// afficher n caracteres, completes a gauche par des '0'. du coup il faut reussir a recuperer le n
		flags.zero_fill = n - len;
	}
}

