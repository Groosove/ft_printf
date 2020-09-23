/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 11:08:38 by flavon            #+#    #+#             */
/*   Updated: 2020/08/12 14:46:00 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_list
{
    short width;
    short precision;
    short minus;
    short zero;
    short dot;
}               t_list;

t_list	ft_parse_star(va_list ap, t_list list);
int		ft_check_flag(const char *dst);
int		ft_isdigit(int ch);
int		ft_print_width(int width, int extra, int zero);
int		ft_printf(const char *format, ...);
char	ft_strchr(int symbol, char *string);
int		ft_strlen(char *dst);
int		ft_putnstr(char *dst, int count);
char	*ft_strdup(char *dst);
char	*ft_pointer_precision(unsigned long long n, int precision);
int		get_plen(unsigned long long n, int precision);
char	*ft_itoa_precision(int n, int precision);
char	*ft_itoa_base_precision(unsigned int n, int precision, int base);
int		get_len(unsigned int n, int precision, int base);
int		ft_toupper(int c);

// General

int		ft_print_char(t_list list, char ch);
int		ft_print_string(t_list list, char *dst, char type);
int		ft_print_pointer(t_list list, unsigned long long value);
int		ft_print_int(t_list list, int value);
int		ft_print_unsigned(t_list list, unsigned int value);
int		ft_print_hex(t_list list, unsigned int value, int type);
int		ft_print_percent(t_list list);

#endif
