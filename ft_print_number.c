/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:44:29 by flavon            #+#    #+#             */
/*   Updated: 2020/08/12 14:47:58 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_list	define_flags(t_list list, int negative)
{
	if (((list.dot && list.precision >= 0) || list.width < 0 || list.minus)
	&& list.zero)
		list.zero = 0;
	if (list.zero)
	{
		if (list.width > 0)
			list.precision = list.width;
		if (negative)
			list.precision--;
		list.width = 0;
	}
	return (list);
}

int				ft_print_int(t_list list, int value)
{
	int		count;
	char	*dst;

	list = define_flags(list, value < 0);
	if (list.dot && (value == 0) && (list.precision == 0))
		dst = ft_strdup("");
	else
		dst = ft_itoa_precision(value, list.precision);
	count = ft_print_string(list, dst, 'd');
	free(dst);
	return (count);
}

int				ft_print_unsigned(t_list flags, unsigned int value)
{
	int		len;
	char	*num_str;

	flags = define_flags(flags, 0);
	if (flags.dot && (value == 0) && (flags.precision == 0))
		num_str = ft_strdup("");
	else
		num_str = ft_itoa_base_precision(value, flags.precision, 10);
	len = ft_print_string(flags, num_str, 'u');
	free(num_str);
	return (len);
}

int				ft_print_hex(t_list flags, unsigned int value, int type)
{
	int		len;
	char	*num_str;
	int		i;

	flags = define_flags(flags, 0);
	if (flags.dot && (value == 0) && (flags.precision == 0))
		num_str = ft_strdup("");
	else
		num_str = ft_itoa_base_precision(value, flags.precision, 16);
	i = 0;
	if (type == 1)
		while (num_str[i])
		{
			num_str[i] = ft_toupper(num_str[i]);
			i++;
		}
	len = ft_print_string(flags, num_str, 'x');
	free(num_str);
	return (len);
}
