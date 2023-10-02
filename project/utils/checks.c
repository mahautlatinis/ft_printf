/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:38:25 by malatini          #+#    #+#             */
/*   Updated: 2023/10/01 23:05:01 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	which_x_type(const char *f)
{
	int	i;

	if (!f)
		return (0);
	i = 0;
	if (f[i] == '%')
		i++;
	while (!(is_correct_type(f[i])) && f[i])
		i++;
	if (f[i] == 'x')
		return ('x');
	else if (f[i] == 'X')
		return ('X');
	return (0);
}

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
