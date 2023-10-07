/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:34:08 by malatini          #+#    #+#             */
/*   Updated: 2023/10/07 18:35:50 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# define ID					0
# define U					1
# define C					2
# define S					3
# define PC					4
# define H					5
# define P					6
# define X_UPPERCASE		7

# define OX 				"0x"
# define NULLPTR			"0x0"
# define BASE16 			"0123456789abcdef"
# define BASE16_UPPERCASE	"0123456789ABCDEF"
# define INT_MIN_STR		"-2147483648"
# define NULL_STR			"(null)"

# define BASE16LEN			16
# define LEN_OX 			2

typedef struct s_format
{
	int	type;
	int	printed_chars;
}				t_format;

typedef void	(*t_dispatcher_ptr)(t_format *f, va_list arg);

int			ft_strlen(const char *s);
int			ft_putchar(char c);
int			ft_isdigit(int c);
int			putnbr(int nbr);
int			ft_putstr(const char *str);

int			n_size_i(int n);
int			n_size_u(unsigned int n);
int			putnbr_unsigned(unsigned int nbr);
void		ft_putnbr_base16(unsigned long long n, char *b);
int			ft_putnbr_u_base(t_format *f, unsigned int n, char *base);
int			count_nbr_u_base(unsigned int nbr, char *base);

int			is_correct_type(char c);
int			is_correct_spec(const char *s);

int			get_type(const char *format);
t_format	*ft_initialize_struct(void);

int			percent_len(const char *s);
int			count_pointer_length(unsigned long long n, char *b);

void		print_u(t_format *f, va_list arg);
void		print_s(t_format *f, va_list arg);
void		print_id(t_format *f, va_list arg);
void		print_c(t_format *f, va_list arg);
void		print_p(t_format *f, va_list arg);
void		print_x(t_format *f, va_list arg);
void		print_x_uppercase(t_format *f, va_list arg);

int			ft_printf(const char *format, ...);

#endif