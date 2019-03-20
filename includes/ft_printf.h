/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:52:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/20 13:30:27 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
# define __PRINTF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*emum id_conv
{
	char = 'c', string = 's', pointer = 'p', double = 'd', dec_int = 'i', octal_num = 'o', float_point = 'f', unsigned_dec = 'u', hex_num_lwrcase = 'x', hex_num_uprcase = 'X'
}*/

# define ABS(x) (x < 0 ? -x : x)

typedef const char * restrict str_format;


typedef struct	s_flags
{
	char	*param;
	char	*str_conv;
	char	*str_bflags; // la string entre % et le premier flag
	int		width; //number
	int		precision; //number (sans le ".")
	int		diese; //boolean
  	//width - (len(param) + plus + change selon la conversion passe 
	//ex :pour "%o ou %x" / SI padding < 0 lors du calcul le param est plus grand que la width donc set a 0
	int		modif;
	int		minus;	//left_justified boolean
	int		plus; //print '+' before printing the parameter boolean
	char	id_conv; //type de la conversion
	int		zero //boolean; // si 0 le premier digit apres % alors le padding se fait avec des 0 -> set a ' ' ou '0', 
						//les 0 sont forcement au debut, le flag 0 est ignore si flag - mais pas pour les char 
}				t_flags;


int		ft_printf(str_format format, ...);

/*
** Parsing functions
*/

void	struct_init(t_flags *flag);
// parse la string des flags et celle des arguments avant de la lancer a get_flags
void	get_args(str_format *str, t_flags *flag, va_list va);
// encore utile ?
char	get_format(str_format format);
// ancien get_options, remplit la structure avec les bonnes infos
void	get_flags(str_format str, t_flags flag);
void	str_converter(t_flags *flag);

	
/*
**  Print functions
*/

void	print(t_flags *flag);
void	char_print(int nb_char, char c);
void	print_c(t_flags *flag);
void	print_d(t_flags *flag);
void	print_o(t_flags *flag);
void	print_u(t_flags *flag);
void	print_x(t_flags *flag);
int		print_param(t_flags *t_flags);

/*
**	Tools Functions
*/

int is_fconv(char c);
int is_alt_special(char c);
int is_special(int c);

#endif

