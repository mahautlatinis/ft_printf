/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:49:36 by malatini          #+#    #+#             */
/*   Updated: 2023/10/07 18:38:56 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	print_pc(t_format *spec, va_list arg_ptr)
{
	(void)arg_ptr;
	ft_putchar('%');
	spec->printed_chars += 1;
}

void	dispatch(int select, t_format *f, va_list arg)
{
	t_dispatcher_ptr	arr[8];

	arr[ID] = &print_id;
	arr[U] = &print_u;
	arr[C] = &print_c;
	arr[S] = &print_s;
	arr[PC] = &print_pc;
	arr[H] = &print_x;
	arr[P] = &print_p;
	arr[X_UPPERCASE] = &print_x_uppercase;
	arr[select](f, arg);
}

int	parse(const char *format, va_list arg_ptr)
{
	t_format	*spec;
	int			printed_chars;
	int			type;

	spec = ft_initialize_struct();
	if (format && spec)
	{
		type = get_type(format);
		spec->type = type;
	}
	dispatch(spec->type, spec, arg_ptr);
	printed_chars = spec->printed_chars;
	free(spec);
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	int		printed_chars;
	va_list	arg_ptr;
	int		i;

	printed_chars = 0;
	i = 0;
	va_start(arg_ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(is_correct_spec(&format[i])))
				return (0);
			printed_chars += parse(&format[i], arg_ptr);
			i += percent_len(&format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	va_end(arg_ptr);
	return (printed_chars);
}
