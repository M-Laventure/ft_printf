#include "../includes/ft_printf.h"

intmax_t	int_conv(t_flags *flags)
{
	if (flags->modif == h)
		return (va_arg(flags->arg_list, short int));
	if (flags->modif == hh)
		return (va_arg(flags->arg_list, char));
	if (flags->modif == l)
		return (va_arg(flags->arg_list, long int));
	if (flags->modif == ll)
		return (va_arg(flags->arg_list, long long int));
	return (va_arg(flags->arg_list, int));
}

uintmax_t	uint_conv(t_flags *flags)
{


	itoa 
	if (flags->modif == h)
		return (va_arg(flags->arg_list, unsigned int));
	if (flags->modif == hh)
		return (va_arg(flags->arg_list, unsigned char));
	if (flags->modif == l)
		return (va_arg(flags->arg_list, unsigned long int));
	if (flags->modif == ll)
		return (va_arg(flags->arg_list, unsigned long long int));
	return (va_arg(flags->arg_list, unsigned int));
}



if (flags->id_conv = 'p' && flags->modif == n)
		return (va_arg(flags->arg_list, void *));
	if (flags->id_conv = 's' && flags->modif == n)
		return (va_arg(flags->arg_list, char *));
	if (flags->id_conv == 'c' && flags->modif == n)
		return (va_arg(flags->arg_list, unsigned char));


void args_conv(t_flags *flags)
{
	if (flags->id_conv == 'd')
		return (int_conv(flags));
	if (ft_strchr("ouxX", flags->id_conv != NULL))
		return (uint_conv(t_flags *flags));
	if (flags->id_conv = 'c')
		if (flags->modif == l)
			return (var_arg(
		return (va_arg(flags->arg_list, unsigned char));
	if (flags->id_conv = 's')
	{
		if (flag->modif = l)
			return (va_arg(flags->arg_lst, wchar_t));
		return (va_arg(flags->arg_lst, char *);
	}

		
	if (flags->id_conv = 'p')
		return (p_conv(flags));
}
