/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:38:44 by malavent          #+#    #+#             */
/*   Updated: 2019/04/03 19:31:13 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str_sub;
	size_t	len_max;
	size_t	i;

	if (s == NULL)
		return (NULL);
	printf("new sub ----------------------------------------------\n");
	printf("start chosen was %u and len chosen was %zu\n", start, len);
	len_max = (ft_strlen(s) - start);
	printf("ft_strlen = %zu\n", ft_strlen(s));
	printf("len_max = %zu\n", len_max);
	if (len <= len_max)
	{
		if (!(str_sub = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			str_sub[i] = s[start + i];
			printf("str_sub[%lu] = %c\n", i, str_sub[i]);
			i++;
		}
		str_sub[i] = '\0';
		return (str_sub);
	}
	return (0);
}
