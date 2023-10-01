/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:20:56 by malatini          #+#    #+#             */
/*   Updated: 2023/10/01 22:43:16 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	count_nbr_u_base(unsigned int nbr, char *base)
{
	long		nb;
	int			base_len;
	static int	i;

	nb = nbr;
	base_len = 16;
	i = 0;
	if (base_len - 1 < nb)
		count_nbr_u_base(nb / base_len, base);
	i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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
