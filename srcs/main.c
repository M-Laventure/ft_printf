#include "../includes/ft_printf.h"

int main()
{
	t_flags flags;
	char *str;
	int i;

	i = 8;
	str = get_flag_conv("bonjour%05\n.dtest", &i, &flags);
	ft_putstr(str);
	ft_putchar('\n');
	ft_putchar(flags.id_conv);
	ft_putchar('\n');
	ft_putnbr(i);
	return (0);
}


