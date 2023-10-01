/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:38:25 by malatini          #+#    #+#             */
/*   Updated: 2023/10/01 11:51:23 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	is_correct_type(char c)
{
	if (!c)
		return (0);
	if (c == 'i' || c == 'd' || c == 'u' || c == 's' || c == 'c'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}



int	is_correct_spec(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '%')
		i++;
	while (s[i])
	{
		if (is_correct_type(s[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
char	c_padding_to_print(t_format *format)
{
	char	to_print;

	to_print = ' ';
	if (format->flags.zero_pad == 1)
		to_print = '0';
	return (to_print);
}
*/

int	ft_putnbr_i(int nbr)
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
		i += ft_putnbr_i(n / 10);
	ft_putchar(n % 10 + '0');
	i++;
	return (i);
}

int	n_size_i(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
