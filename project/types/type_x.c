/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:16:16 by malatini          #+#    #+#             */
/*   Updated: 2023/10/07 17:48:52 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_x_uppercase(t_format *f, va_list arg)
{
	int		n;
	char	*base;

	base = BASE16_UPPERCASE;
	n = va_arg(arg, unsigned int);
	f->printed_chars += ft_putnbr_u_base(f, n, base);

}

void	print_x(t_format *f, va_list arg)
{
	int		n;
	char	*base;

	base = BASE16;
	n = va_arg(arg, unsigned int);
	f->printed_chars += ft_putnbr_u_base(f, n, base);
}
