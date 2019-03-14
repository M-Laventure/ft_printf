#include "../includes/ft_printf.h"

/*
void	print_format(t_options opt, str_format format)
{
	printf_std(str_format format);
}*/

int is_special(int c)
{
	if (c == '"' || c == '\'' || c == '%')
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
		ft_putchar('\v');
	if (c == 'f')
		ft_putchar('\f');
	if (c == 't')
		ft_putchar('\t');
	if (c == 'a')
		ft_putchar('\a');
	if (c == 'r')
		ft_putchar('\r');
}

void	print_std(char *format)
{
	int i;
	
	i = 0;
	while (format[i + 1] != '\0')
	{
		if (format[i] == '\\' || (format[i] == '%' && format[i + 1] == '%'))
		{
			if ((format[i] == '%' && format[i + 1] == '%'))
					ft_putchar(format[i + 1]);
			else if (is_alt_special(format[i + 1]) != 0)
					print_alt_special(format[i + 1]);
			i += 1;
		}
		if (format[i] == '\\')

		else
			ft_putchar(format[i]);
		i++;
	}
}

void test(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i]  == '\\') && (str[i + 1] == '\\'))//is_special(str[i + 1]))
		{
			ft_putstr("HERE\n");
			ft_putchar('\\');
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	char str[2];

	//test("\\");
//	printf("\\");
//	ft_putstr("\\");	
//	ft_putchar('\\');
//	print_std(str);
	printf("test\\");
	printf("\n");
	print_std("test\\");
	return (0);
}
