#include "../includes/ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_flags *flags;
	int i;

	if (argc != 2)
		return (0);
	i = 8;
	flags = (t_flags*)malloc(sizeof(t_flags));
	ft_bzero(flags, sizeof(t_flags));
	if (!(flags->spec = get_flag_conv(argv[1], &i, flags)))
	{
		printf("error\n");
		return (-1);
	}
	//ft_putstr(flags->spec);
	get_flags(flags);
	ft_putchar('\n');
	ft_putchar(flags->id_conv);
	ft_putchar('\n');
	ft_putnbr(flags->zero);
	ft_putchar('\n');
	ft_putnbr(flags->width);
	ft_putchar('\n');
	ft_putnbr(flags->sharp);
	ft_putchar('\n');
	ft_putnbr(flags->minus);
	ft_putchar('\n');
	ft_putnbr(flags->plus);
	ft_putchar('\n');
	ft_putnbr(flags->dot);
	ft_putchar('\n');
	//flags->modif = n;
	ft_putnbr(flags->modif);
	
	ft_putchar('\n');
	return (0);
}


