#include "../includes/printf.h"

char 

void	print_format(t_options opt, str_format format)
{
	printf_std(str_format format);
}

int is_special(int c)
{
	if (c == '"' || c == ''' || c == '\' || c == '%')
		return (1);
	return (0);
}

int is_alt_special(int c)
{
	if (c == 'n' || c == 'a' || c == 'f' || c == 'b' || c == 'r' || c == 't' || c == 'v')
		return (c);
	return (0);
}

void	print_alt_special(int c)
{
	if (c == 'n')
		ft_putchar('\n');
	if (c == 'v')


void	print_std(str_format format)
{

	int i;

	i = 0;
	while (format[i + 1] != '\0')
	{
		if (format[i] == '\')
		{
			if (is_special(format[i + 1]) || (format[i] == '%' && format[i + 1]))
				ft_putchar(format[i + 1]);
			else if (is_alt_special(format[i + 1]) != 0)
				print_alt_special(for
			i += 2
		}
	}
}			
