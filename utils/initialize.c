/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:58:22 by malatini          #+#    #+#             */
/*   Updated: 2023/10/01 23:05:07 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_type(const char *f)
{
	int	i;

	if (!f)
		return (0);
	i = 0;
	if (f[i] == '%')
		i++;
	while (!(is_correct_type(f[i])) && f[i])
		i++;
	if (f[i] == 'i' || f[i] == 'd')
		return (ID);
	else if (f[i] == 'u')
		return (U);
	else if (f[i] == 'c')
		return (C);
	else if (f[i] == 's')
		return (S);
	else if (f[i] == '%')
		return (PC);
	else if (f[i] == 'x' || f[i] == 'X')
		return (H);
	else if (f[i] == 'p')
		return (P);
	return (0);
}

t_format	*ft_initialize_struct(void)
{
	t_format	*format;

	format = (t_format *)malloc(sizeof(t_format));
	if (!format)
		return (NULL);
	format->type = 0;
	format->printed_chars = 0;
	return (format);
}

int	fill_type(const char *str, t_format *f)
{
	int	type;

	if (!str && !f)
		return (false);
	type = get_type(str);
	f->type = type;
	return (type);
}

void	fill_struct(const char *str, t_format *f)
{
	if (!str && !f)
		return ;
	fill_type(str, f);
}
