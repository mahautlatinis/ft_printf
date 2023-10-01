/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:42:29 by malatini          #+#    #+#             */
/*   Updated: 2023/10/01 23:04:48 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putnbr(int nbr)
{
	int	n;
	int	i;

	i = 0;
	n = nbr;
	if (nbr < 0)
	{
		n = -n;
		ft_putchar('-');
		i++;
	}
	if (n > 9)
		i += putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	i++;
	return (i);
}

int	print_numbers(int n)
{
	int	i;

	i = 0;
	if (n == INT_MIN)
		return (i += ft_putstr(INT_MIN_STR));
	i += putnbr(n);
	return (i);
}

void	print_id(t_format *f, va_list arg)
{
	int	n;
	int	i;

	i = 0;
	n = va_arg(arg, int);
	if (n > 0)
		i += putnbr((unsigned int)n);
	else
		i += print_numbers(n);
	f->printed_chars += i;
}
