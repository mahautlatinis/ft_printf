/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:41:42 by malatini          #+#    #+#             */
/*   Updated: 2023/10/01 11:32:34 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_p_base(unsigned long long n, char *b)
{
	unsigned long long	nb;
	int					temp;
	int					base_len;

	nb = n;
	base_len = 16;
	if ((unsigned long long)(base_len - 1) < nb)
		ft_putnbr_p_base(nb / base_len, b);
	temp = b[(int)(nb % base_len)];
	write(1, &temp, 1);
}

int	count_p_length(unsigned long long n, char *b)
{
	int	base_len;
	int	i;

	i = 0;
	base_len = 16;
	if ((unsigned long long)(base_len - 1) < n)
		i += count_p_length(n / base_len, b);
	i++;
	return (i);
}

int	r_width_precision_p(t_format *f, unsigned long long p, char c, char *b)
{
	int	i;
	int	w_to_print;

	i = 0;
	if (f->width > 0)
		w_to_print = f->width - count_p_length(p, b);
	else
		w_to_print = -f->width - count_p_length(p, b);
	i += ft_putstr("0x");
	ft_putnbr_p_base(p, b);
	i += print_x_time(c, w_to_print - 2);
	i += count_p_length(p, b);
	return (i);
}

int	zero_pad_width_p(t_format *f, unsigned long long p, char c, char *b)
{
	int	i;
	int	w_to_print;

	i = 0;
	w_to_print = f->width - count_p_length(p, b);
	i += print_x_time(c, w_to_print - 2);
	i += ft_putstr("0x");
	ft_putnbr_p_base(p, b);
	i += count_p_length(p, b);
	return (i);
}
