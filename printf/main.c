/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/02 19:22:59 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	/*printf("the real printf returns:%-12c\n", '\n');
	ft_putchar('\n');
	ft_printf("my printf returns      :%-12c\n", '\n');
	printf("the real printf returns:%4c\n", 'U');
	ft_putchar('\n');
	ft_printf("my printf returns      :%4c\n", 'U');
	ft_printf("my printf : hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	printf("the real one: hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);*/
//	printf("my printf returns      :test %-12i et %--2.4s %24s !\n", 0, NULL, "coco");
	ft_printf("the real printf returns:test %-12i et %--2.4s %24s !\n", 0, NULL, "coco");
	return (0);
}
