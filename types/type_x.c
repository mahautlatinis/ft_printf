/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:16:16 by malatini          #+#    #+#             */
/*   Updated: 2023/10/01 23:04:50 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_x(const char *str, t_format *f, va_list arg)
{
	int		n;
	char	*base;
	char	x;

	x = which_x_type(str);
	if (x == 'x')
		base = BASE16;
	else
		base = BASE16_UPPERCASE;
	n = va_arg(arg, unsigned int);
	f->printed_chars += ft_putnbr_u_base(f, n, base);
}
