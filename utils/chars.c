/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:03:52 by malatini          #+#    #+#             */
/*   Updated: 2023/10/01 11:50:05 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_isdigit(int c)
{
	if (!c)
		return (0);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	found_char(const char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = len_until_end_format(str);
	if (!c && !str)
		return (0);
	while (str[i] && i < len)
	{
		if (str[i] == c && str[i] && i < len)
			return (i);
		i++;
	}
	return (0);
}
