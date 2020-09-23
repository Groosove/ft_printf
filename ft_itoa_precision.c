/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:19:02 by flavon            #+#    #+#             */
/*   Updated: 2020/08/13 12:22:06 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	check_negative(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int			get_slen(int n, int precision)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (precision > len ? precision : len);
}

char		*ft_itoa_precision(int n, int precision)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = get_slen(n, precision);
	if (n < 0)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		str[i++] = '0';
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	while (n / 10 != 0)
	{
		str[--len] = check_negative(n % 10) + '0';
		n /= 10;
	}
	str[--len] = check_negative(n % 10) + '0';
	return (str);
}

char		*ft_itoa_base_precision(unsigned int n, int precision, int base)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	if (base < 2 || base > 16)
		return (NULL);
	len = get_len(n, precision, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		str[i++] = '0';
	str[len] = '\0';
	while (n / base != 0)
	{
		str[--len] = "0123456789abcdef"[n % base];
		n /= base;
	}
	str[--len] = "0123456789abcdef"[n % base];
	return (str);
}

int			get_len(unsigned int n, int precision, int base)
{
	int	len;

	len = 1;
	while (n / base != 0)
	{
		n /= base;
		len++;
	}
	return (precision > len ? precision : len);
}
