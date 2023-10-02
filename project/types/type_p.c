/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:47:41 by malatini          #+#    #+#             */
/*   Updated: 2023/10/01 23:05:54 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base16(unsigned long long n, char *b)
{
	unsigned long long	nb;
	int					temp;

	nb = n;
	if ((unsigned long long)(BASE16LEN- 1) < nb)
		ft_putnbr_base16(nb / BASE16LEN, b);
	temp = b[(int)(nb % BASE16LEN)];
	write(1, &temp, 1);
}

int	count_pointer_length(unsigned long long n, char *b)
{
	int	i;

	i = 0;
	if ((unsigned long long)(BASE16LEN - 1) < n)
		i += count_pointer_length(n / BASE16LEN, b);
	i++;
	return (i);
}

int	print_pointer(unsigned long long p)
{
	ft_putstr(OX);
	ft_putnbr_base16(p, BASE16);
	return (count_pointer_length(p, BASE16) + LEN_OX);
}

void	print_p(t_format *f, va_list arg)
{
	unsigned long long	ptr;
	int					i;

	i = 0;
	ptr = va_arg(arg, unsigned long long);
	if (!ptr)
		i += ft_putstr(NULLPTR);
	else
		i += print_pointer(ptr);
	f->printed_chars += i;
}
