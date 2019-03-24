#include "../includes/ft_printf.h"

void	struct_init(t_flags *flags)
{
	flags->width = 0;
	flags->dot = 0;
	flags->sharp = 0;
	flags->padding = 0;
	flags->modif = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->zero_fill = 0;
	flags->id_conv = 0;
}

int	get_size(char *spec, int *i)  //chope la size pour la precision ou la width si 
{
	int size;
	int k;

	k = 0;
	size = 0;
	while (ft_isdigit(spec[k]) && spec[k])
	{
		size = (size * 10) + (spec[k] - 48);
		*i += 1;
		k++;
	}
/*	if (spec[k] != '.' && spec[k] != '\0')
		return (0);*/
	return (size);
}

//int is_integer(

void	get_modifs(t_flags *flags)
{
	int i;

	i = 0;
	while (flags->spec[i + 1])
		i++;
	if ((flags->spec[i] == 'l' || flags->spec[i] == 'h') && is_integer(flags->id_conv)
		
	if (flags->spec[i] == 
}

void	get_flags(t_flags *flags)
{
	int i;
	int start;
	char *size;

	i = 0;
	while (flags->spec[i])
	{
		if (ft_isdigit(flags->spec[i]) && flags->spec[i] != '0' && flags->width == 0)
			flags->width = get_size((flags->spec) + i, &i);
		if (flags->spec[i] == '.')
		{
			i++;
			flags->dot = get_size(flags->spec + i, &i);// saute le point
		}
		if (ft_strchr( "0#-+", flags->spec[i]) != NULL)
		{
			if (flags->spec[i] == '0')
				flags->zero_fill = 1;
			if (flags->spec[i] == '#')
				flags->sharp = 1;
			if (flags->spec[i] == '-')
				flags->minus = 1;
			if (flags->spec[i] == '+')
				flags->plus = 1;
		}
		if (flags->spec[i] != '.')
			i++;
	}
	if (flags->zero_fill != 0 && flags->minus != 0)
		flags->zero_fill = 0;
}

/*void	get_args(str_format format, t_flags *flag, va_list va)
{
	id_conv = get_format(str);
	t_flag.param = va_arg(va, char*);
	t_flag.str_bflagss = ft_strsub(format, 0, is_flag_conv(format));
}*/

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

