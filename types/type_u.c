/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:23:14 by malatini          #+#    #+#             */
/*   Updated: 2023/10/02 16:55:36 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putnbr_unsigned(unsigned int n)
{
	unsigned int	nb;
	int				i;

	nb = n;
	i = 0;
	if (nb > 9)
		i += putnbr_unsigned(nb / 10);
	ft_putchar(nb % 10 + '0');
	i++;
	return (i);
}

int	n_size_u(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return ((int)i);
}

int	ft_putnbr_u_base(t_format *f, unsigned int n, char *b)
{
	long		nb;
	int			temp;
	static int	i;

	nb = n;
	i = 0;
	if (BASE16LEN - 1 < nb)
		ft_putnbr_u_base(f, nb / BASE16LEN, b);
	temp = b[(int)(nb % BASE16LEN)];
	write(1, &temp, 1);
	i++;
	return (i);
}


void	print_u(t_format *f, va_list arg)
{
	unsigned int	n;
	int				i;

	i = 0;
	n = va_arg(arg, unsigned int);
	putnbr_unsigned(n);
	i += n_size_u(n);
	f->printed_chars += i;
}
