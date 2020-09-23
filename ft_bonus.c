/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:43:41 by flavon            #+#    #+#             */
/*   Updated: 2020/08/13 12:23:57 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flag(const char *dst)
{
	char	*flags;
	int		index;
	int		count;

	flags = "-0.*123456789";
	index = 0;
	count = 0;
	while (flags[index] != 0)
	{
		if (flags[index] == dst[count])
		{
			index = -1;
			count++;
		}
		index++;
	}
	return (count);
}

t_list	ft_parse_star(va_list ap, t_list list)
{
	if (list.dot == 1)
		list.precision = va_arg(ap, int);
	else if (list.width < 1)
	{
		list.width = va_arg(ap, int);
		if (list.width < 0)
		{
			list.minus = 1;
			list.width *= -1;
		}
	}
	return (list);
}

int		get_plen(unsigned long long n, int precision)
{
	int len;

	len = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		len++;
	}
	return (precision > len ? precision : len);
}

char	*ft_pointer_precision(unsigned long long n, int precision)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = get_plen(n, precision) + 2;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		str[i++] = '0';
	str[1] = 'x';
	str[len] = '\0';
	while (n / 16 != 0)
	{
		str[--len] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	str[--len] = "0123456789abcdef"[n % 16];
	return (str);
}

int		ft_print_width(int width, int argprt_length, int space_or_zero)
{
	int	count;

	count = 0;
	while (width-- - argprt_length > 0)
	{
		if (space_or_zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		count++;
	}
	return (count);
}
