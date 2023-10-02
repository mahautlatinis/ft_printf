/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:34:08 by malatini          #+#    #+#             */
/*   Updated: 2023/10/01 23:06:05 by mahautlatin      ###   ########.fr       */
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

# define ID 1
# define U 2
# define C 3
# define S 4
# define PC 5
# define H 6
# define P 7
# define LEN_OX 2
# define OX "0x"
# define BASE16 "0123456789abcdef"
# define BASE16_UPPERCASE "0123456789ABCDEF"
# define BASE16LEN 16
# define NULLPTR "0x0"
# define INT_MIN_STR "-2147483648"
# define NULL_STR "(null)"

typedef struct s_format
{
	int	type;
	int	printed_chars;
}				t_format;

int			ft_putchar(char c);
int			ft_isdigit(int c);
int			n_size_i(int n);
int			putnbr(int nbr);
int			is_correct_type(char c);
int			ft_strlen(const char *s);
int			is_correct_spec(const char *s);
int			ft_putstr(const char *str);
char		which_x_type(const char *format);
int			get_type(const char *format);
int			count_nbr_u_base(unsigned int nbr, char *base);
t_format	*ft_initialize_struct(void);
int			fill_type(const char *str, t_format *format);
void		fill_struct(const char *str, t_format *format);
void		print_x(const char *str, t_format *format, va_list arg_ptr);
void		print_u(t_format *f, va_list arg);
int			n_size_u(unsigned int n);
int			putnbr_unsigned(unsigned int nbr);
int			ft_putnbr_u_base(t_format *f, unsigned int n, char *base);
void		print_s(t_format *f, va_list arg);
int			percent_len(const char *s);
int			print_pointer(unsigned long long ptr);
void		print_p(t_format *f, va_list arg);
void		ft_putnbr_base16(unsigned long long n, char *b);
int			count_pointer_length(unsigned long long n, char *b);
void		print_id(t_format *f, va_list arg);
void		print_c(t_format *f, va_list arg);
int			ft_printf(const char *format, ...);

#endif
