/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:30:11 by flavon            #+#    #+#             */
/*   Updated: 2020/08/13 12:26:02 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline	t_list	initial(t_list list)
{
	list.width = 0;
	list.precision = -1;
	list.minus = 0;
	list.zero = 0;
	list.dot = 0;
	return (list);
}

int						ft_start_printf(char type, t_list list, va_list argptr)
{
	int	len;

	len = 0;
	if (type == 'c' || ft_strchr(type, "spdiuxX%") == 0)
		len = ft_print_char(list, va_arg(argptr, int));
	else if (type == 's')
		len = ft_print_string(list, va_arg(argptr, char *), type);
	else if (type == 'p')
		len = ft_print_pointer(list, va_arg(argptr, unsigned long long));
	else if (type == 'd' || type == 'i')
		len = ft_print_int(list, va_arg(argptr, int));
	else if (type == 'u')
		len = ft_print_unsigned(list, va_arg(argptr, unsigned int));
	else if (type == 'x')
		len = ft_print_hex(list, va_arg(argptr, unsigned int), 0);
	else if (type == 'X')
		len = ft_print_hex(list, va_arg(argptr, unsigned int), 1);
	else
		len = ft_print_percent(list);
	return (len);
}

t_list					ft_parse(const char *format, va_list argptr,
								t_list list)
{
	int index;
	int count;

	index = 0;
	count = ft_check_flag(&format[index]);
	while (count-- != 0)
	{
		if (format[index] == '-' && list.dot == 0)
			list.minus = 1;
		else if (format[index] == '0' && list.dot == 0 && list.width < 1)
			list.zero = 1;
		else if (ft_isdigit(format[index]) && list.dot == 0)
			list.width = (list.width * 10) + (format[index] - '0');
		else if (ft_isdigit(format[index]) && list.dot == 1)
			list.precision = (list.precision * 10) + (format[index] - '0');
		else if (format[index] == '.')
		{
			list.dot = 1;
			list.precision = 0;
		}
		else if (format[index] == '*')
			list = ft_parse_star(argptr, list);
		index++;
	}
	return (list);
}

int						ft_printf(const char *format, ...)
{
	size_t	length;
	size_t	index;
	t_list	list;
	va_list	argptr;

	index = 0;
	length = 0;
	va_start(argptr, format);
	while (format[index] != 0)
	{
		while (format[index] != '%' && format[index] != 0 && length++ != -1)
			write(1, &format[index++], 1);
		if (format[index] == '%')
		{
			list = initial(list);
			list = ft_parse(&format[++index], argptr, list);
			index += ft_check_flag(&format[index]);
			length += (size_t)ft_start_printf(format[index], list, argptr);
		}
		index += (format[index] != 0) ? 1 : 0;
	}
	va_end(argptr);
	return ((int)length);
}
