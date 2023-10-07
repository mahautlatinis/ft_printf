/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:22:26 by malatini          #+#    #+#             */
/*   Updated: 2023/10/07 18:09:19 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_c(t_format *f, va_list arg)
{
	int	c;

	c = va_arg(arg, int);
	f->printed_chars += ft_putchar(c);
}

int	percent_len(const char *s)
{
	int	i;

	i = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (is_correct_type(s[i]))
			return (i);
		i++;
	}
	return (0);
}

void	print_s(t_format *f, va_list arg)
{
	int		i;
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
	{
		f->printed_chars += ft_putstr(NULL_STR);
		return ;
	}
	i = 0;
	i += ft_putstr(s);
	f->printed_chars += i;
}
