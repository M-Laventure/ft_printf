#include "../includes/ft_printf.h"

int main()
{
	t_flags flags;
	char *str;
	int i;

	i = 8;
	struct_init(&flags);
	flags.spec = get_flag_conv("bonjour%3.2#.5.4dtest", &i, &flags);
	ft_putstr(flags.spec);
	get_flags(&flags);
	ft_putchar('\n');
	ft_putnbr(flags.zero_fill);
	ft_putchar('\n');
	ft_putnbr(flags.width);
	ft_putchar('\n');
	ft_putnbr(flags.sharp);
	ft_putchar('\n');
	ft_putnbr(flags.minus);
	ft_putchar('\n');
	ft_putnbr(flags.plus);
	ft_putchar('\n');
	ft_putnbr(flags.dot);
	ft_putchar('\n');
	return (0);
}


