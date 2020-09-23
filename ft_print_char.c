/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:13:48 by flavon            #+#    #+#             */
/*   Updated: 2020/08/13 12:22:47 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(t_list list, char ch)
{
	int count;

	count = 0;
	if (list.minus == 1)
	{
		write(1, &ch, 1);
		count = ft_print_width(list.width, 1, 0);
	}
	else
	{
		count = ft_print_width(list.width, 1, 0);
		write(1, &ch, 1);
	}
	return (++count);
}

int		ft_print_string(t_list list, char *dst, char type)
{
	int count;
	int index;

	index = 0;
	count = 0;
	if (dst == 0)
		dst = "(null)";
	if (list.precision == 0 && list.dot == 1 && type == 's')
		dst = "";
	count = ft_strlen(dst);
	if (list.dot && count > list.precision && type == 's' && list.precision > 0)
		count = list.precision;
	if (list.minus == 1)
		return (ft_putnstr(dst, count) + ft_print_width(list.width, count, 0));
	else
		return (ft_print_width(list.width, count, 0) + ft_putnstr(dst, count));
}

int		ft_print_pointer(t_list list, unsigned long long value)
{
	char	*dst;
	int		count;

	if (list.zero && (list.dot || list.minus))
		list.zero = 0;
	if (list.zero)
	{
		list.precision = list.width - 2;
		list.width = 0;
	}
	if (list.dot && list.precision == 0 && value == 0)
		dst = ft_strdup("0x");
	else
		dst = ft_pointer_precision(value, list.precision);
	count = ft_print_string(list, dst, 'p');
	free(dst);
	return (count);
}

int		ft_print_percent(t_list list)
{
	int	len;

	len = 0;
	if (list.minus)
	{
		write(1, "%", 1);
		len += ft_print_width(list.width, 1, 0);
	}
	else
	{
		if (list.zero)
			len += ft_print_width(list.width, 1, 1);
		else
			len += ft_print_width(list.width, 1, 0);
		write(1, "%", 1);
	}
	return (len + 1);
}

int		ft_putnstr(char *dst, int count)
{
	int	index;

	index = 0;
	while (dst[index] && count--)
		write(1, &dst[index++], 1);
	return (index);
}
