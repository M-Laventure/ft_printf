

#include "../includes/ft_printf.h"
#include <stdio.h>

void	printf_flags(t_flags *flag)
{
		printf("padding=%d\n", flag->minus);
		printf("space=%d\n", flag->space);
		printf("width=%d\n", flag->width);
		printf("precision=%d\n", flag->dot);
		printf("len=%d\n", flag->len);
		printf("sharp=%d\n", flag->sharp);
		printf("plus=%c\n", flag->plus);
		printf("id_conv=%c\n", flag->id_conv);
		printf("modif=%c\n", flag->modif);
}
