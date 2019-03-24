#include "../includes/ft_printf.h"

int is_fconv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'|| c == 'i' || 
	c == 'o' || c == 'f' || c == 'u' || c == 'x' || c == 'X')
				return (1);
		return (0);
} 

int is_special(char c)
{
		if (c == '"' || c == '\'' || c == '%')
				return (1);
		return (0);
}

int is_alt_special(char c)
{
		if (c == '\n' || c == '\a' || c == '\f' || c == '\b' || c == '\r' || c == '\t' || c == '\v')
				return (1);
		return (0);
}

char *get_flag_conv(str_format format, int *i, t_flags *flags)
{
	int start;
	start = *i;

	while (format[*i] && format[*i] != '%' && !is_alt_special(format[*i])) //si il y a un char alt_spe, il met fin a la specification de format
	{
		if (is_fconv(format[*i]))
		{
			flags->id_conv = format[*i];
			return (ft_strsub(format, start, *i - start));
		}
		*i += 1;
	}
	return (NULL);
}

